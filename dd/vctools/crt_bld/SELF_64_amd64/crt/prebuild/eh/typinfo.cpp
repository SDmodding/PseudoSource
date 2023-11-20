// File Line: 72
// RVA: 0x12ADC70
bool __fastcall type_info::operator==(type_info *this, type_info *rhs)
{
  return strcmp(&rhs->_M_d_name[1], &this->_M_d_name[1]) == 0;
}

