// File Line: 51
// RVA: 0x14BEB0
void __fastcall UFG::Audio3D::SetId(UFG::Audio3D *this, const unsigned int id)
{
  __int64 v2; // rsi
  UFG::qArray<unsigned long,0> *v3; // rdi
  unsigned int v4; // ebp
  unsigned int v5; // edx
  unsigned int v6; // ebx
  unsigned int v7; // edx
  unsigned int *v8; // rax

  v2 = this->m_myIds.size;
  v3 = &this->m_myIds;
  v4 = id;
  v5 = this->m_myIds.capacity;
  v6 = v2 + 1;
  if ( (signed int)v2 + 1 > v5 )
  {
    if ( v5 )
      v7 = 2 * v5;
    else
      v7 = 1;
    for ( ; v7 < v6; v7 *= 2 )
      ;
    if ( v7 <= 4 )
      v7 = 4;
    if ( v7 - v6 > 0x10000 )
      v7 = v2 + 65537;
    UFG::qArray<long,0>::Reallocate(&this->m_myIds, v7, "Audio3D");
  }
  v8 = v3->p;
  v3->size = v6;
  v8[v2] = v4;
}

