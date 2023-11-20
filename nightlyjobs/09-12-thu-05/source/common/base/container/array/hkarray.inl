// File Line: 382
// RVA: 0x12F90C0
void __fastcall hkArrayBase<short>::_spliceInto(hkArrayBase<short> *this, hkMemoryAllocator *alloc, int index, int numdel, const __int16 *p, int numtoinsert)
{
  __int64 v6; // rdi
  __int64 v7; // rbp
  __int64 v8; // rbx
  int v9; // eax
  int v10; // esi
  int v11; // er15
  hkArrayBase<short> *v12; // r14
  int v13; // eax
  int v14; // er9
  signed __int64 v15; // rax
  char *v16; // rdx
  __int16 v17; // cx

  v6 = numtoinsert;
  v7 = numdel;
  v8 = index;
  v9 = this->m_capacityAndFlags & 0x3FFFFFFF;
  v10 = numtoinsert + this->m_size - numdel;
  v11 = this->m_size - index - numdel;
  v12 = this;
  if ( v10 > v9 && v9 < v10 )
  {
    v13 = 2 * v9;
    v14 = numtoinsert + this->m_size - numdel;
    if ( v10 < v13 )
      v14 = v13;
    hkArrayUtil::_reserve((hkResult *)&numtoinsert, alloc, this, v14, 2);
  }
  hkMemUtil::memMove(&v12->m_data[v6 + v8], &v12->m_data[v8 + v7], 2 * v11);
  v15 = (signed __int64)&v12->m_data[v8];
  if ( v6 > 0 )
  {
    v16 = (char *)p - v15;
    do
    {
      v17 = *(_WORD *)&v16[v15];
      v15 += 2i64;
      *(_WORD *)(v15 - 2) = v17;
      --v6;
    }
    while ( v6 );
  }
  v12->m_size = v10;
}

// File Line: 400
// RVA: 0xC7CDE0
void __fastcall hkArrayBase<hkStackTracer::CallTree::Node>::_insertAt(hkArrayBase<hkStackTracer::CallTree::Node> *this, hkMemoryAllocator *alloc, int index, hkStackTracer::CallTree::Node *p, int numtoinsert)
{
  hkArrayBase<hkStackTracer::CallTree::Node>::_spliceInto(this, alloc, index, 0, p, numtoinsert);
}

// File Line: 406
// RVA: 0xCE42E0
void __fastcall hkArrayBase<unsigned __int64>::_append(hkArrayBase<char *> *this, hkMemoryAllocator *alloc, char *const *a, int numtoinsert)
{
  __int64 v4; // r14
  int v5; // esi
  int v6; // eax
  char *const *v7; // rbx
  hkArrayBase<char *> *v8; // rdi
  int v9; // eax
  int v10; // er9
  __int64 v11; // rdx
  signed __int64 v12; // rax
  char *v13; // rbx
  __int64 v14; // rcx
  hkResult result; // [rsp+58h] [rbp+20h]

  v4 = numtoinsert;
  v5 = numtoinsert + this->m_size;
  v6 = this->m_capacityAndFlags & 0x3FFFFFFF;
  v7 = a;
  v8 = this;
  if ( v5 > v6 && v6 < v5 )
  {
    v9 = 2 * v6;
    v10 = numtoinsert + this->m_size;
    if ( v5 < v9 )
      v10 = v9;
    hkArrayUtil::_reserve(&result, alloc, this, v10, 8);
  }
  v11 = v4;
  v12 = (signed __int64)&v8->m_data[v8->m_size];
  if ( (signed int)v4 > 0 )
  {
    v13 = (char *)v7 - v12;
    do
    {
      v14 = *(_QWORD *)&v13[v12];
      v12 += 8i64;
      *(_QWORD *)(v12 - 8) = v14;
      --v11;
    }
    while ( v11 );
  }
  v8->m_size = v5;
}

// File Line: 436
// RVA: 0xD720D0
void __fastcall hkArrayBase<hkClass *>::_insertAt(hkArrayBase<hkClass *> *this, hkMemoryAllocator *alloc, int i, hkClass *const *t)
{
  hkArrayBase<hkpEntity *>::_insertAt((hkArrayBase<hkProcess *> *)this, alloc, i, (hkProcess *const *)t, 1);
}

// File Line: 590
// RVA: 0xCC56C0
void __fastcall hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *this, hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *a)
{
  hkRelocationInfo::Import *v2; // r8
  int v3; // eax
  int v4; // eax

  v2 = this->m_data;
  this->m_data = a->m_data;
  v3 = a->m_size;
  a->m_data = v2;
  LODWORD(v2) = this->m_size;
  this->m_size = v3;
  v4 = a->m_capacityAndFlags;
  a->m_size = (signed int)v2;
  LODWORD(v2) = this->m_capacityAndFlags;
  this->m_capacityAndFlags = v4;
  a->m_capacityAndFlags = (signed int)v2;
}

