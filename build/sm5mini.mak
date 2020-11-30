APP_ROOT = $(TOP)/SM5MINI
APP = $(APP_ROOT)/build/SM5MINI_APP.bin
LOADER = $(APP_ROOT)/build/SM5MINI_LOADER.bin
UPGRADER_ROOT = $(TOP)/upgrader
UPGRADER = $(UPGRADER_ROOT)/upgrader.bin
APP_OFFSET = 0x8000
UPGRADER_OFFSET = 0xf000
TOOLS = $(TOP)/tools
PACK_ROOT = $(TOOLS)/pack
PACK = $(PACK_ROOT)/pack
UTILROOT = $(TOOLS)/util
UPGRADE = $(UTILROOT)/mcu-util

$(TARGET): FORCE
	$(Q)rm -rf $(OUTPUT)
	$(Q)mkdir -p $(OUTPUT)
	$(Q)cd $(APP_ROOT) && make clean && make
	$(Q)cd $(UPGRADER_ROOT) && make distclean && make
	$(Q)cd $(PACK_ROOT) && make distclean && make
	$(Q)cd $(UTILROOT) && make clean && make && cd - && cp $(UPGRADE) $(OUTPUT)/mcu-util-amd64
	$(Q)cd $(UTILROOT) && make clean && make CROSS_COMPILE=$(AARCH64_CROSS_COMPILE) && cd - && cp $(UPGRADE) $(OUTPUT)/mcu-util-aarch64
	$(Q)$(PACK) $(LOADER) $(APP) $(APP_OFFSET) $(UPGRADER) $(UPGRADER_OFFSET) $@ $(E) && mv $@ $(OUTPUT)/

clean: FORCE
	$(Q)cd $(APP_ROOT) && make clean
	$(Q)cd $(UPGRADER_ROOT) && make distclean
	$(Q)cd $(PACK_ROOT) && make distclean
	$(Q)cd $(UTILROOT) && make clean
	$(Q)cd $(UTILROOT) && make clean

distclean: clean
	$(Q)rm -rf $(OUTPUT)

burn: FORCE
	st-flash write $(OUTPUT)/$(TARGET) 0x08000000