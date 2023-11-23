// File Line: 51
// RVA: 0x14BEB0
void __fastcall UFG::Audio3D::SetId(UFG::Audio3D *this, unsigned int id)
{
  __int64 size; // rsi
  UFG::qArray<unsigned long,0> *p_m_myIds; // rdi
  unsigned int capacity; // edx
  unsigned int v6; // ebx
  unsigned int v7; // edx
  unsigned int *p; // rax

  size = this->m_myIds.size;
  p_m_myIds = &this->m_myIds;
  capacity = this->m_myIds.capacity;
  v6 = size + 1;
  if ( (int)size + 1 > capacity )
  {
    if ( capacity )
      v7 = 2 * capacity;
    else
      v7 = 1;
    for ( ; v7 < v6; v7 *= 2 )
      ;
    if ( v7 <= 4 )
      v7 = 4;
    if ( v7 - v6 > 0x10000 )
      v7 = size + 65537;
    UFG::qArray<long,0>::Reallocate(&this->m_myIds, v7, "Audio3D");
  }
  p = p_m_myIds->p;
  p_m_myIds->size = v6;
  p[size] = id;
}

