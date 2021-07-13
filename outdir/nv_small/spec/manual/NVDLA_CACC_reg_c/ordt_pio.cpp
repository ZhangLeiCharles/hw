//   Ordt 171103.01 autogenerated file 
//   Input: NVDLA_CACC.rdl
//   Parms: opendla.parms
//   Date: Tue Jul 13 11:42:13 SGT 2021
//

#include "ordt_pio_common.hpp"
#include "ordt_pio.hpp"

// ------------------ ordt_addr_elem methods ------------------

ordt_addr_elem::ordt_addr_elem(uint64_t _m_startaddress, uint64_t _m_endaddress)
  : m_startaddress(_m_startaddress),
    m_endaddress(_m_endaddress) {
}

bool  ordt_addr_elem::containsAddress(const uint64_t &addr) {
  return ((addr >= m_startaddress) && (addr <= m_endaddress));
}

bool  ordt_addr_elem::isBelowAddress(const uint64_t &addr) {
  return (addr > m_endaddress);
}

bool  ordt_addr_elem::isAboveAddress(const uint64_t &addr) {
  return (addr < m_startaddress);
}

bool  ordt_addr_elem::hasStartAddress(const uint64_t &addr) {
  return (addr == m_startaddress);
}

void  ordt_addr_elem::update_child_ptrs() {
}

// ------------------ ordt_regset methods ------------------

ordt_addr_elem*  ordt_regset::findAddrElem(const uint64_t &addr) {
  int lo = 0;
  int hi = m_children.size()-1;
  int mid = 0;
  while (lo <= hi) {
     mid = (lo + hi) / 2;
     if (m_children[mid]->containsAddress(addr)) {
        //outElem = m_children[mid];
        return m_children[mid];
     }
     else if (m_children[mid]->isAboveAddress(addr))
        hi = mid - 1;
     else
        lo = mid + 1;
  }
  return nullptr;
}

ordt_regset::ordt_regset(uint64_t _m_startaddress, uint64_t _m_endaddress)
  : ordt_addr_elem(_m_startaddress, _m_endaddress) {
}

int  ordt_regset::write(const uint64_t &addr, const ordt_data &wdata) {
     if (this->containsAddress(addr)) {
        childElem = this->findAddrElem(addr);
        if (childElem != nullptr) { return childElem->write(addr, wdata); }
     }
  #ifdef ORDT_PIO_VERBOSE
     std::cout << "--> write to invalid address " << addr << " in regset\n";
  #endif
     return 8;
}

int  ordt_regset::read(const uint64_t &addr, ordt_data &rdata) {
     if (this->containsAddress(addr)) {
        childElem = this->findAddrElem(addr);
        if (childElem != nullptr) { return childElem->read(addr, rdata); }
     }
  #ifdef ORDT_PIO_VERBOSE
     std::cout << "--> read to invalid address " << addr << " in regset\n";
  #endif
     rdata.clear();
     return 8;
}

// ------------------ ordt_reg methods ------------------

ordt_reg::ordt_reg(uint64_t _m_startaddress, uint64_t _m_endaddress)
  : ordt_addr_elem(_m_startaddress, _m_endaddress) {
}

ordt_reg::ordt_reg(const ordt_reg &_old)
  : ordt_addr_elem(_old),
    m_mutex() {
}

void  ordt_reg::write(const ordt_data &wdata) {
}

int  ordt_reg::write(const uint64_t &addr, const ordt_data &wdata) {
     return 0;
}

void  ordt_reg::read(ordt_data &rdata) {
}

int  ordt_reg::read(const uint64_t &addr, ordt_data &rdata) {
     return 0;
}

// ------------------ ordt_rg_NVDLA_CACC_S_STATUS methods ------------------

ordt_rg_NVDLA_CACC_S_STATUS::ordt_rg_NVDLA_CACC_S_STATUS(uint64_t _m_startaddress, uint64_t _m_endaddress)
  : ordt_reg(_m_startaddress, _m_endaddress),
    STATUS_0(0, 2, 0x0, r_std, w_none),
    STATUS_1(16, 2, 0x0, r_std, w_none) {
}

int  ordt_rg_NVDLA_CACC_S_STATUS::write(const uint64_t &addr, const ordt_data &wdata) {
  #ifdef ORDT_PIO_VERBOSE
     std::cout << "--> write of reg ordt_rg_NVDLA_CACC_S_STATUS at addr="<< addr << ", data=" << wdata.to_string() << "\n";
  #endif
     if (this->hasStartAddress(addr)) {
        this->write(wdata);
        return 0;
     }
  #ifdef ORDT_PIO_VERBOSE
     std::cout << "--> write to invalid address " << addr << " in reg ordt_rg_NVDLA_CACC_S_STATUS\n";
  #endif
     return 8;
}

void  ordt_rg_NVDLA_CACC_S_STATUS::write(const ordt_data &wdata) {
  std::lock_guard<std::mutex> m_guard(m_mutex);
  STATUS_0.write(wdata);
  STATUS_1.write(wdata);
}

int  ordt_rg_NVDLA_CACC_S_STATUS::read(const uint64_t &addr, ordt_data &rdata) {
  #ifdef ORDT_PIO_VERBOSE
     std::cout << "--> read of reg ordt_rg_NVDLA_CACC_S_STATUS at addr="<< addr << "\n";
  #endif
     if (this->hasStartAddress(addr)) {
        this->read(rdata);
        return 0;
     }
  #ifdef ORDT_PIO_VERBOSE
     std::cout << "--> read to invalid address " << addr << " in reg ordt_rg_NVDLA_CACC_S_STATUS\n";
  #endif
     rdata.clear();
     return 8;
}

void  ordt_rg_NVDLA_CACC_S_STATUS::read(ordt_data &rdata) {
  rdata.clear();
  for (int widx=0; widx<((m_endaddress - m_startaddress + 1)/4); widx++) rdata.push_back(0);
  STATUS_0.read(rdata);
  STATUS_1.read(rdata);
}

// ------------------ ordt_rg_NVDLA_CACC_S_POINTER methods ------------------

ordt_rg_NVDLA_CACC_S_POINTER::ordt_rg_NVDLA_CACC_S_POINTER(uint64_t _m_startaddress, uint64_t _m_endaddress)
  : ordt_reg(_m_startaddress, _m_endaddress),
    PRODUCER(0, 1, 0x0, r_std, w_std),
    CONSUMER(16, 1, 0x0, r_std, w_none) {
}

int  ordt_rg_NVDLA_CACC_S_POINTER::write(const uint64_t &addr, const ordt_data &wdata) {
  #ifdef ORDT_PIO_VERBOSE
     std::cout << "--> write of reg ordt_rg_NVDLA_CACC_S_POINTER at addr="<< addr << ", data=" << wdata.to_string() << "\n";
  #endif
     if (this->hasStartAddress(addr)) {
        this->write(wdata);
        return 0;
     }
  #ifdef ORDT_PIO_VERBOSE
     std::cout << "--> write to invalid address " << addr << " in reg ordt_rg_NVDLA_CACC_S_POINTER\n";
  #endif
     return 8;
}

void  ordt_rg_NVDLA_CACC_S_POINTER::write(const ordt_data &wdata) {
  std::lock_guard<std::mutex> m_guard(m_mutex);
  PRODUCER.write(wdata);
  CONSUMER.write(wdata);
}

int  ordt_rg_NVDLA_CACC_S_POINTER::read(const uint64_t &addr, ordt_data &rdata) {
  #ifdef ORDT_PIO_VERBOSE
     std::cout << "--> read of reg ordt_rg_NVDLA_CACC_S_POINTER at addr="<< addr << "\n";
  #endif
     if (this->hasStartAddress(addr)) {
        this->read(rdata);
        return 0;
     }
  #ifdef ORDT_PIO_VERBOSE
     std::cout << "--> read to invalid address " << addr << " in reg ordt_rg_NVDLA_CACC_S_POINTER\n";
  #endif
     rdata.clear();
     return 8;
}

void  ordt_rg_NVDLA_CACC_S_POINTER::read(ordt_data &rdata) {
  rdata.clear();
  for (int widx=0; widx<((m_endaddress - m_startaddress + 1)/4); widx++) rdata.push_back(0);
  PRODUCER.read(rdata);
  CONSUMER.read(rdata);
}

// ------------------ ordt_rg_NVDLA_CACC_D_OP_ENABLE methods ------------------

ordt_rg_NVDLA_CACC_D_OP_ENABLE::ordt_rg_NVDLA_CACC_D_OP_ENABLE(uint64_t _m_startaddress, uint64_t _m_endaddress)
  : ordt_reg(_m_startaddress, _m_endaddress),
    OP_EN(0, 1, 0x0, r_std, w_std) {
}

int  ordt_rg_NVDLA_CACC_D_OP_ENABLE::write(const uint64_t &addr, const ordt_data &wdata) {
  #ifdef ORDT_PIO_VERBOSE
     std::cout << "--> write of reg ordt_rg_NVDLA_CACC_D_OP_ENABLE at addr="<< addr << ", data=" << wdata.to_string() << "\n";
  #endif
     if (this->hasStartAddress(addr)) {
        this->write(wdata);
        return 0;
     }
  #ifdef ORDT_PIO_VERBOSE
     std::cout << "--> write to invalid address " << addr << " in reg ordt_rg_NVDLA_CACC_D_OP_ENABLE\n";
  #endif
     return 8;
}

void  ordt_rg_NVDLA_CACC_D_OP_ENABLE::write(const ordt_data &wdata) {
  std::lock_guard<std::mutex> m_guard(m_mutex);
  OP_EN.write(wdata);
}

int  ordt_rg_NVDLA_CACC_D_OP_ENABLE::read(const uint64_t &addr, ordt_data &rdata) {
  #ifdef ORDT_PIO_VERBOSE
     std::cout << "--> read of reg ordt_rg_NVDLA_CACC_D_OP_ENABLE at addr="<< addr << "\n";
  #endif
     if (this->hasStartAddress(addr)) {
        this->read(rdata);
        return 0;
     }
  #ifdef ORDT_PIO_VERBOSE
     std::cout << "--> read to invalid address " << addr << " in reg ordt_rg_NVDLA_CACC_D_OP_ENABLE\n";
  #endif
     rdata.clear();
     return 8;
}

void  ordt_rg_NVDLA_CACC_D_OP_ENABLE::read(ordt_data &rdata) {
  rdata.clear();
  for (int widx=0; widx<((m_endaddress - m_startaddress + 1)/4); widx++) rdata.push_back(0);
  OP_EN.read(rdata);
}

// ------------------ ordt_rg_NVDLA_CACC_D_MISC_CFG methods ------------------

ordt_rg_NVDLA_CACC_D_MISC_CFG::ordt_rg_NVDLA_CACC_D_MISC_CFG(uint64_t _m_startaddress, uint64_t _m_endaddress)
  : ordt_reg(_m_startaddress, _m_endaddress),
    CONV_MODE(0, 1, 0x0, r_std, w_std),
    PROC_PRECISION(12, 2, 0x1, r_std, w_std) {
}

int  ordt_rg_NVDLA_CACC_D_MISC_CFG::write(const uint64_t &addr, const ordt_data &wdata) {
  #ifdef ORDT_PIO_VERBOSE
     std::cout << "--> write of reg ordt_rg_NVDLA_CACC_D_MISC_CFG at addr="<< addr << ", data=" << wdata.to_string() << "\n";
  #endif
     if (this->hasStartAddress(addr)) {
        this->write(wdata);
        return 0;
     }
  #ifdef ORDT_PIO_VERBOSE
     std::cout << "--> write to invalid address " << addr << " in reg ordt_rg_NVDLA_CACC_D_MISC_CFG\n";
  #endif
     return 8;
}

void  ordt_rg_NVDLA_CACC_D_MISC_CFG::write(const ordt_data &wdata) {
  std::lock_guard<std::mutex> m_guard(m_mutex);
  CONV_MODE.write(wdata);
  PROC_PRECISION.write(wdata);
}

int  ordt_rg_NVDLA_CACC_D_MISC_CFG::read(const uint64_t &addr, ordt_data &rdata) {
  #ifdef ORDT_PIO_VERBOSE
     std::cout << "--> read of reg ordt_rg_NVDLA_CACC_D_MISC_CFG at addr="<< addr << "\n";
  #endif
     if (this->hasStartAddress(addr)) {
        this->read(rdata);
        return 0;
     }
  #ifdef ORDT_PIO_VERBOSE
     std::cout << "--> read to invalid address " << addr << " in reg ordt_rg_NVDLA_CACC_D_MISC_CFG\n";
  #endif
     rdata.clear();
     return 8;
}

void  ordt_rg_NVDLA_CACC_D_MISC_CFG::read(ordt_data &rdata) {
  rdata.clear();
  for (int widx=0; widx<((m_endaddress - m_startaddress + 1)/4); widx++) rdata.push_back(0);
  CONV_MODE.read(rdata);
  PROC_PRECISION.read(rdata);
}

// ------------------ ordt_rg_NVDLA_CACC_D_DATAOUT_SIZE_0 methods ------------------

ordt_rg_NVDLA_CACC_D_DATAOUT_SIZE_0::ordt_rg_NVDLA_CACC_D_DATAOUT_SIZE_0(uint64_t _m_startaddress, uint64_t _m_endaddress)
  : ordt_reg(_m_startaddress, _m_endaddress),
    DATAOUT_WIDTH(0, 13, 0x0, r_std, w_std),
    DATAOUT_HEIGHT(16, 13, 0x0, r_std, w_std) {
}

int  ordt_rg_NVDLA_CACC_D_DATAOUT_SIZE_0::write(const uint64_t &addr, const ordt_data &wdata) {
  #ifdef ORDT_PIO_VERBOSE
     std::cout << "--> write of reg ordt_rg_NVDLA_CACC_D_DATAOUT_SIZE_0 at addr="<< addr << ", data=" << wdata.to_string() << "\n";
  #endif
     if (this->hasStartAddress(addr)) {
        this->write(wdata);
        return 0;
     }
  #ifdef ORDT_PIO_VERBOSE
     std::cout << "--> write to invalid address " << addr << " in reg ordt_rg_NVDLA_CACC_D_DATAOUT_SIZE_0\n";
  #endif
     return 8;
}

void  ordt_rg_NVDLA_CACC_D_DATAOUT_SIZE_0::write(const ordt_data &wdata) {
  std::lock_guard<std::mutex> m_guard(m_mutex);
  DATAOUT_WIDTH.write(wdata);
  DATAOUT_HEIGHT.write(wdata);
}

int  ordt_rg_NVDLA_CACC_D_DATAOUT_SIZE_0::read(const uint64_t &addr, ordt_data &rdata) {
  #ifdef ORDT_PIO_VERBOSE
     std::cout << "--> read of reg ordt_rg_NVDLA_CACC_D_DATAOUT_SIZE_0 at addr="<< addr << "\n";
  #endif
     if (this->hasStartAddress(addr)) {
        this->read(rdata);
        return 0;
     }
  #ifdef ORDT_PIO_VERBOSE
     std::cout << "--> read to invalid address " << addr << " in reg ordt_rg_NVDLA_CACC_D_DATAOUT_SIZE_0\n";
  #endif
     rdata.clear();
     return 8;
}

void  ordt_rg_NVDLA_CACC_D_DATAOUT_SIZE_0::read(ordt_data &rdata) {
  rdata.clear();
  for (int widx=0; widx<((m_endaddress - m_startaddress + 1)/4); widx++) rdata.push_back(0);
  DATAOUT_WIDTH.read(rdata);
  DATAOUT_HEIGHT.read(rdata);
}

// ------------------ ordt_rg_NVDLA_CACC_D_DATAOUT_SIZE_1 methods ------------------

ordt_rg_NVDLA_CACC_D_DATAOUT_SIZE_1::ordt_rg_NVDLA_CACC_D_DATAOUT_SIZE_1(uint64_t _m_startaddress, uint64_t _m_endaddress)
  : ordt_reg(_m_startaddress, _m_endaddress),
    DATAOUT_CHANNEL(0, 13, 0x0, r_std, w_std) {
}

int  ordt_rg_NVDLA_CACC_D_DATAOUT_SIZE_1::write(const uint64_t &addr, const ordt_data &wdata) {
  #ifdef ORDT_PIO_VERBOSE
     std::cout << "--> write of reg ordt_rg_NVDLA_CACC_D_DATAOUT_SIZE_1 at addr="<< addr << ", data=" << wdata.to_string() << "\n";
  #endif
     if (this->hasStartAddress(addr)) {
        this->write(wdata);
        return 0;
     }
  #ifdef ORDT_PIO_VERBOSE
     std::cout << "--> write to invalid address " << addr << " in reg ordt_rg_NVDLA_CACC_D_DATAOUT_SIZE_1\n";
  #endif
     return 8;
}

void  ordt_rg_NVDLA_CACC_D_DATAOUT_SIZE_1::write(const ordt_data &wdata) {
  std::lock_guard<std::mutex> m_guard(m_mutex);
  DATAOUT_CHANNEL.write(wdata);
}

int  ordt_rg_NVDLA_CACC_D_DATAOUT_SIZE_1::read(const uint64_t &addr, ordt_data &rdata) {
  #ifdef ORDT_PIO_VERBOSE
     std::cout << "--> read of reg ordt_rg_NVDLA_CACC_D_DATAOUT_SIZE_1 at addr="<< addr << "\n";
  #endif
     if (this->hasStartAddress(addr)) {
        this->read(rdata);
        return 0;
     }
  #ifdef ORDT_PIO_VERBOSE
     std::cout << "--> read to invalid address " << addr << " in reg ordt_rg_NVDLA_CACC_D_DATAOUT_SIZE_1\n";
  #endif
     rdata.clear();
     return 8;
}

void  ordt_rg_NVDLA_CACC_D_DATAOUT_SIZE_1::read(ordt_data &rdata) {
  rdata.clear();
  for (int widx=0; widx<((m_endaddress - m_startaddress + 1)/4); widx++) rdata.push_back(0);
  DATAOUT_CHANNEL.read(rdata);
}

// ------------------ ordt_rg_NVDLA_CACC_D_DATAOUT_ADDR methods ------------------

ordt_rg_NVDLA_CACC_D_DATAOUT_ADDR::ordt_rg_NVDLA_CACC_D_DATAOUT_ADDR(uint64_t _m_startaddress, uint64_t _m_endaddress)
  : ordt_reg(_m_startaddress, _m_endaddress),
    DATAOUT_ADDR(0, 32, 0x0, r_std, w_std) {
}

int  ordt_rg_NVDLA_CACC_D_DATAOUT_ADDR::write(const uint64_t &addr, const ordt_data &wdata) {
  #ifdef ORDT_PIO_VERBOSE
     std::cout << "--> write of reg ordt_rg_NVDLA_CACC_D_DATAOUT_ADDR at addr="<< addr << ", data=" << wdata.to_string() << "\n";
  #endif
     if (this->hasStartAddress(addr)) {
        this->write(wdata);
        return 0;
     }
  #ifdef ORDT_PIO_VERBOSE
     std::cout << "--> write to invalid address " << addr << " in reg ordt_rg_NVDLA_CACC_D_DATAOUT_ADDR\n";
  #endif
     return 8;
}

void  ordt_rg_NVDLA_CACC_D_DATAOUT_ADDR::write(const ordt_data &wdata) {
  std::lock_guard<std::mutex> m_guard(m_mutex);
  DATAOUT_ADDR.write(wdata);
}

int  ordt_rg_NVDLA_CACC_D_DATAOUT_ADDR::read(const uint64_t &addr, ordt_data &rdata) {
  #ifdef ORDT_PIO_VERBOSE
     std::cout << "--> read of reg ordt_rg_NVDLA_CACC_D_DATAOUT_ADDR at addr="<< addr << "\n";
  #endif
     if (this->hasStartAddress(addr)) {
        this->read(rdata);
        return 0;
     }
  #ifdef ORDT_PIO_VERBOSE
     std::cout << "--> read to invalid address " << addr << " in reg ordt_rg_NVDLA_CACC_D_DATAOUT_ADDR\n";
  #endif
     rdata.clear();
     return 8;
}

void  ordt_rg_NVDLA_CACC_D_DATAOUT_ADDR::read(ordt_data &rdata) {
  rdata.clear();
  for (int widx=0; widx<((m_endaddress - m_startaddress + 1)/4); widx++) rdata.push_back(0);
  DATAOUT_ADDR.read(rdata);
}

// ------------------ ordt_rg_NVDLA_CACC_D_BATCH_NUMBER methods ------------------

ordt_rg_NVDLA_CACC_D_BATCH_NUMBER::ordt_rg_NVDLA_CACC_D_BATCH_NUMBER(uint64_t _m_startaddress, uint64_t _m_endaddress)
  : ordt_reg(_m_startaddress, _m_endaddress),
    BATCHES(0, 5, 0x0, r_std, w_std) {
}

int  ordt_rg_NVDLA_CACC_D_BATCH_NUMBER::write(const uint64_t &addr, const ordt_data &wdata) {
  #ifdef ORDT_PIO_VERBOSE
     std::cout << "--> write of reg ordt_rg_NVDLA_CACC_D_BATCH_NUMBER at addr="<< addr << ", data=" << wdata.to_string() << "\n";
  #endif
     if (this->hasStartAddress(addr)) {
        this->write(wdata);
        return 0;
     }
  #ifdef ORDT_PIO_VERBOSE
     std::cout << "--> write to invalid address " << addr << " in reg ordt_rg_NVDLA_CACC_D_BATCH_NUMBER\n";
  #endif
     return 8;
}

void  ordt_rg_NVDLA_CACC_D_BATCH_NUMBER::write(const ordt_data &wdata) {
  std::lock_guard<std::mutex> m_guard(m_mutex);
  BATCHES.write(wdata);
}

int  ordt_rg_NVDLA_CACC_D_BATCH_NUMBER::read(const uint64_t &addr, ordt_data &rdata) {
  #ifdef ORDT_PIO_VERBOSE
     std::cout << "--> read of reg ordt_rg_NVDLA_CACC_D_BATCH_NUMBER at addr="<< addr << "\n";
  #endif
     if (this->hasStartAddress(addr)) {
        this->read(rdata);
        return 0;
     }
  #ifdef ORDT_PIO_VERBOSE
     std::cout << "--> read to invalid address " << addr << " in reg ordt_rg_NVDLA_CACC_D_BATCH_NUMBER\n";
  #endif
     rdata.clear();
     return 8;
}

void  ordt_rg_NVDLA_CACC_D_BATCH_NUMBER::read(ordt_data &rdata) {
  rdata.clear();
  for (int widx=0; widx<((m_endaddress - m_startaddress + 1)/4); widx++) rdata.push_back(0);
  BATCHES.read(rdata);
}

// ------------------ ordt_rg_NVDLA_CACC_D_LINE_STRIDE methods ------------------

ordt_rg_NVDLA_CACC_D_LINE_STRIDE::ordt_rg_NVDLA_CACC_D_LINE_STRIDE(uint64_t _m_startaddress, uint64_t _m_endaddress)
  : ordt_reg(_m_startaddress, _m_endaddress),
    LINE_STRIDE(0, 24, 0x0, r_std, w_std) {
}

int  ordt_rg_NVDLA_CACC_D_LINE_STRIDE::write(const uint64_t &addr, const ordt_data &wdata) {
  #ifdef ORDT_PIO_VERBOSE
     std::cout << "--> write of reg ordt_rg_NVDLA_CACC_D_LINE_STRIDE at addr="<< addr << ", data=" << wdata.to_string() << "\n";
  #endif
     if (this->hasStartAddress(addr)) {
        this->write(wdata);
        return 0;
     }
  #ifdef ORDT_PIO_VERBOSE
     std::cout << "--> write to invalid address " << addr << " in reg ordt_rg_NVDLA_CACC_D_LINE_STRIDE\n";
  #endif
     return 8;
}

void  ordt_rg_NVDLA_CACC_D_LINE_STRIDE::write(const ordt_data &wdata) {
  std::lock_guard<std::mutex> m_guard(m_mutex);
  LINE_STRIDE.write(wdata);
}

int  ordt_rg_NVDLA_CACC_D_LINE_STRIDE::read(const uint64_t &addr, ordt_data &rdata) {
  #ifdef ORDT_PIO_VERBOSE
     std::cout << "--> read of reg ordt_rg_NVDLA_CACC_D_LINE_STRIDE at addr="<< addr << "\n";
  #endif
     if (this->hasStartAddress(addr)) {
        this->read(rdata);
        return 0;
     }
  #ifdef ORDT_PIO_VERBOSE
     std::cout << "--> read to invalid address " << addr << " in reg ordt_rg_NVDLA_CACC_D_LINE_STRIDE\n";
  #endif
     rdata.clear();
     return 8;
}

void  ordt_rg_NVDLA_CACC_D_LINE_STRIDE::read(ordt_data &rdata) {
  rdata.clear();
  for (int widx=0; widx<((m_endaddress - m_startaddress + 1)/4); widx++) rdata.push_back(0);
  LINE_STRIDE.read(rdata);
}

// ------------------ ordt_rg_NVDLA_CACC_D_SURF_STRIDE methods ------------------

ordt_rg_NVDLA_CACC_D_SURF_STRIDE::ordt_rg_NVDLA_CACC_D_SURF_STRIDE(uint64_t _m_startaddress, uint64_t _m_endaddress)
  : ordt_reg(_m_startaddress, _m_endaddress),
    SURF_STRIDE(0, 24, 0x0, r_std, w_std) {
}

int  ordt_rg_NVDLA_CACC_D_SURF_STRIDE::write(const uint64_t &addr, const ordt_data &wdata) {
  #ifdef ORDT_PIO_VERBOSE
     std::cout << "--> write of reg ordt_rg_NVDLA_CACC_D_SURF_STRIDE at addr="<< addr << ", data=" << wdata.to_string() << "\n";
  #endif
     if (this->hasStartAddress(addr)) {
        this->write(wdata);
        return 0;
     }
  #ifdef ORDT_PIO_VERBOSE
     std::cout << "--> write to invalid address " << addr << " in reg ordt_rg_NVDLA_CACC_D_SURF_STRIDE\n";
  #endif
     return 8;
}

void  ordt_rg_NVDLA_CACC_D_SURF_STRIDE::write(const ordt_data &wdata) {
  std::lock_guard<std::mutex> m_guard(m_mutex);
  SURF_STRIDE.write(wdata);
}

int  ordt_rg_NVDLA_CACC_D_SURF_STRIDE::read(const uint64_t &addr, ordt_data &rdata) {
  #ifdef ORDT_PIO_VERBOSE
     std::cout << "--> read of reg ordt_rg_NVDLA_CACC_D_SURF_STRIDE at addr="<< addr << "\n";
  #endif
     if (this->hasStartAddress(addr)) {
        this->read(rdata);
        return 0;
     }
  #ifdef ORDT_PIO_VERBOSE
     std::cout << "--> read to invalid address " << addr << " in reg ordt_rg_NVDLA_CACC_D_SURF_STRIDE\n";
  #endif
     rdata.clear();
     return 8;
}

void  ordt_rg_NVDLA_CACC_D_SURF_STRIDE::read(ordt_data &rdata) {
  rdata.clear();
  for (int widx=0; widx<((m_endaddress - m_startaddress + 1)/4); widx++) rdata.push_back(0);
  SURF_STRIDE.read(rdata);
}

// ------------------ ordt_rg_NVDLA_CACC_D_DATAOUT_MAP methods ------------------

ordt_rg_NVDLA_CACC_D_DATAOUT_MAP::ordt_rg_NVDLA_CACC_D_DATAOUT_MAP(uint64_t _m_startaddress, uint64_t _m_endaddress)
  : ordt_reg(_m_startaddress, _m_endaddress),
    LINE_PACKED(0, 1, 0x0, r_std, w_std),
    SURF_PACKED(16, 1, 0x0, r_std, w_std) {
}

int  ordt_rg_NVDLA_CACC_D_DATAOUT_MAP::write(const uint64_t &addr, const ordt_data &wdata) {
  #ifdef ORDT_PIO_VERBOSE
     std::cout << "--> write of reg ordt_rg_NVDLA_CACC_D_DATAOUT_MAP at addr="<< addr << ", data=" << wdata.to_string() << "\n";
  #endif
     if (this->hasStartAddress(addr)) {
        this->write(wdata);
        return 0;
     }
  #ifdef ORDT_PIO_VERBOSE
     std::cout << "--> write to invalid address " << addr << " in reg ordt_rg_NVDLA_CACC_D_DATAOUT_MAP\n";
  #endif
     return 8;
}

void  ordt_rg_NVDLA_CACC_D_DATAOUT_MAP::write(const ordt_data &wdata) {
  std::lock_guard<std::mutex> m_guard(m_mutex);
  LINE_PACKED.write(wdata);
  SURF_PACKED.write(wdata);
}

int  ordt_rg_NVDLA_CACC_D_DATAOUT_MAP::read(const uint64_t &addr, ordt_data &rdata) {
  #ifdef ORDT_PIO_VERBOSE
     std::cout << "--> read of reg ordt_rg_NVDLA_CACC_D_DATAOUT_MAP at addr="<< addr << "\n";
  #endif
     if (this->hasStartAddress(addr)) {
        this->read(rdata);
        return 0;
     }
  #ifdef ORDT_PIO_VERBOSE
     std::cout << "--> read to invalid address " << addr << " in reg ordt_rg_NVDLA_CACC_D_DATAOUT_MAP\n";
  #endif
     rdata.clear();
     return 8;
}

void  ordt_rg_NVDLA_CACC_D_DATAOUT_MAP::read(ordt_data &rdata) {
  rdata.clear();
  for (int widx=0; widx<((m_endaddress - m_startaddress + 1)/4); widx++) rdata.push_back(0);
  LINE_PACKED.read(rdata);
  SURF_PACKED.read(rdata);
}

// ------------------ ordt_rg_NVDLA_CACC_D_CLIP_CFG methods ------------------

ordt_rg_NVDLA_CACC_D_CLIP_CFG::ordt_rg_NVDLA_CACC_D_CLIP_CFG(uint64_t _m_startaddress, uint64_t _m_endaddress)
  : ordt_reg(_m_startaddress, _m_endaddress),
    CLIP_TRUNCATE(0, 5, 0x0, r_std, w_std) {
}

int  ordt_rg_NVDLA_CACC_D_CLIP_CFG::write(const uint64_t &addr, const ordt_data &wdata) {
  #ifdef ORDT_PIO_VERBOSE
     std::cout << "--> write of reg ordt_rg_NVDLA_CACC_D_CLIP_CFG at addr="<< addr << ", data=" << wdata.to_string() << "\n";
  #endif
     if (this->hasStartAddress(addr)) {
        this->write(wdata);
        return 0;
     }
  #ifdef ORDT_PIO_VERBOSE
     std::cout << "--> write to invalid address " << addr << " in reg ordt_rg_NVDLA_CACC_D_CLIP_CFG\n";
  #endif
     return 8;
}

void  ordt_rg_NVDLA_CACC_D_CLIP_CFG::write(const ordt_data &wdata) {
  std::lock_guard<std::mutex> m_guard(m_mutex);
  CLIP_TRUNCATE.write(wdata);
}

int  ordt_rg_NVDLA_CACC_D_CLIP_CFG::read(const uint64_t &addr, ordt_data &rdata) {
  #ifdef ORDT_PIO_VERBOSE
     std::cout << "--> read of reg ordt_rg_NVDLA_CACC_D_CLIP_CFG at addr="<< addr << "\n";
  #endif
     if (this->hasStartAddress(addr)) {
        this->read(rdata);
        return 0;
     }
  #ifdef ORDT_PIO_VERBOSE
     std::cout << "--> read to invalid address " << addr << " in reg ordt_rg_NVDLA_CACC_D_CLIP_CFG\n";
  #endif
     rdata.clear();
     return 8;
}

void  ordt_rg_NVDLA_CACC_D_CLIP_CFG::read(ordt_data &rdata) {
  rdata.clear();
  for (int widx=0; widx<((m_endaddress - m_startaddress + 1)/4); widx++) rdata.push_back(0);
  CLIP_TRUNCATE.read(rdata);
}

// ------------------ ordt_rg_NVDLA_CACC_D_OUT_SATURATION methods ------------------

ordt_rg_NVDLA_CACC_D_OUT_SATURATION::ordt_rg_NVDLA_CACC_D_OUT_SATURATION(uint64_t _m_startaddress, uint64_t _m_endaddress)
  : ordt_reg(_m_startaddress, _m_endaddress),
    SAT_COUNT(0, 32, 0x0, r_std, w_none) {
}

int  ordt_rg_NVDLA_CACC_D_OUT_SATURATION::write(const uint64_t &addr, const ordt_data &wdata) {
  #ifdef ORDT_PIO_VERBOSE
     std::cout << "--> write of reg ordt_rg_NVDLA_CACC_D_OUT_SATURATION at addr="<< addr << ", data=" << wdata.to_string() << "\n";
  #endif
     if (this->hasStartAddress(addr)) {
        this->write(wdata);
        return 0;
     }
  #ifdef ORDT_PIO_VERBOSE
     std::cout << "--> write to invalid address " << addr << " in reg ordt_rg_NVDLA_CACC_D_OUT_SATURATION\n";
  #endif
     return 8;
}

void  ordt_rg_NVDLA_CACC_D_OUT_SATURATION::write(const ordt_data &wdata) {
  std::lock_guard<std::mutex> m_guard(m_mutex);
  SAT_COUNT.write(wdata);
}

int  ordt_rg_NVDLA_CACC_D_OUT_SATURATION::read(const uint64_t &addr, ordt_data &rdata) {
  #ifdef ORDT_PIO_VERBOSE
     std::cout << "--> read of reg ordt_rg_NVDLA_CACC_D_OUT_SATURATION at addr="<< addr << "\n";
  #endif
     if (this->hasStartAddress(addr)) {
        this->read(rdata);
        return 0;
     }
  #ifdef ORDT_PIO_VERBOSE
     std::cout << "--> read to invalid address " << addr << " in reg ordt_rg_NVDLA_CACC_D_OUT_SATURATION\n";
  #endif
     rdata.clear();
     return 8;
}

void  ordt_rg_NVDLA_CACC_D_OUT_SATURATION::read(ordt_data &rdata) {
  rdata.clear();
  for (int widx=0; widx<((m_endaddress - m_startaddress + 1)/4); widx++) rdata.push_back(0);
  SAT_COUNT.read(rdata);
}

// ------------------ ordt_rg_NVDLA_CACC_D_CYA methods ------------------

ordt_rg_NVDLA_CACC_D_CYA::ordt_rg_NVDLA_CACC_D_CYA(uint64_t _m_startaddress, uint64_t _m_endaddress)
  : ordt_reg(_m_startaddress, _m_endaddress),
    CYA(0, 32, 0x0, r_std, w_std) {
}

int  ordt_rg_NVDLA_CACC_D_CYA::write(const uint64_t &addr, const ordt_data &wdata) {
  #ifdef ORDT_PIO_VERBOSE
     std::cout << "--> write of reg ordt_rg_NVDLA_CACC_D_CYA at addr="<< addr << ", data=" << wdata.to_string() << "\n";
  #endif
     if (this->hasStartAddress(addr)) {
        this->write(wdata);
        return 0;
     }
  #ifdef ORDT_PIO_VERBOSE
     std::cout << "--> write to invalid address " << addr << " in reg ordt_rg_NVDLA_CACC_D_CYA\n";
  #endif
     return 8;
}

void  ordt_rg_NVDLA_CACC_D_CYA::write(const ordt_data &wdata) {
  std::lock_guard<std::mutex> m_guard(m_mutex);
  CYA.write(wdata);
}

int  ordt_rg_NVDLA_CACC_D_CYA::read(const uint64_t &addr, ordt_data &rdata) {
  #ifdef ORDT_PIO_VERBOSE
     std::cout << "--> read of reg ordt_rg_NVDLA_CACC_D_CYA at addr="<< addr << "\n";
  #endif
     if (this->hasStartAddress(addr)) {
        this->read(rdata);
        return 0;
     }
  #ifdef ORDT_PIO_VERBOSE
     std::cout << "--> read to invalid address " << addr << " in reg ordt_rg_NVDLA_CACC_D_CYA\n";
  #endif
     rdata.clear();
     return 8;
}

void  ordt_rg_NVDLA_CACC_D_CYA::read(ordt_data &rdata) {
  rdata.clear();
  for (int widx=0; widx<((m_endaddress - m_startaddress + 1)/4); widx++) rdata.push_back(0);
  CYA.read(rdata);
}

// ------------------ ordt_rset_NVDLA_CACC methods ------------------

ordt_rset_NVDLA_CACC::ordt_rset_NVDLA_CACC(uint64_t _m_startaddress, uint64_t _m_endaddress)
  : ordt_regset(_m_startaddress, _m_endaddress),
    S_STATUS(_m_startaddress + 0x0, _m_startaddress + 0x3),
    S_POINTER(_m_startaddress + 0x4, _m_startaddress + 0x7),
    D_OP_ENABLE(_m_startaddress + 0x8, _m_startaddress + 0xb),
    D_MISC_CFG(_m_startaddress + 0xc, _m_startaddress + 0xf),
    D_DATAOUT_SIZE_0(_m_startaddress + 0x10, _m_startaddress + 0x13),
    D_DATAOUT_SIZE_1(_m_startaddress + 0x14, _m_startaddress + 0x17),
    D_DATAOUT_ADDR(_m_startaddress + 0x18, _m_startaddress + 0x1b),
    D_BATCH_NUMBER(_m_startaddress + 0x1c, _m_startaddress + 0x1f),
    D_LINE_STRIDE(_m_startaddress + 0x20, _m_startaddress + 0x23),
    D_SURF_STRIDE(_m_startaddress + 0x24, _m_startaddress + 0x27),
    D_DATAOUT_MAP(_m_startaddress + 0x28, _m_startaddress + 0x2b),
    D_CLIP_CFG(_m_startaddress + 0x2c, _m_startaddress + 0x2f),
    D_OUT_SATURATION(_m_startaddress + 0x30, _m_startaddress + 0x33),
    D_CYA(_m_startaddress + 0x34, _m_startaddress + 0x37) {
  m_children.push_back(&S_STATUS);
  m_children.push_back(&S_POINTER);
  m_children.push_back(&D_OP_ENABLE);
  m_children.push_back(&D_MISC_CFG);
  m_children.push_back(&D_DATAOUT_SIZE_0);
  m_children.push_back(&D_DATAOUT_SIZE_1);
  m_children.push_back(&D_DATAOUT_ADDR);
  m_children.push_back(&D_BATCH_NUMBER);
  m_children.push_back(&D_LINE_STRIDE);
  m_children.push_back(&D_SURF_STRIDE);
  m_children.push_back(&D_DATAOUT_MAP);
  m_children.push_back(&D_CLIP_CFG);
  m_children.push_back(&D_OUT_SATURATION);
  m_children.push_back(&D_CYA);
}

void  ordt_rset_NVDLA_CACC::update_child_ptrs() {
  m_children.clear();
  m_children.push_back(&S_STATUS);
  m_children.push_back(&S_POINTER);
  m_children.push_back(&D_OP_ENABLE);
  m_children.push_back(&D_MISC_CFG);
  m_children.push_back(&D_DATAOUT_SIZE_0);
  m_children.push_back(&D_DATAOUT_SIZE_1);
  m_children.push_back(&D_DATAOUT_ADDR);
  m_children.push_back(&D_BATCH_NUMBER);
  m_children.push_back(&D_LINE_STRIDE);
  m_children.push_back(&D_SURF_STRIDE);
  m_children.push_back(&D_DATAOUT_MAP);
  m_children.push_back(&D_CLIP_CFG);
  m_children.push_back(&D_OUT_SATURATION);
  m_children.push_back(&D_CYA);
}

// ------------------ ordt_root methods ------------------

ordt_root::ordt_root()
  : ordt_root(0x0, 0x7037) {
}

ordt_root::ordt_root(uint64_t _m_startaddress, uint64_t _m_endaddress)
  : ordt_regset(_m_startaddress, _m_endaddress),
    NVDLA_CACC(_m_startaddress + 0x7000, _m_startaddress + 0x703f) {
  m_children.push_back(&NVDLA_CACC);
}

void  ordt_root::update_child_ptrs() {
  m_children.clear();
  m_children.push_back(&NVDLA_CACC);
}

