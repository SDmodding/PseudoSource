// File Line: 62
// RVA: 0xA05D0
void __fastcall UFG::NativePackfileUtils::Fixups::AddFixup(
        UFG::NativePackfileUtils::Fixups *this,
        void *_addr,
        unsigned int _val0,
        unsigned int _val1)
{
  UFG::NativePackfileUtils::Fixup *v6; // rcx
  __int64 v7; // [rsp+28h] [rbp-10h]

  if ( _val0 != _val1 )
  {
    if ( _val0 )
    {
      LODWORD(v7) = _val0;
      if ( this->nonZeroFixups.m_size == (this->nonZeroFixups.m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, this, 16);
      v6 = &this->nonZeroFixups.m_data[this->nonZeroFixups.m_size];
      if ( v6 )
      {
        v6->addr = _addr;
        *(_QWORD *)&v6->val = v7;
      }
      ++this->nonZeroFixups.m_size;
    }
    else
    {
      if ( this->zeroFixups.m_size == (this->zeroFixups.m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &this->zeroFixups, 8);
      this->zeroFixups.m_data[this->zeroFixups.m_size++] = _addr;
    }
  }
}

