//   Ordt 171103.01 autogenerated file 
//   Input: NVDLA_MCIF.rdl
//   Parms: opendla.parms
//   Date: Tue Jul 13 11:42:07 SGT 2021
//

import uvm_pkg::*;
import ordt_uvm_reg_pkg::*;

// CFG_RD_WEIGHT_0
class reg_addrmap_NVDLA_NVDLA_MCIF_CFG_RD_WEIGHT_0 extends uvm_reg_rdl;
  string m_rdl_tag;
  rand uvm_reg_field_rdl RD_WEIGHT_BDMA;
  rand uvm_reg_field_rdl RD_WEIGHT_SDP;
  rand uvm_reg_field_rdl RD_WEIGHT_PDP;
  rand uvm_reg_field_rdl RD_WEIGHT_CDP;
  
  function new(string name = "reg_addrmap_NVDLA_NVDLA_MCIF_CFG_RD_WEIGHT_0");
    super.new(name, 32, UVM_NO_COVERAGE);
  endfunction: new
  
  virtual function void build();
    string rdl_reg_name;
    this.RD_WEIGHT_BDMA = new("RD_WEIGHT_BDMA");
    this.RD_WEIGHT_BDMA.set_rdl_access_info(1, 1, 1, 0, 0, 0);
    this.RD_WEIGHT_BDMA.configure(this, 8, 0, "RW", 0, 8'h1, 1, 1, 0);
    this.RD_WEIGHT_BDMA.add_def_property("spec_access", "rw");
    this.RD_WEIGHT_BDMA.add_def_property("spec_sw_default", "0x0");
    this.RD_WEIGHT_BDMA.add_def_property("sw_default_mask", "0x0");
    this.RD_WEIGHT_BDMA.add_def_property("reset_mask", "0xff");
    this.RD_WEIGHT_SDP = new("RD_WEIGHT_SDP");
    this.RD_WEIGHT_SDP.set_rdl_access_info(1, 1, 1, 0, 0, 0);
    this.RD_WEIGHT_SDP.configure(this, 8, 8, "RW", 0, 8'h1, 1, 1, 0);
    this.RD_WEIGHT_SDP.add_def_property("spec_access", "rw");
    this.RD_WEIGHT_SDP.add_def_property("spec_sw_default", "0x0");
    this.RD_WEIGHT_SDP.add_def_property("sw_default_mask", "0x0");
    this.RD_WEIGHT_SDP.add_def_property("reset_mask", "0xff");
    this.RD_WEIGHT_PDP = new("RD_WEIGHT_PDP");
    this.RD_WEIGHT_PDP.set_rdl_access_info(1, 1, 1, 0, 0, 0);
    this.RD_WEIGHT_PDP.configure(this, 8, 16, "RW", 0, 8'h1, 1, 1, 0);
    this.RD_WEIGHT_PDP.add_def_property("spec_access", "rw");
    this.RD_WEIGHT_PDP.add_def_property("spec_sw_default", "0x0");
    this.RD_WEIGHT_PDP.add_def_property("sw_default_mask", "0x0");
    this.RD_WEIGHT_PDP.add_def_property("reset_mask", "0xff");
    this.RD_WEIGHT_CDP = new("RD_WEIGHT_CDP");
    this.RD_WEIGHT_CDP.set_rdl_access_info(1, 1, 1, 0, 0, 0);
    this.RD_WEIGHT_CDP.configure(this, 8, 24, "RW", 0, 8'h1, 1, 1, 0);
    this.RD_WEIGHT_CDP.add_def_property("spec_access", "rw");
    this.RD_WEIGHT_CDP.add_def_property("spec_sw_default", "0x0");
    this.RD_WEIGHT_CDP.add_def_property("sw_default_mask", "0x0");
    this.RD_WEIGHT_CDP.add_def_property("reset_mask", "0xff");
    
    rdl_reg_name = get_rdl_name("rg_");
    add_hdl_path_slice({rdl_reg_name, "RD_WEIGHT_BDMA"}, 0, 8);
    add_hdl_path_slice({rdl_reg_name, "RD_WEIGHT_SDP"}, 8, 8);
    add_hdl_path_slice({rdl_reg_name, "RD_WEIGHT_PDP"}, 16, 8);
    add_hdl_path_slice({rdl_reg_name, "RD_WEIGHT_CDP"}, 24, 8);
  endfunction: build
  
endclass : reg_addrmap_NVDLA_NVDLA_MCIF_CFG_RD_WEIGHT_0

// CFG_RD_WEIGHT_1
class reg_addrmap_NVDLA_NVDLA_MCIF_CFG_RD_WEIGHT_1 extends uvm_reg_rdl;
  string m_rdl_tag;
  rand uvm_reg_field_rdl RD_WEIGHT_SDP_B;
  rand uvm_reg_field_rdl RD_WEIGHT_SDP_N;
  rand uvm_reg_field_rdl RD_WEIGHT_SDP_E;
  rand uvm_reg_field_rdl RD_WEIGHT_CDMA_DAT;
  
  function new(string name = "reg_addrmap_NVDLA_NVDLA_MCIF_CFG_RD_WEIGHT_1");
    super.new(name, 32, UVM_NO_COVERAGE);
  endfunction: new
  
  virtual function void build();
    string rdl_reg_name;
    this.RD_WEIGHT_SDP_B = new("RD_WEIGHT_SDP_B");
    this.RD_WEIGHT_SDP_B.set_rdl_access_info(1, 1, 1, 0, 0, 0);
    this.RD_WEIGHT_SDP_B.configure(this, 8, 0, "RW", 0, 8'h1, 1, 1, 0);
    this.RD_WEIGHT_SDP_B.add_def_property("spec_access", "rw");
    this.RD_WEIGHT_SDP_B.add_def_property("spec_sw_default", "0x0");
    this.RD_WEIGHT_SDP_B.add_def_property("sw_default_mask", "0x0");
    this.RD_WEIGHT_SDP_B.add_def_property("reset_mask", "0xff");
    this.RD_WEIGHT_SDP_N = new("RD_WEIGHT_SDP_N");
    this.RD_WEIGHT_SDP_N.set_rdl_access_info(1, 1, 1, 0, 0, 0);
    this.RD_WEIGHT_SDP_N.configure(this, 8, 8, "RW", 0, 8'h1, 1, 1, 0);
    this.RD_WEIGHT_SDP_N.add_def_property("spec_access", "rw");
    this.RD_WEIGHT_SDP_N.add_def_property("spec_sw_default", "0x0");
    this.RD_WEIGHT_SDP_N.add_def_property("sw_default_mask", "0x0");
    this.RD_WEIGHT_SDP_N.add_def_property("reset_mask", "0xff");
    this.RD_WEIGHT_SDP_E = new("RD_WEIGHT_SDP_E");
    this.RD_WEIGHT_SDP_E.set_rdl_access_info(1, 1, 1, 0, 0, 0);
    this.RD_WEIGHT_SDP_E.configure(this, 8, 16, "RW", 0, 8'h1, 1, 1, 0);
    this.RD_WEIGHT_SDP_E.add_def_property("spec_access", "rw");
    this.RD_WEIGHT_SDP_E.add_def_property("spec_sw_default", "0x0");
    this.RD_WEIGHT_SDP_E.add_def_property("sw_default_mask", "0x0");
    this.RD_WEIGHT_SDP_E.add_def_property("reset_mask", "0xff");
    this.RD_WEIGHT_CDMA_DAT = new("RD_WEIGHT_CDMA_DAT");
    this.RD_WEIGHT_CDMA_DAT.set_rdl_access_info(1, 1, 1, 0, 0, 0);
    this.RD_WEIGHT_CDMA_DAT.configure(this, 8, 24, "RW", 0, 8'h1, 1, 1, 0);
    this.RD_WEIGHT_CDMA_DAT.add_def_property("spec_access", "rw");
    this.RD_WEIGHT_CDMA_DAT.add_def_property("spec_sw_default", "0x0");
    this.RD_WEIGHT_CDMA_DAT.add_def_property("sw_default_mask", "0x0");
    this.RD_WEIGHT_CDMA_DAT.add_def_property("reset_mask", "0xff");
    
    rdl_reg_name = get_rdl_name("rg_");
    add_hdl_path_slice({rdl_reg_name, "RD_WEIGHT_SDP_B"}, 0, 8);
    add_hdl_path_slice({rdl_reg_name, "RD_WEIGHT_SDP_N"}, 8, 8);
    add_hdl_path_slice({rdl_reg_name, "RD_WEIGHT_SDP_E"}, 16, 8);
    add_hdl_path_slice({rdl_reg_name, "RD_WEIGHT_CDMA_DAT"}, 24, 8);
  endfunction: build
  
endclass : reg_addrmap_NVDLA_NVDLA_MCIF_CFG_RD_WEIGHT_1

// CFG_RD_WEIGHT_2
class reg_addrmap_NVDLA_NVDLA_MCIF_CFG_RD_WEIGHT_2 extends uvm_reg_rdl;
  string m_rdl_tag;
  rand uvm_reg_field_rdl RD_WEIGHT_CDMA_WT;
  rand uvm_reg_field_rdl RD_WEIGHT_RBK;
  rand uvm_reg_field_rdl RD_WEIGHT_RSV_1;
  rand uvm_reg_field_rdl RD_WEIGHT_RSV_0;
  
  function new(string name = "reg_addrmap_NVDLA_NVDLA_MCIF_CFG_RD_WEIGHT_2");
    super.new(name, 32, UVM_NO_COVERAGE);
  endfunction: new
  
  virtual function void build();
    string rdl_reg_name;
    this.RD_WEIGHT_CDMA_WT = new("RD_WEIGHT_CDMA_WT");
    this.RD_WEIGHT_CDMA_WT.set_rdl_access_info(1, 1, 1, 0, 0, 0);
    this.RD_WEIGHT_CDMA_WT.configure(this, 8, 0, "RW", 0, 8'h1, 1, 1, 0);
    this.RD_WEIGHT_CDMA_WT.add_def_property("spec_access", "rw");
    this.RD_WEIGHT_CDMA_WT.add_def_property("spec_sw_default", "0x0");
    this.RD_WEIGHT_CDMA_WT.add_def_property("sw_default_mask", "0x0");
    this.RD_WEIGHT_CDMA_WT.add_def_property("reset_mask", "0xff");
    this.RD_WEIGHT_RBK = new("RD_WEIGHT_RBK");
    this.RD_WEIGHT_RBK.set_rdl_access_info(1, 1, 1, 0, 0, 0);
    this.RD_WEIGHT_RBK.configure(this, 8, 8, "RW", 0, 8'h1, 1, 1, 0);
    this.RD_WEIGHT_RBK.add_def_property("spec_access", "rw");
    this.RD_WEIGHT_RBK.add_def_property("spec_sw_default", "0x0");
    this.RD_WEIGHT_RBK.add_def_property("sw_default_mask", "0x0");
    this.RD_WEIGHT_RBK.add_def_property("reset_mask", "0xff");
    this.RD_WEIGHT_RSV_1 = new("RD_WEIGHT_RSV_1");
    this.RD_WEIGHT_RSV_1.set_rdl_access_info(1, 1, 1, 0, 0, 0);
    this.RD_WEIGHT_RSV_1.configure(this, 8, 16, "RW", 0, 8'h1, 1, 1, 0);
    this.RD_WEIGHT_RSV_1.add_def_property("spec_access", "rw");
    this.RD_WEIGHT_RSV_1.add_def_property("spec_sw_default", "0x0");
    this.RD_WEIGHT_RSV_1.add_def_property("sw_default_mask", "0x0");
    this.RD_WEIGHT_RSV_1.add_def_property("reset_mask", "0xff");
    this.RD_WEIGHT_RSV_0 = new("RD_WEIGHT_RSV_0");
    this.RD_WEIGHT_RSV_0.set_rdl_access_info(1, 1, 1, 0, 0, 0);
    this.RD_WEIGHT_RSV_0.configure(this, 8, 24, "RW", 0, 8'h1, 1, 1, 0);
    this.RD_WEIGHT_RSV_0.add_def_property("spec_access", "rw");
    this.RD_WEIGHT_RSV_0.add_def_property("spec_sw_default", "0x0");
    this.RD_WEIGHT_RSV_0.add_def_property("sw_default_mask", "0x0");
    this.RD_WEIGHT_RSV_0.add_def_property("reset_mask", "0xff");
    
    rdl_reg_name = get_rdl_name("rg_");
    add_hdl_path_slice({rdl_reg_name, "RD_WEIGHT_CDMA_WT"}, 0, 8);
    add_hdl_path_slice({rdl_reg_name, "RD_WEIGHT_RBK"}, 8, 8);
    add_hdl_path_slice({rdl_reg_name, "RD_WEIGHT_RSV_1"}, 16, 8);
    add_hdl_path_slice({rdl_reg_name, "RD_WEIGHT_RSV_0"}, 24, 8);
  endfunction: build
  
endclass : reg_addrmap_NVDLA_NVDLA_MCIF_CFG_RD_WEIGHT_2

// CFG_WR_WEIGHT_0
class reg_addrmap_NVDLA_NVDLA_MCIF_CFG_WR_WEIGHT_0 extends uvm_reg_rdl;
  string m_rdl_tag;
  rand uvm_reg_field_rdl WR_WEIGHT_BDMA;
  rand uvm_reg_field_rdl WR_WEIGHT_SDP;
  rand uvm_reg_field_rdl WR_WEIGHT_PDP;
  rand uvm_reg_field_rdl WR_WEIGHT_CDP;
  
  function new(string name = "reg_addrmap_NVDLA_NVDLA_MCIF_CFG_WR_WEIGHT_0");
    super.new(name, 32, UVM_NO_COVERAGE);
  endfunction: new
  
  virtual function void build();
    string rdl_reg_name;
    this.WR_WEIGHT_BDMA = new("WR_WEIGHT_BDMA");
    this.WR_WEIGHT_BDMA.set_rdl_access_info(1, 1, 1, 0, 0, 0);
    this.WR_WEIGHT_BDMA.configure(this, 8, 0, "RW", 0, 8'h1, 1, 1, 0);
    this.WR_WEIGHT_BDMA.add_def_property("spec_access", "rw");
    this.WR_WEIGHT_BDMA.add_def_property("spec_sw_default", "0x0");
    this.WR_WEIGHT_BDMA.add_def_property("sw_default_mask", "0x0");
    this.WR_WEIGHT_BDMA.add_def_property("reset_mask", "0xff");
    this.WR_WEIGHT_SDP = new("WR_WEIGHT_SDP");
    this.WR_WEIGHT_SDP.set_rdl_access_info(1, 1, 1, 0, 0, 0);
    this.WR_WEIGHT_SDP.configure(this, 8, 8, "RW", 0, 8'h1, 1, 1, 0);
    this.WR_WEIGHT_SDP.add_def_property("spec_access", "rw");
    this.WR_WEIGHT_SDP.add_def_property("spec_sw_default", "0x0");
    this.WR_WEIGHT_SDP.add_def_property("sw_default_mask", "0x0");
    this.WR_WEIGHT_SDP.add_def_property("reset_mask", "0xff");
    this.WR_WEIGHT_PDP = new("WR_WEIGHT_PDP");
    this.WR_WEIGHT_PDP.set_rdl_access_info(1, 1, 1, 0, 0, 0);
    this.WR_WEIGHT_PDP.configure(this, 8, 16, "RW", 0, 8'h1, 1, 1, 0);
    this.WR_WEIGHT_PDP.add_def_property("spec_access", "rw");
    this.WR_WEIGHT_PDP.add_def_property("spec_sw_default", "0x0");
    this.WR_WEIGHT_PDP.add_def_property("sw_default_mask", "0x0");
    this.WR_WEIGHT_PDP.add_def_property("reset_mask", "0xff");
    this.WR_WEIGHT_CDP = new("WR_WEIGHT_CDP");
    this.WR_WEIGHT_CDP.set_rdl_access_info(1, 1, 1, 0, 0, 0);
    this.WR_WEIGHT_CDP.configure(this, 8, 24, "RW", 0, 8'h1, 1, 1, 0);
    this.WR_WEIGHT_CDP.add_def_property("spec_access", "rw");
    this.WR_WEIGHT_CDP.add_def_property("spec_sw_default", "0x0");
    this.WR_WEIGHT_CDP.add_def_property("sw_default_mask", "0x0");
    this.WR_WEIGHT_CDP.add_def_property("reset_mask", "0xff");
    
    rdl_reg_name = get_rdl_name("rg_");
    add_hdl_path_slice({rdl_reg_name, "WR_WEIGHT_BDMA"}, 0, 8);
    add_hdl_path_slice({rdl_reg_name, "WR_WEIGHT_SDP"}, 8, 8);
    add_hdl_path_slice({rdl_reg_name, "WR_WEIGHT_PDP"}, 16, 8);
    add_hdl_path_slice({rdl_reg_name, "WR_WEIGHT_CDP"}, 24, 8);
  endfunction: build
  
endclass : reg_addrmap_NVDLA_NVDLA_MCIF_CFG_WR_WEIGHT_0

// CFG_WR_WEIGHT_1
class reg_addrmap_NVDLA_NVDLA_MCIF_CFG_WR_WEIGHT_1 extends uvm_reg_rdl;
  string m_rdl_tag;
  rand uvm_reg_field_rdl WR_WEIGHT_RBK;
  rand uvm_reg_field_rdl WR_WEIGHT_RSV_2;
  rand uvm_reg_field_rdl WR_WEIGHT_RSV_1;
  rand uvm_reg_field_rdl WR_WEIGHT_RSV_0;
  
  function new(string name = "reg_addrmap_NVDLA_NVDLA_MCIF_CFG_WR_WEIGHT_1");
    super.new(name, 32, UVM_NO_COVERAGE);
  endfunction: new
  
  virtual function void build();
    string rdl_reg_name;
    this.WR_WEIGHT_RBK = new("WR_WEIGHT_RBK");
    this.WR_WEIGHT_RBK.set_rdl_access_info(1, 1, 1, 0, 0, 0);
    this.WR_WEIGHT_RBK.configure(this, 8, 0, "RW", 0, 8'h1, 1, 1, 0);
    this.WR_WEIGHT_RBK.add_def_property("spec_access", "rw");
    this.WR_WEIGHT_RBK.add_def_property("spec_sw_default", "0x0");
    this.WR_WEIGHT_RBK.add_def_property("sw_default_mask", "0x0");
    this.WR_WEIGHT_RBK.add_def_property("reset_mask", "0xff");
    this.WR_WEIGHT_RSV_2 = new("WR_WEIGHT_RSV_2");
    this.WR_WEIGHT_RSV_2.set_rdl_access_info(1, 1, 1, 0, 0, 0);
    this.WR_WEIGHT_RSV_2.configure(this, 8, 8, "RW", 0, 8'h1, 1, 1, 0);
    this.WR_WEIGHT_RSV_2.add_def_property("spec_access", "rw");
    this.WR_WEIGHT_RSV_2.add_def_property("spec_sw_default", "0x0");
    this.WR_WEIGHT_RSV_2.add_def_property("sw_default_mask", "0x0");
    this.WR_WEIGHT_RSV_2.add_def_property("reset_mask", "0xff");
    this.WR_WEIGHT_RSV_1 = new("WR_WEIGHT_RSV_1");
    this.WR_WEIGHT_RSV_1.set_rdl_access_info(1, 1, 1, 0, 0, 0);
    this.WR_WEIGHT_RSV_1.configure(this, 8, 16, "RW", 0, 8'h1, 1, 1, 0);
    this.WR_WEIGHT_RSV_1.add_def_property("spec_access", "rw");
    this.WR_WEIGHT_RSV_1.add_def_property("spec_sw_default", "0x0");
    this.WR_WEIGHT_RSV_1.add_def_property("sw_default_mask", "0x0");
    this.WR_WEIGHT_RSV_1.add_def_property("reset_mask", "0xff");
    this.WR_WEIGHT_RSV_0 = new("WR_WEIGHT_RSV_0");
    this.WR_WEIGHT_RSV_0.set_rdl_access_info(1, 1, 1, 0, 0, 0);
    this.WR_WEIGHT_RSV_0.configure(this, 8, 24, "RW", 0, 8'h1, 1, 1, 0);
    this.WR_WEIGHT_RSV_0.add_def_property("spec_access", "rw");
    this.WR_WEIGHT_RSV_0.add_def_property("spec_sw_default", "0x0");
    this.WR_WEIGHT_RSV_0.add_def_property("sw_default_mask", "0x0");
    this.WR_WEIGHT_RSV_0.add_def_property("reset_mask", "0xff");
    
    rdl_reg_name = get_rdl_name("rg_");
    add_hdl_path_slice({rdl_reg_name, "WR_WEIGHT_RBK"}, 0, 8);
    add_hdl_path_slice({rdl_reg_name, "WR_WEIGHT_RSV_2"}, 8, 8);
    add_hdl_path_slice({rdl_reg_name, "WR_WEIGHT_RSV_1"}, 16, 8);
    add_hdl_path_slice({rdl_reg_name, "WR_WEIGHT_RSV_0"}, 24, 8);
  endfunction: build
  
endclass : reg_addrmap_NVDLA_NVDLA_MCIF_CFG_WR_WEIGHT_1

// CFG_OUTSTANDING_CNT
class reg_addrmap_NVDLA_NVDLA_MCIF_CFG_OUTSTANDING_CNT extends uvm_reg_rdl;
  string m_rdl_tag;
  rand uvm_reg_field_rdl RD_OS_CNT;
  rand uvm_reg_field_rdl WR_OS_CNT;
  
  function new(string name = "reg_addrmap_NVDLA_NVDLA_MCIF_CFG_OUTSTANDING_CNT");
    super.new(name, 32, UVM_NO_COVERAGE);
  endfunction: new
  
  virtual function void build();
    string rdl_reg_name;
    this.RD_OS_CNT = new("RD_OS_CNT");
    this.RD_OS_CNT.set_rdl_access_info(1, 1, 1, 0, 0, 0);
    this.RD_OS_CNT.configure(this, 8, 0, "RW", 0, 8'hff, 1, 1, 0);
    this.RD_OS_CNT.add_def_property("spec_access", "rw");
    this.RD_OS_CNT.add_def_property("spec_sw_default", "0x0");
    this.RD_OS_CNT.add_def_property("sw_default_mask", "0x0");
    this.RD_OS_CNT.add_def_property("reset_mask", "0xff");
    this.WR_OS_CNT = new("WR_OS_CNT");
    this.WR_OS_CNT.set_rdl_access_info(1, 1, 1, 0, 0, 0);
    this.WR_OS_CNT.configure(this, 8, 8, "RW", 0, 8'hff, 1, 1, 0);
    this.WR_OS_CNT.add_def_property("spec_access", "rw");
    this.WR_OS_CNT.add_def_property("spec_sw_default", "0x0");
    this.WR_OS_CNT.add_def_property("sw_default_mask", "0x0");
    this.WR_OS_CNT.add_def_property("reset_mask", "0xff");
    
    rdl_reg_name = get_rdl_name("rg_");
    add_hdl_path_slice({rdl_reg_name, "RD_OS_CNT"}, 0, 8);
    add_hdl_path_slice({rdl_reg_name, "WR_OS_CNT"}, 8, 8);
  endfunction: build
  
endclass : reg_addrmap_NVDLA_NVDLA_MCIF_CFG_OUTSTANDING_CNT

// STATUS
class reg_addrmap_NVDLA_NVDLA_MCIF_STATUS extends uvm_reg_rdl;
  string m_rdl_tag;
  rand uvm_reg_field_rdl IDLE;
  
  function new(string name = "reg_addrmap_NVDLA_NVDLA_MCIF_STATUS");
    super.new(name, 32, UVM_NO_COVERAGE);
  endfunction: new
  
  virtual function void build();
    string rdl_reg_name;
    this.IDLE = new("IDLE");
    this.IDLE.set_rdl_access_info(1, 0, 0, 1, 0, 0);
    this.IDLE.configure(this, 1, 8, "RO", 1, 1'h1, 1, 0, 1);
    this.IDLE.add_def_property("spec_access", "r");
    this.IDLE.add_def_property("spec_sw_default", "0x0");
    this.IDLE.add_def_property("sw_default_mask", "0x0");
    this.IDLE.add_def_property("reset_mask", "0x1");
    
    rdl_reg_name = get_rdl_name("rg_");
    add_hdl_path_slice({rdl_reg_name, "IDLE"}, 8, 1);
  endfunction: build
  
endclass : reg_addrmap_NVDLA_NVDLA_MCIF_STATUS

// Block NVDLA_MCIF
class block_addrmap_NVDLA_NVDLA_MCIF extends uvm_reg_block_rdl;
  rand reg_addrmap_NVDLA_NVDLA_MCIF_CFG_RD_WEIGHT_0 CFG_RD_WEIGHT_0;
  rand reg_addrmap_NVDLA_NVDLA_MCIF_CFG_RD_WEIGHT_1 CFG_RD_WEIGHT_1;
  rand reg_addrmap_NVDLA_NVDLA_MCIF_CFG_RD_WEIGHT_2 CFG_RD_WEIGHT_2;
  rand reg_addrmap_NVDLA_NVDLA_MCIF_CFG_WR_WEIGHT_0 CFG_WR_WEIGHT_0;
  rand reg_addrmap_NVDLA_NVDLA_MCIF_CFG_WR_WEIGHT_1 CFG_WR_WEIGHT_1;
  rand reg_addrmap_NVDLA_NVDLA_MCIF_CFG_OUTSTANDING_CNT CFG_OUTSTANDING_CNT;
  rand reg_addrmap_NVDLA_NVDLA_MCIF_STATUS STATUS;
  
  function new(string name = "block_addrmap_NVDLA_NVDLA_MCIF");
    super.new(name);
  endfunction: new
  
  virtual function void build();
    this.default_map = create_map("", 0, 4, UVM_LITTLE_ENDIAN, 1);
    this.CFG_RD_WEIGHT_0 = new("CFG_RD_WEIGHT_0");
    this.CFG_RD_WEIGHT_0.configure(this, null, "");
    this.CFG_RD_WEIGHT_0.set_rdl_tag("CFG_RD_WEIGHT_0_");
    this.CFG_RD_WEIGHT_0.set_reg_test_info(0, 0, 2);
    this.CFG_RD_WEIGHT_0.build();
    this.default_map.add_reg(this.CFG_RD_WEIGHT_0, `UVM_REG_ADDR_WIDTH'h0, "RW", 0);
    this.CFG_RD_WEIGHT_1 = new("CFG_RD_WEIGHT_1");
    this.CFG_RD_WEIGHT_1.configure(this, null, "");
    this.CFG_RD_WEIGHT_1.set_rdl_tag("CFG_RD_WEIGHT_1_");
    this.CFG_RD_WEIGHT_1.set_reg_test_info(0, 0, 2);
    this.CFG_RD_WEIGHT_1.build();
    this.default_map.add_reg(this.CFG_RD_WEIGHT_1, `UVM_REG_ADDR_WIDTH'h4, "RW", 0);
    this.CFG_RD_WEIGHT_2 = new("CFG_RD_WEIGHT_2");
    this.CFG_RD_WEIGHT_2.configure(this, null, "");
    this.CFG_RD_WEIGHT_2.set_rdl_tag("CFG_RD_WEIGHT_2_");
    this.CFG_RD_WEIGHT_2.set_reg_test_info(0, 0, 2);
    this.CFG_RD_WEIGHT_2.build();
    this.default_map.add_reg(this.CFG_RD_WEIGHT_2, `UVM_REG_ADDR_WIDTH'h8, "RW", 0);
    this.CFG_WR_WEIGHT_0 = new("CFG_WR_WEIGHT_0");
    this.CFG_WR_WEIGHT_0.configure(this, null, "");
    this.CFG_WR_WEIGHT_0.set_rdl_tag("CFG_WR_WEIGHT_0_");
    this.CFG_WR_WEIGHT_0.set_reg_test_info(0, 0, 2);
    this.CFG_WR_WEIGHT_0.build();
    this.default_map.add_reg(this.CFG_WR_WEIGHT_0, `UVM_REG_ADDR_WIDTH'hc, "RW", 0);
    this.CFG_WR_WEIGHT_1 = new("CFG_WR_WEIGHT_1");
    this.CFG_WR_WEIGHT_1.configure(this, null, "");
    this.CFG_WR_WEIGHT_1.set_rdl_tag("CFG_WR_WEIGHT_1_");
    this.CFG_WR_WEIGHT_1.set_reg_test_info(0, 0, 2);
    this.CFG_WR_WEIGHT_1.build();
    this.default_map.add_reg(this.CFG_WR_WEIGHT_1, `UVM_REG_ADDR_WIDTH'h10, "RW", 0);
    this.CFG_OUTSTANDING_CNT = new("CFG_OUTSTANDING_CNT");
    this.CFG_OUTSTANDING_CNT.configure(this, null, "");
    this.CFG_OUTSTANDING_CNT.set_rdl_tag("CFG_OUTSTANDING_CNT_");
    this.CFG_OUTSTANDING_CNT.set_reg_test_info(0, 0, 2);
    this.CFG_OUTSTANDING_CNT.build();
    this.default_map.add_reg(this.CFG_OUTSTANDING_CNT, `UVM_REG_ADDR_WIDTH'h14, "RW", 0);
    this.STATUS = new("STATUS");
    this.STATUS.configure(this, null, "");
    this.STATUS.set_rdl_tag("STATUS_");
    this.STATUS.set_reg_test_info(0, 0, 32);
    this.STATUS.build();
    this.default_map.add_reg(this.STATUS, `UVM_REG_ADDR_WIDTH'h18, "RO", 0);
  endfunction: build
  
  `uvm_object_utils(block_addrmap_NVDLA_NVDLA_MCIF)
endclass : block_addrmap_NVDLA_NVDLA_MCIF

// Base block
class block_addrmap_NVDLA extends uvm_reg_block_rdl;
  rand block_addrmap_NVDLA_NVDLA_MCIF NVDLA_MCIF;
  
  function new(string name = "block_addrmap_NVDLA");
    super.new(name);
  endfunction: new
  
  virtual function void build();
    this.default_map = create_map("", `UVM_REG_ADDR_WIDTH'h0, 4, UVM_LITTLE_ENDIAN, 1);
    this.set_rdl_address_map(1);
    this.set_rdl_address_map_hdl_path({`ADDRMAP_NVDLA_PIO_INSTANCE_PATH, ".pio_logic"});
    this.NVDLA_MCIF = block_addrmap_NVDLA_NVDLA_MCIF::type_id::create("NVDLA_MCIF",, get_full_name());
    this.NVDLA_MCIF.configure(this, "");
    this.NVDLA_MCIF.set_rdl_tag("NVDLA_MCIF_");
    this.NVDLA_MCIF.build();
    this.default_map.add_submap(this.NVDLA_MCIF.default_map, `UVM_REG_ADDR_WIDTH'h2000);
    set_hdl_path_root({`ADDRMAP_NVDLA_PIO_INSTANCE_PATH, ".pio_logic"});
    this.add_callbacks();
  endfunction: build
  
  `uvm_object_utils(block_addrmap_NVDLA)
endclass : block_addrmap_NVDLA
