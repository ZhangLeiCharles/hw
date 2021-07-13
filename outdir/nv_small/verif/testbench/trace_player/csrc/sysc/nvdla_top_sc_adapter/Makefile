# ------------------------------------------------------------------
# SYNOPSYS CONFIDENTIAL                                             
#                                                                   
# This is an unpublished, proprietary work of Synopsys, Inc., and   
# is fully protected under copyright and trade secret laws. You may 
# not view, use, disclose, copy, or distribute this file or any     
# information contained herein except pursuant to a valid written   
# license from Synopsys.                                            
# ------------------------------------------------------------------
MODULE = nvdla_top_sc_adapter

V = @
CXX = /usr/bin/g++
CXXFLAGS =  -D__STDC_FORMAT_MACROS -DNVDLA_REFERENCE_MODEL_ENABLE -DUVMC_MAX_WORDS=2048 -DVCS -I/home/ubuntu1604/nvdla_proj/hw/third_party_tools/uvmc-2.3.0/src/connect/sc -I/home/ubuntu1604/synopsys/vcs_2019.06-SP2/vcs/P-2019.06-SP2-12/include/systemc231 -I/home/ubuntu1604/nvdla_proj/hw/outdir/nv_small/verif/vip/reference_model/nvdla_cmod_wrap/release/include -I/home/ubuntu1604/nvdla_proj/hw/outdir/nv_small/verif/vip/reference_model/nvdla_scsv/sc -I/home/ubuntu1604/nvdla_proj/hw/outdir/nv_small/verif/vip/reference_model/nvdla_top_scsv_adapter/sc -DVCSSYSTEMC=1 -MMD -m64 -fPIC -DVCSSYSTEMC=1

SC_INCLUDES = \
	-I$(VCS_HOME)/include/systemc231 \
	-I/home/ubuntu1604/nvdla_proj/hw/outdir/nv_small/verif/testbench/trace_player

C_INCLUDES = \
	-I/home/ubuntu1604/nvdla_proj/hw/outdir/nv_small/verif/vip/reference_model/nvdla_top_scsv_adapter/sc \
	-I/home/ubuntu1604/nvdla_proj/hw/outdir/nv_small/verif/testbench/trace_player/csrc/sysc/include \
	-I$(VCS_HOME)/include/cosim/bf \
	-I/home/ubuntu1604/synopsys/vcs_2019.06-SP2/vcs/P-2019.06-SP2-12/include/systemc231/include/tlm \
	-I/home/ubuntu1604/synopsys/vcs_2019.06-SP2/vcs/P-2019.06-SP2-12/etc/systemc/tlm/tli \
	-I/home/ubuntu1604/synopsys/vcs_2019.06-SP2/vcs/P-2019.06-SP2-12/include/systemc231/examples/tlm/common/include \
	-I$(VCS_HOME)/include \
	-I$(VCS_HOME)/lib \
	-I$(VCS_HOME)/vhdl-src/snps/synopsys/include \
	-I$(VCS_HOME)/include/cosim/bf

INCLUDES = $(SC_INCLUDES) $(C_INCLUDES)

OBJS = nvdla_top_sc_adapter.o nvdla_top_sc_adapter_vcs.o nvdla_top_sc_adapter_stubs.o 
all:	$(OBJS)

clean:
	rm -f $(OBJS)
	rm -f $(subst .o,.d,$(OBJS))

src_name_cpp = /home/ubuntu1604/nvdla_proj/hw/outdir/nv_small/verif/vip/reference_model/nvdla_top_scsv_adapter/sc/nvdla_top_sc_adapter.cpp
nvdla_top_sc_adapter.o:	$(src_name_cpp)
	@echo "Compiling /home/ubuntu1604/nvdla_proj/hw/outdir/nv_small/verif/vip/reference_model/nvdla_top_scsv_adapter/sc/nvdla_top_sc_adapter.cpp"
	$(V) $(CXX) -c /home/ubuntu1604/nvdla_proj/hw/outdir/nv_small/verif/vip/reference_model/nvdla_top_scsv_adapter/sc/nvdla_top_sc_adapter.cpp -o $@ $(INCLUDES) $(CXXFLAGS)
	@$(MAKE) -C /home/ubuntu1604/nvdla_proj/hw/outdir/nv_small/verif/testbench/trace_player/csrc/sysc -f Makefile_shared clean

nvdla_top_sc_adapter_vcs.o:	nvdla_top_sc_adapter_vcs.cpp
	@echo "Compiling nvdla_top_sc_adapter_vcs.cpp"
	$(V) $(CXX) -c $< -o $@ $(INCLUDES) $(CXXFLAGS) 
	@$(MAKE) -C /home/ubuntu1604/nvdla_proj/hw/outdir/nv_small/verif/testbench/trace_player/csrc/sysc -f Makefile_shared clean

nvdla_top_sc_adapter_stubs.o:	nvdla_top_sc_adapter_stubs.c
	$(V) $(CXX) -c $< -o $@ $(INCLUDES) $(CXXFLAGS) 
	@$(MAKE) -C /home/ubuntu1604/nvdla_proj/hw/outdir/nv_small/verif/testbench/trace_player/csrc/sysc -f Makefile_shared clean

-include nvdla_top_sc_adapter_vcs.d
-include nvdla_top_sc_adapter.d

