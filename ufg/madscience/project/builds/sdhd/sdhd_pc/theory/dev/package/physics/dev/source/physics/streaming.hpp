// File Line: 62
// RVA: 0xA05D0
void __fastcall UFG::NativePackfileUtils::Fixups::AddFixup(UFG::NativePackfileUtils::Fixups *this, void *_addr, unsigned int _val0, unsigned int _val1)
{
  void *v4; // rdi
  UFG::NativePackfileUtils::Fixups *v5; // rbx
  UFG::NativePackfileUtils::Fixup *v6; // rcx
  __int64 v7; // [rsp+28h] [rbp-10h]

  if ( _val0 != _val1 )
  {
    v4 = _addr;
    v5 = this;
    if ( _val0 )
    {
      LODWORD(v7) = _val0;
      if ( this->nonZeroFixups.m_size == (this->nonZeroFixups.m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, this, 16);
      v6 = &v5->nonZeroFixups.m_data[v5->nonZeroFixups.m_size];
      if ( v6 )
      {
        v6->addr = v4;
        *(_QWORD *)&v6->val = v7;
      }
      ++v5->nonZeroFixups.m_size;
    }
    else
    {
      if ( this->zeroFixups.m_size == (this->zeroFixups.m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &this->zeroFixups, 8);
      v5->zeroFixups.m_data[v5->zeroFixups.m_size++] = v4;
    }
  }
}

