ACTIVE = @


BUILD_SYSC::
-include /home/ubuntu1604/nvdla_proj/hw/outdir/nv_small/verif/testbench/trace_player/csrc/sysc/info.sysc.make.t

-include /home/ubuntu1604/nvdla_proj/hw/outdir/nv_small/verif/testbench/trace_player/csrc/sysc/info.sysc.make.shared

-include /home/ubuntu1604/nvdla_proj/hw/outdir/nv_small/verif/testbench/trace_player/csrc/sysc/modellist

-include /home/ubuntu1604/nvdla_proj/hw/outdir/nv_small/verif/testbench/trace_player/csrc/sysc/stublist

#FORCE TARGET
FORCE:
SYSC_FILES += $(addprefix /home/ubuntu1604/nvdla_proj/hw/outdir/nv_small/verif/testbench/trace_player/csrc/sysc/,$(MODELS))

SYSC_STUBS += $(addprefix /home/ubuntu1604/nvdla_proj/hw/outdir/nv_small/verif/testbench/trace_player/csrc/sysc/,$(STUBLIB))
SYSC_STUB_LIB = $(addprefix /home/ubuntu1604/nvdla_proj/hw/outdir/nv_small/verif/testbench/trace_player/csrc/sysc/,$(STUBLIB))

SYSC_OBJS := $(SYSC_OBJS) $(addsuffix .o,$(SYSC_FILES)) $(SYSC_STUBS)
sysc_globals_cpp = /home/ubuntu1604/nvdla_proj/hw/outdir/nv_small/verif/testbench/trace_player/csrc/sysc/sysc_globals.cpp
sysc_globals_o = /home/ubuntu1604/nvdla_proj/hw/outdir/nv_small/verif/testbench/trace_player/csrc/sysc/sysc_globals.o
$(sysc_globals_o):	$(sysc_globals_cpp)
	@/usr/bin/g++ -o $@ -c $^  -m64 -fPIC   -pipe -DVCSMX -DUVM_DPI_DO_TYPE_CHECK -I/home/ubuntu1604/nvdla_proj/hw/cmod/include -I/home/ubuntu1604/nvdla_proj/hw/cmod/include/nvdla_ness_header -I/home/ubuntu1604/nvdla_proj/hw/outdir/nv_small/spec/defs -O -I/home/ubuntu1604/synopsys/vcs_2019.06-SP2/vcs/P-2019.06-SP2-12/include  -I/home/ubuntu1604/nvdla_proj/hw/cmod/include -I/home/ubuntu1604/nvdla_proj/hw/cmod/include/nvdla_ness_header -I/home/ubuntu1604/nvdla_proj/hw/outdir/nv_small/spec/defs 
$(SYSC_STUB_LIB):
	$(MAKE) -C /home/ubuntu1604/nvdla_proj/hw/outdir/nv_small/verif/testbench/trace_player/csrc/sysc -f Makefile_shared stubs

systemc_stubs_c = /home/ubuntu1604/nvdla_proj/hw/outdir/nv_small/verif/testbench/trace_player/csrc/sysc/systemc_stub.c
systemc_stubs_o = /home/ubuntu1604/nvdla_proj/hw/outdir/nv_small/verif/testbench/trace_player/csrc/sysc/systemc_stub.o
$(systemc_stubs_o):	$(systemc_stubs_c)
	@$(VCS_CC)  -o $@ -c $^  -m64 -fPIC 
simv_c = /home/ubuntu1604/nvdla_proj/hw/outdir/nv_small/verif/testbench/trace_player/csrc/sysc/simv/simv.c
simv_o = /home/ubuntu1604/nvdla_proj/hw/outdir/nv_small/verif/testbench/trace_player/csrc/sysc/simv/simv.o
$(simv_o):	$(simv_c)
	@$(VCS_CC) -o $@ -c -I$(VCS_HOME)/include -I/home/ubuntu1604/synopsys/vcs_2019.06-SP2/vcs/P-2019.06-SP2-12/linux64/lib $^  -m64 -fPIC  
