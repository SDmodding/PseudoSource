// File Line: 136
// RVA: 0x9A7EB0
void __fastcall Scaleform::Render::MatrixPoolImpl::EntryHandle::ReleaseHandle(
        Scaleform::Render::MatrixPoolImpl::EntryHandle *this)
{
  char *v2; // r8
  __int64 v3; // rcx
  __int64 v4; // rax
  bool v5; // zf

  v2 = (char *)((unsigned __int64)this & 0xFFFFFFFFFFFFF800ui64);
  if ( !*(_QWORD *)(((unsigned __int64)this & 0xFFFFFFFFFFFFF800ui64) + 0x18) )
  {
    *(_QWORD *)(*(_QWORD *)((unsigned __int64)this & 0xFFFFFFFFFFFFF800ui64) + 8i64) = *(_QWORD *)(((unsigned __int64)this & 0xFFFFFFFFFFFFF800ui64)
                                                                                                 + 8);
    **(_QWORD **)(((unsigned __int64)this & 0xFFFFFFFFFFFFF800ui64) + 8) = *(_QWORD *)v2;
    v3 = *(_QWORD *)(((unsigned __int64)this & 0xFFFFFFFFFFFFF800ui64) + 0x20);
    *(_QWORD *)v2 = -1i64;
    *((_QWORD *)v2 + 1) = -1i64;
    v4 = *(_QWORD *)(v3 + 40);
    v3 += 32i64;
    *((_QWORD *)v2 + 1) = v4;
    *(_QWORD *)v2 = v3;
    **(_QWORD **)(v3 + 8) = v2;
    *(_QWORD *)(v3 + 8) = v2;
  }
  this->pHeader = *(Scaleform::Render::MatrixPoolImpl::DataHeader **)(v2 + 24);
  v5 = (*((_DWORD *)v2 + 4))-- == 1;
  *((_QWORD *)v2 + 3) = this;
  if ( v5 )
  {
    *(_QWORD *)(*(_QWORD *)v2 + 8i64) = *((_QWORD *)v2 + 1);
    **((_QWORD **)v2 + 1) = *(_QWORD *)v2;
    *(_QWORD *)v2 = -1i64;
    *((_QWORD *)v2 + 1) = -1i64;
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v2);
  }
}

// File Line: 189
// RVA: 0x9CBBE0
bool __fastcall Scaleform::Render::MatrixPoolImpl::EntryHandleTable::allocEntryPage(
        Scaleform::Render::MatrixPoolImpl::EntryHandleTable *this)
{
  Scaleform::Render::MatrixPoolImpl::HandlePageBase *pPrev; // rax
  Scaleform::Render::MatrixPoolImpl::HandlePageBase *v3; // r8
  Scaleform::Render::MatrixPoolImpl::EntryHandle *v4; // rdx
  __int64 v5; // rcx
  Scaleform::Render::MatrixPoolImpl::EntryHandle **p_pFreeList; // rax

  pPrev = (Scaleform::Render::MatrixPoolImpl::HandlePageBase *)this->pHeap->vfptr->Alloc(
                                                                 this->pHeap,
                                                                 2032i64,
                                                                 2048i64,
                                                                 0i64);
  v3 = pPrev;
  if ( pPrev )
  {
    v4 = 0i64;
    pPrev->pTable = this;
    v5 = 249i64;
    pPrev->UseCount = 0;
    p_pFreeList = &pPrev[50].pFreeList;
    do
    {
      *p_pFreeList = v4;
      v4 = (Scaleform::Render::MatrixPoolImpl::EntryHandle *)p_pFreeList--;
      --v5;
    }
    while ( v5 );
    v3->pFreeList = v4;
    pPrev = this->PartiallyFreePages.Root.pPrev;
    v3->pNext = (Scaleform::Render::MatrixPoolImpl::HandlePageBase *)&this->PartiallyFreePages;
    v3->pPrev = pPrev;
    this->PartiallyFreePages.Root.pPrev->pNext = v3;
    this->PartiallyFreePages.Root.pPrev = v3;
    LOBYTE(pPrev) = 1;
  }
  return (char)pPrev;
}

// File Line: 211
// RVA: 0x957AB0
Scaleform::Render::MatrixPoolImpl::EntryHandle *__fastcall Scaleform::Render::MatrixPoolImpl::EntryHandleTable::AllocEntry(
        Scaleform::Render::MatrixPoolImpl::EntryHandleTable *this,
        Scaleform::Render::MatrixPoolImpl::DataHeader *header)
{
  Scaleform::Render::MatrixPoolImpl::HandlePageBase *pNext; // r8
  Scaleform::Render::MatrixPoolImpl::EntryHandle *pFreeList; // r9
  Scaleform::Render::MatrixPoolImpl::EntryHandle *pHeader; // rax

  if ( (Scaleform::List<Scaleform::Render::MatrixPoolImpl::HandlePage,Scaleform::Render::MatrixPoolImpl::HandlePageBase> *)this->PartiallyFreePages.Root.pNext == &this->PartiallyFreePages
    && !Scaleform::Render::MatrixPoolImpl::EntryHandleTable::allocEntryPage(this) )
  {
    return 0i64;
  }
  pNext = this->PartiallyFreePages.Root.pNext;
  pFreeList = pNext->pFreeList;
  pHeader = (Scaleform::Render::MatrixPoolImpl::EntryHandle *)pFreeList->pHeader;
  ++pNext->UseCount;
  pNext->pFreeList = pHeader;
  if ( !pFreeList->pHeader )
  {
    pNext->pPrev->pNext = pNext->pNext;
    pNext->pNext->Scaleform::ListNode<Scaleform::Render::MatrixPoolImpl::HandlePageBase>::$2F49CB2E8DD4080EF3ED0AEB2BBF906C::pPrev = pNext->pPrev;
    pNext->pPrev = (Scaleform::Render::MatrixPoolImpl::HandlePageBase *)-1i64;
    pNext->pNext = (Scaleform::Render::MatrixPoolImpl::HandlePageBase *)-1i64;
    pNext->pPrev = this->FullPages.Root.pPrev;
    pNext->pNext = (Scaleform::Render::MatrixPoolImpl::HandlePageBase *)&this->FullPages;
    this->FullPages.Root.pPrev->pNext = pNext;
    this->FullPages.Root.pPrev = pNext;
  }
  pFreeList->pHeader = header;
  return pFreeList;
}

// File Line: 310
// RVA: 0x159CD50
char *Scaleform::Render::MatrixPoolImpl::_dynamic_initializer_for__HMatrix_DefaultMatrixData__()
{
  char *result; // rax

  result = &Scaleform::Render::MatrixPoolImpl::HMatrix_DefaultMatrixData.DataBytes[16];
  *(Scaleform::Render::Matrix2x4<float> *)&Scaleform::Render::MatrixPoolImpl::HMatrix_DefaultMatrixData.DataBytes[16 * (unsigned __int8)Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[0].Offsets[4] + 16] = Scaleform::Render::Matrix2x4<float>::Identity;
  return result;
}

// File Line: 315
// RVA: 0x9B1750
void __fastcall Scaleform::Render::MatrixPoolImpl::HMatrix::SetMatrix2D(
        Scaleform::Render::MatrixPoolImpl::HMatrix *this,
        Scaleform::Render::Matrix2x4<float> *m)
{
  Scaleform::Render::MatrixPoolImpl::EntryHandle *pHandle; // rdi
  char Format; // si
  int v6; // xmm1_4
  int v7; // xmm0_4
  int v8; // xmm1_4
  int v9; // xmm0_4
  int v10; // xmm1_4
  Scaleform::Render::MatrixPoolImpl::DataHeader *pHeader; // r8
  int v12; // ecx
  int Buf1[8]; // [rsp+20h] [rbp-38h] BYREF
  __m128 v14; // [rsp+40h] [rbp-18h]

  pHandle = this->pHandle;
  Format = this->pHandle->pHeader->Format;
  if ( (Format & 0x10) != 0 )
  {
    v6 = LODWORD(m->M[0][1]);
    Buf1[0] = LODWORD(m->M[0][0]);
    v7 = LODWORD(m->M[0][2]);
    Buf1[1] = v6;
    v8 = LODWORD(m->M[0][3]);
    Buf1[2] = v7;
    Buf1[4] = LODWORD(m->M[1][0]);
    v9 = LODWORD(m->M[1][2]);
    Buf1[3] = v8;
    v10 = LODWORD(m->M[1][1]);
    Buf1[6] = v9;
    v14 = _xmm;
    Buf1[5] = v10;
    Buf1[7] = LODWORD(m->M[1][3]);
    if ( !memcmp(Buf1, &Scaleform::Render::Matrix3x4<float>::Identity, 0x30ui64) )
      return;
    Scaleform::Render::MatrixPoolImpl::MatrixPool::reallocMatrixData(
      *(Scaleform::Render::MatrixPoolImpl::MatrixPool **)(*(_QWORD *)(((unsigned __int64)pHandle & 0xFFFFFFFFFFFFF800ui64)
                                                                    + 0x20)
                                                        + 8i64),
      pHandle,
      Format & 0xEF);
  }
  pHeader = this->pHandle->pHeader;
  v12 = (unsigned __int8)Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[pHeader->Format & 0xF].Offsets[4];
  *(float *)&pHeader[v12 + 1].pHandle = m->M[0][0];
  HIDWORD(pHeader[v12 + 1].pHandle) = LODWORD(m->M[0][1]);
  pHeader[v12 + 1].RefCount = LODWORD(m->M[0][2]);
  *(float *)&pHeader[v12 + 1].DataPageOffset = m->M[0][3];
  *(float *)&pHeader[v12 + 2].pHandle = m->M[1][0];
  HIDWORD(pHeader[v12 + 2].pHandle) = LODWORD(m->M[1][1]);
  pHeader[v12 + 2].RefCount = LODWORD(m->M[1][2]);
  *(float *)&pHeader[v12 + 2].DataPageOffset = m->M[1][3];
}

// File Line: 327
// RVA: 0x9B18A0
void __fastcall Scaleform::Render::MatrixPoolImpl::HMatrix::SetMatrix3D(
        Scaleform::Render::MatrixPoolImpl::HMatrix *this,
        Scaleform::Render::Matrix3x4<float> *m)
{
  Scaleform::Render::MatrixPoolImpl::EntryHandle *pHandle; // rdi
  unsigned __int8 Format; // si
  float *v6; // rcx

  pHandle = this->pHandle;
  Format = this->pHandle->pHeader->Format;
  if ( (Format & 0x10) == 0 )
  {
    if ( !memcmp(m, &Scaleform::Render::Matrix3x4<float>::Identity, 0x30ui64) )
      return;
    Scaleform::Render::MatrixPoolImpl::MatrixPool::reallocMatrixData(
      *(Scaleform::Render::MatrixPoolImpl::MatrixPool **)(*(_QWORD *)(((unsigned __int64)pHandle & 0xFFFFFFFFFFFFF800ui64)
                                                                    + 0x20)
                                                        + 8i64),
      pHandle,
      Format | 0x10);
  }
  v6 = (float *)&this->pHandle->pHeader[(unsigned __int8)Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[this->pHandle->pHeader->Format & 0xF].Offsets[4]];
  v6[4] = m->M[0][0];
  v6[5] = m->M[0][1];
  v6[6] = m->M[0][2];
  v6[7] = m->M[0][3];
  v6[8] = m->M[1][0];
  v6[9] = m->M[1][1];
  v6[10] = m->M[1][2];
  v6[11] = m->M[1][3];
  v6[12] = m->M[2][0];
  v6[13] = m->M[2][1];
  v6[14] = m->M[2][2];
  v6[15] = m->M[2][3];
}

// File Line: 339
// RVA: 0x9AECE0
void __fastcall Scaleform::Render::MatrixPoolImpl::HMatrix::SetCxform(
        Scaleform::Render::MatrixPoolImpl::HMatrix *this,
        Scaleform::Render::Cxform *m)
{
  Scaleform::Render::MatrixPoolImpl::DataHeader *pHeader; // rax
  Scaleform::Render::MatrixPoolImpl::DataHeader *v5; // rdx
  __int64 v6; // rcx

  pHeader = this->pHandle->pHeader;
  if ( (pHeader->Format & 1) != 0 )
    goto LABEL_11;
  if ( Scaleform::Render::Cxform::Identity.M[0][0] != m->M[0][0]
    || Scaleform::Render::Cxform::Identity.M[0][1] != m->M[0][1]
    || Scaleform::Render::Cxform::Identity.M[0][2] != m->M[0][2]
    || Scaleform::Render::Cxform::Identity.M[0][3] != m->M[0][3]
    || Scaleform::Render::Cxform::Identity.M[1][0] != m->M[1][0]
    || Scaleform::Render::Cxform::Identity.M[1][1] != m->M[1][1]
    || Scaleform::Render::Cxform::Identity.M[1][2] != m->M[1][2]
    || Scaleform::Render::Cxform::Identity.M[1][3] != m->M[1][3] )
  {
    Scaleform::Render::MatrixPoolImpl::MatrixPool::reallocMatrixData(
      *(Scaleform::Render::MatrixPoolImpl::MatrixPool **)(*(_QWORD *)(((unsigned __int64)this->pHandle & 0xFFFFFFFFFFFFF800ui64)
                                                                    + 0x20)
                                                        + 8i64),
      this->pHandle,
      (unsigned __int8)pHeader->Format | 1);
LABEL_11:
    v5 = this->pHandle->pHeader;
    v6 = (unsigned __int8)Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[v5->Format & 0xF].Offsets[0]
       + 1i64;
    v5[v6] = *(Scaleform::Render::MatrixPoolImpl::DataHeader *)&m->M[0][0];
    v5[v6 + 1] = *(Scaleform::Render::MatrixPoolImpl::DataHeader *)&m->M[1][0];
  }
}

// File Line: 351
// RVA: 0x9B4C30
void __fastcall Scaleform::Render::MatrixPoolImpl::HMatrix::SetTextureMatrix(
        Scaleform::Render::MatrixPoolImpl::HMatrix *this,
        Scaleform::Render::Matrix2x4<float> *m,
        unsigned int index)
{
  Scaleform::Render::MatrixPoolImpl::EntryHandle *pHandle; // rdi
  int v4; // ebp
  int v6; // ebx
  Scaleform::Render::MatrixPoolImpl::DataHeader *pHeader; // rdx
  __int64 v9; // rcx

  pHandle = this->pHandle;
  v4 = index + 1;
  v6 = 1 << (index + 1);
  if ( ((unsigned __int8)v6 & this->pHandle->pHeader->Format) == 0 )
  {
    if ( !memcmp(m, &Scaleform::Render::Matrix2x4<float>::Identity, 0x20ui64) )
      return;
    Scaleform::Render::MatrixPoolImpl::MatrixPool::reallocMatrixData(
      *(Scaleform::Render::MatrixPoolImpl::MatrixPool **)(*(_QWORD *)(((unsigned __int64)pHandle & 0xFFFFFFFFFFFFF800ui64)
                                                                    + 0x20)
                                                        + 8i64),
      pHandle,
      v6 | (unsigned __int8)pHandle->pHeader->Format);
  }
  pHeader = this->pHandle->pHeader;
  v9 = (unsigned __int8)Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[pHeader->Format & 0xF].Offsets[v4];
  *(float *)&pHeader[v9 + 1].pHandle = m->M[0][0];
  HIDWORD(pHeader[v9 + 1].pHandle) = LODWORD(m->M[0][1]);
  pHeader[v9 + 1].RefCount = LODWORD(m->M[0][2]);
  *(float *)&pHeader[v9 + 1].DataPageOffset = m->M[0][3];
  *(float *)&pHeader[v9 + 2].pHandle = m->M[1][0];
  HIDWORD(pHeader[v9 + 2].pHandle) = LODWORD(m->M[1][1]);
  pHeader[v9 + 2].RefCount = LODWORD(m->M[1][2]);
  *(float *)&pHeader[v9 + 2].DataPageOffset = m->M[1][3];
}

// File Line: 364
// RVA: 0x9B52C0
void __fastcall Scaleform::Render::MatrixPoolImpl::HMatrix::SetUserData(
        Scaleform::Render::MatrixPoolImpl::HMatrix *this,
        const void *data,
        size_t size)
{
  Scaleform::Render::MatrixPoolImpl::DataHeader *pHeader; // rax
  Scaleform::Render::MatrixPoolImpl::DataHeader *v7; // rcx

  pHeader = this->pHandle->pHeader;
  if ( (pHeader->Format & 8) == 0 )
  {
    if ( !data )
      return;
    Scaleform::Render::MatrixPoolImpl::MatrixPool::reallocMatrixData(
      *(Scaleform::Render::MatrixPoolImpl::MatrixPool **)(*(_QWORD *)(((unsigned __int64)this->pHandle & 0xFFFFFFFFFFFFF800ui64)
                                                                    + 0x20)
                                                        + 8i64),
      this->pHandle,
      (unsigned __int8)pHeader->Format | 8);
  }
  v7 = &this->pHandle->pHeader[(unsigned __int8)Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[this->pHandle->pHeader->Format & 0xF].Offsets[3]
                             + 1];
  if ( data )
    memmove(v7, data, size);
  else
    memset(v7, 0, size);
}

// File Line: 384
// RVA: 0x94DFB0
void __fastcall Scaleform::Render::MatrixPoolImpl::HMatrix::operator=(
        Scaleform::Render::MatrixPoolImpl::HMatrix *this,
        Scaleform::Render::MatrixPoolImpl::HMatrix *other)
{
  Scaleform::Render::MatrixPoolImpl::DataHeader *pHeader; // rbx
  bool v5; // zf
  __int64 DataPageOffset; // rcx

  if ( other->pHandle != &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle )
    ++other->pHandle->pHeader->RefCount;
  if ( this->pHandle == &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle
    || (pHeader = this->pHandle->pHeader, v5 = pHeader->RefCount == 1, --pHeader->RefCount, !v5) )
  {
    this->pHandle = other->pHandle;
  }
  else
  {
    DataPageOffset = pHeader->DataPageOffset;
    *(_WORD *)((char *)&pHeader[1].RefCount + DataPageOffset + 2) += 16 * (unsigned __int8)pHeader->UnitSize;
    (*(Scaleform::Render::MatrixPoolImpl::EntryHandle **)((char *)&pHeader[1].pHandle + DataPageOffset))[5].pHeader += (unsigned __int8)pHeader->UnitSize;
    Scaleform::Render::MatrixPoolImpl::EntryHandle::ReleaseHandle(pHeader->pHandle);
    pHeader->pHandle = 0i64;
    this->pHandle = other->pHandle;
  }
}

// File Line: 405
// RVA: 0x94B3A0
void __fastcall Scaleform::Render::MatrixPoolImpl::MatrixPool::~MatrixPool(
        Scaleform::Render::MatrixPoolImpl::MatrixPool *this)
{
  Scaleform::List<Scaleform::Render::MatrixPoolImpl::DataPage,Scaleform::Render::MatrixPoolImpl::DataPage> *p_DataPages; // rsi
  Scaleform::Render::MatrixPoolImpl::DataPage *pNext; // rdi

  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::MatrixPoolImpl::MatrixPool::`vftable;
  p_DataPages = &this->DataPages;
  if ( (Scaleform::List<Scaleform::Render::MatrixPoolImpl::DataPage,Scaleform::Render::MatrixPoolImpl::DataPage> *)this->DataPages.Root.pNext != &this->DataPages )
  {
    do
    {
      pNext = this->DataPages.Root.pNext;
      pNext->pPrev->pNext = pNext->pNext;
      pNext->pNext->Scaleform::ListNode<Scaleform::Render::MatrixPoolImpl::DataPage>::$E5F2B3BA179E0486073CE4F8756635B8::pPrev = pNext->pPrev;
      pNext->pPrev = (Scaleform::Render::MatrixPoolImpl::DataPage *)-1i64;
      pNext->pNext = (Scaleform::Render::MatrixPoolImpl::DataPage *)-1i64;
      this->AllocatedSpace -= 4064i64;
      --this->DataPageCount;
      if ( this->pLastFreedPage )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      this->pLastFreedPage = pNext;
    }
    while ( (Scaleform::List<Scaleform::Render::MatrixPoolImpl::DataPage,Scaleform::Render::MatrixPoolImpl::DataPage> *)p_DataPages->Root.pNext != p_DataPages );
  }
  if ( this->pLastFreedPage )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
}

// File Line: 419
// RVA: 0x9DD420
Scaleform::Render::MatrixPoolImpl::EntryHandle *__fastcall Scaleform::Render::MatrixPoolImpl::MatrixPool::createMatrixHelper(
        Scaleform::Render::MatrixPoolImpl::MatrixPool *this,
        Scaleform::Render::Matrix2x4<float> *m,
        Scaleform::Render::Cxform *cx,
        char formatBits)
{
  Scaleform::Render::MatrixPoolImpl::EntryHandle *v7; // rax
  Scaleform::Render::MatrixPoolImpl::EntryHandle *v8; // r10
  Scaleform::Render::MatrixPoolImpl::DataHeader *pHeader; // r9
  __int64 v10; // rdx
  __int64 v11; // rcx
  Scaleform::Render::MatrixPoolImpl::DataHeader *v12; // rdx
  int v13; // eax
  Scaleform::Render::MatrixPoolImpl::DataHeader *v14; // rdx
  int v15; // eax
  Scaleform::Render::MatrixPoolImpl::DataHeader *v16; // rdx
  __int64 v17; // rcx

  v7 = Scaleform::Render::MatrixPoolImpl::MatrixPool::allocMatrixData(this, formatBits);
  v8 = v7;
  if ( !v7 )
    return &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle;
  pHeader = v7->pHeader;
  v10 = (unsigned __int8)Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[v7->pHeader->Format & 0xF].Offsets[4];
  *(float *)&pHeader[v10 + 1].pHandle = m->M[0][0];
  HIDWORD(pHeader[v10 + 1].pHandle) = LODWORD(m->M[0][1]);
  pHeader[v10 + 1].RefCount = LODWORD(m->M[0][2]);
  *(float *)&pHeader[v10 + 1].DataPageOffset = m->M[0][3];
  *(float *)&pHeader[v10 + 2].pHandle = m->M[1][0];
  HIDWORD(pHeader[v10 + 2].pHandle) = LODWORD(m->M[1][1]);
  pHeader[v10 + 2].RefCount = LODWORD(m->M[1][2]);
  *(float *)&pHeader[v10 + 2].DataPageOffset = m->M[1][3];
  if ( (formatBits & 1) != 0 )
  {
    v11 = (unsigned __int8)Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[pHeader->Format & 0xF].Offsets[0]
        + 1i64;
    pHeader[v11] = *(Scaleform::Render::MatrixPoolImpl::DataHeader *)&cx->M[0][0];
    pHeader[v11 + 1] = *(Scaleform::Render::MatrixPoolImpl::DataHeader *)&cx->M[1][0];
  }
  if ( (formatBits & 2) != 0 )
  {
    v12 = v7->pHeader;
    v13 = (unsigned __int8)Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[v7->pHeader->Format & 0xF].Offsets[1];
    v12[v13 + 1].pHandle = (Scaleform::Render::MatrixPoolImpl::EntryHandle *)1065353216;
    *(_QWORD *)&v12[v13 + 1].RefCount = 0i64;
    LODWORD(v12[v13 + 2].pHandle) = 0;
    *(Scaleform::Render::MatrixPoolImpl::EntryHandle **)((char *)&v12[v13 + 2].pHandle + 4) = (Scaleform::Render::MatrixPoolImpl::EntryHandle *)1065353216;
    *(_DWORD *)&v12[v13 + 2].DataPageOffset = 0;
  }
  if ( (formatBits & 4) != 0 )
  {
    v14 = v8->pHeader;
    v15 = (unsigned __int8)Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[v8->pHeader->Format & 0xF].Offsets[2];
    v14[v15 + 1].pHandle = (Scaleform::Render::MatrixPoolImpl::EntryHandle *)1065353216;
    *(_QWORD *)&v14[v15 + 1].RefCount = 0i64;
    LODWORD(v14[v15 + 2].pHandle) = 0;
    *(Scaleform::Render::MatrixPoolImpl::EntryHandle **)((char *)&v14[v15 + 2].pHandle + 4) = (Scaleform::Render::MatrixPoolImpl::EntryHandle *)1065353216;
    *(_DWORD *)&v14[v15 + 2].DataPageOffset = 0;
  }
  if ( (formatBits & 8) != 0 )
  {
    v16 = v8->pHeader;
    v17 = (unsigned __int8)Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[v8->pHeader->Format & 0xF].Offsets[3];
    v16[v17 + 1].pHandle = 0i64;
    *(_QWORD *)&v16[v17 + 1].RefCount = 0i64;
    v16[v17 + 2].pHandle = 0i64;
    *(_QWORD *)&v16[v17 + 2].RefCount = 0i64;
    v16[v17 + 3].pHandle = 0i64;
    *(_QWORD *)&v16[v17 + 3].RefCount = 0i64;
    v16[v17 + 4].pHandle = 0i64;
    *(_QWORD *)&v16[v17 + 4].RefCount = 0i64;
  }
  return v8;
}

// File Line: 444
// RVA: 0x9DD5E0
Scaleform::Render::MatrixPoolImpl::EntryHandle *__fastcall Scaleform::Render::MatrixPoolImpl::MatrixPool::createMatrixHelper(
        Scaleform::Render::MatrixPoolImpl::MatrixPool *this,
        Scaleform::Render::Matrix3x4<float> *m,
        Scaleform::Render::Cxform *cx,
        char formatBits)
{
  Scaleform::Render::MatrixPoolImpl::EntryHandle *v7; // rax
  Scaleform::Render::MatrixPoolImpl::EntryHandle *v8; // r11
  Scaleform::Render::MatrixPoolImpl::DataHeader *pHeader; // r10
  __int64 v10; // rdx
  Scaleform::Render::MatrixPoolImpl::DataHeader *v11; // rdx
  __int64 v12; // rcx
  Scaleform::Render::MatrixPoolImpl::DataHeader *v13; // rdx
  int v14; // eax
  Scaleform::Render::MatrixPoolImpl::DataHeader *v15; // rdx
  int v16; // eax
  Scaleform::Render::MatrixPoolImpl::DataHeader *v17; // rdx
  __int64 v18; // rcx

  v7 = Scaleform::Render::MatrixPoolImpl::MatrixPool::allocMatrixData(this, formatBits);
  v8 = v7;
  if ( !v7 )
    return &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle;
  pHeader = v7->pHeader;
  v10 = (unsigned __int8)Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[v7->pHeader->Format & 0xF].Offsets[4];
  *(float *)&pHeader[v10 + 1].pHandle = m->M[0][0];
  HIDWORD(pHeader[v10 + 1].pHandle) = LODWORD(m->M[0][1]);
  pHeader[v10 + 1].RefCount = LODWORD(m->M[0][2]);
  *(float *)&pHeader[v10 + 1].DataPageOffset = m->M[0][3];
  *(float *)&pHeader[v10 + 2].pHandle = m->M[1][0];
  HIDWORD(pHeader[v10 + 2].pHandle) = LODWORD(m->M[1][1]);
  pHeader[v10 + 2].RefCount = LODWORD(m->M[1][2]);
  *(float *)&pHeader[v10 + 2].DataPageOffset = m->M[1][3];
  *(float *)&pHeader[v10 + 3].pHandle = m->M[2][0];
  HIDWORD(pHeader[v10 + 3].pHandle) = LODWORD(m->M[2][1]);
  pHeader[v10 + 3].RefCount = LODWORD(m->M[2][2]);
  *(float *)&pHeader[v10 + 3].DataPageOffset = m->M[2][3];
  if ( (formatBits & 1) != 0 )
  {
    v11 = v7->pHeader;
    v12 = (unsigned __int8)Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[v7->pHeader->Format & 0xF].Offsets[0]
        + 1i64;
    v11[v12] = *(Scaleform::Render::MatrixPoolImpl::DataHeader *)&cx->M[0][0];
    v11[v12 + 1] = *(Scaleform::Render::MatrixPoolImpl::DataHeader *)&cx->M[1][0];
  }
  if ( (formatBits & 2) != 0 )
  {
    v13 = v7->pHeader;
    v14 = (unsigned __int8)Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[v7->pHeader->Format & 0xF].Offsets[1];
    v13[v14 + 1].pHandle = (Scaleform::Render::MatrixPoolImpl::EntryHandle *)1065353216;
    *(_QWORD *)&v13[v14 + 1].RefCount = 0i64;
    LODWORD(v13[v14 + 2].pHandle) = 0;
    *(Scaleform::Render::MatrixPoolImpl::EntryHandle **)((char *)&v13[v14 + 2].pHandle + 4) = (Scaleform::Render::MatrixPoolImpl::EntryHandle *)1065353216;
    *(_DWORD *)&v13[v14 + 2].DataPageOffset = 0;
  }
  if ( (formatBits & 4) != 0 )
  {
    v15 = v8->pHeader;
    v16 = (unsigned __int8)Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[v8->pHeader->Format & 0xF].Offsets[2];
    v15[v16 + 1].pHandle = (Scaleform::Render::MatrixPoolImpl::EntryHandle *)1065353216;
    *(_QWORD *)&v15[v16 + 1].RefCount = 0i64;
    LODWORD(v15[v16 + 2].pHandle) = 0;
    *(Scaleform::Render::MatrixPoolImpl::EntryHandle **)((char *)&v15[v16 + 2].pHandle + 4) = (Scaleform::Render::MatrixPoolImpl::EntryHandle *)1065353216;
    *(_DWORD *)&v15[v16 + 2].DataPageOffset = 0;
  }
  if ( (formatBits & 8) != 0 )
  {
    v17 = v8->pHeader;
    v18 = (unsigned __int8)Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[v8->pHeader->Format & 0xF].Offsets[3];
    v17[v18 + 1].pHandle = 0i64;
    *(_QWORD *)&v17[v18 + 1].RefCount = 0i64;
    v17[v18 + 2].pHandle = 0i64;
    *(_QWORD *)&v17[v18 + 2].RefCount = 0i64;
    v17[v18 + 3].pHandle = 0i64;
    *(_QWORD *)&v17[v18 + 3].RefCount = 0i64;
    v17[v18 + 4].pHandle = 0i64;
    *(_QWORD *)&v17[v18 + 4].RefCount = 0i64;
  }
  return v8;
}

// File Line: 471
// RVA: 0x967B70
Scaleform::Render::MatrixPoolImpl::HMatrix *__fastcall Scaleform::Render::MatrixPoolImpl::MatrixPool::CreateMatrix(
        Scaleform::Render::MatrixPoolImpl::MatrixPool *this,
        Scaleform::Render::MatrixPoolImpl::HMatrix *result,
        Scaleform::Render::Matrix2x4<float> *m,
        unsigned int formatBits)
{
  result->pHandle = Scaleform::Render::MatrixPoolImpl::MatrixPool::createMatrixHelper(
                      this,
                      m,
                      &Scaleform::Render::Cxform::Identity,
                      formatBits);
  return result;
}

// File Line: 475
// RVA: 0x967C10
Scaleform::Render::MatrixPoolImpl::HMatrix *__fastcall Scaleform::Render::MatrixPoolImpl::MatrixPool::CreateMatrix(
        Scaleform::Render::MatrixPoolImpl::MatrixPool *this,
        Scaleform::Render::MatrixPoolImpl::HMatrix *result,
        Scaleform::Render::Matrix3x4<float> *m,
        unsigned int formatBits)
{
  result->pHandle = Scaleform::Render::MatrixPoolImpl::MatrixPool::createMatrixHelper(
                      this,
                      m,
                      &Scaleform::Render::Cxform::Identity,
                      formatBits);
  return result;
}

// File Line: 479
// RVA: 0x967B20
Scaleform::Render::MatrixPoolImpl::HMatrix *__fastcall Scaleform::Render::MatrixPoolImpl::MatrixPool::CreateMatrix(
        Scaleform::Render::MatrixPoolImpl::MatrixPool *this,
        Scaleform::Render::MatrixPoolImpl::HMatrix *result,
        Scaleform::Render::Matrix2x4<float> *m,
        Scaleform::Render::Cxform *cx,
        unsigned int formatBits)
{
  result->pHandle = Scaleform::Render::MatrixPoolImpl::MatrixPool::createMatrixHelper(this, m, cx, formatBits);
  return result;
}

// File Line: 483
// RVA: 0x967BC0
Scaleform::Render::MatrixPoolImpl::HMatrix *__fastcall Scaleform::Render::MatrixPoolImpl::MatrixPool::CreateMatrix(
        Scaleform::Render::MatrixPoolImpl::MatrixPool *this,
        Scaleform::Render::MatrixPoolImpl::HMatrix *result,
        Scaleform::Render::Matrix3x4<float> *m,
        Scaleform::Render::Cxform *cx,
        unsigned int formatBits)
{
  result->pHandle = Scaleform::Render::MatrixPoolImpl::MatrixPool::createMatrixHelper(this, m, cx, formatBits);
  return result;
}

// File Line: 511
// RVA: 0x9CB9F0
bool __fastcall Scaleform::Render::MatrixPoolImpl::MatrixPool::allocDataPage(
        Scaleform::Render::MatrixPoolImpl::MatrixPool *this)
{
  Scaleform::Render::MatrixPoolImpl::DataPage *pLastFreedPage; // rdx
  Scaleform::Render::MatrixPoolImpl::DataPage *pPrev; // rax

  pLastFreedPage = this->pLastFreedPage;
  if ( pLastFreedPage )
  {
    this->pLastFreedPage = 0i64;
  }
  else
  {
    pPrev = (Scaleform::Render::MatrixPoolImpl::DataPage *)this->pHeap->vfptr->Alloc(this->pHeap, 4096i64, 16i64, 0i64);
    pLastFreedPage = pPrev;
    if ( !pPrev )
      return (char)pPrev;
  }
  pLastFreedPage->pPool = this;
  *(_DWORD *)&pLastFreedPage->FreeTail = 4064;
  pPrev = this->DataPages.Root.pPrev;
  pLastFreedPage->pNext = (Scaleform::Render::MatrixPoolImpl::DataPage *)&this->DataPages;
  pLastFreedPage->pPrev = pPrev;
  this->DataPages.Root.pPrev->pNext = pLastFreedPage;
  this->DataPages.Root.pPrev = pLastFreedPage;
  this->AllocatedSpace += 4064i64;
  ++this->DataPageCount;
  this->pAllocPage = pLastFreedPage;
  LOBYTE(pPrev) = 1;
  return (char)pPrev;
}

// File Line: 546
// RVA: 0x9E1D70
bool __fastcall Scaleform::Render::MatrixPoolImpl::MatrixPool::ensureAllocSpace(
        Scaleform::Render::MatrixPoolImpl::MatrixPool *this,
        unsigned __int64 size)
{
  Scaleform::List<Scaleform::Render::MatrixPoolImpl::DataPage,Scaleform::Render::MatrixPoolImpl::DataPage> *p_DataPages; // rax
  Scaleform::Render::MatrixPoolImpl::DataPage *pPrev; // rcx
  Scaleform::Render::MatrixPoolImpl::DataPage *pSqueezePage; // rdx
  Scaleform::Render::MatrixPoolImpl::DataPage *pAllocPage; // rax

  p_DataPages = &this->DataPages;
  pPrev = this->DataPages.Root.pPrev;
  if ( this->pAllocPage != pPrev
    && (Scaleform::List<Scaleform::Render::MatrixPoolImpl::DataPage,Scaleform::Render::MatrixPoolImpl::DataPage> *)p_DataPages->Root.pNext != p_DataPages )
  {
    this->pAllocPage = pPrev;
    if ( pPrev->FreeTail >= size )
      return 1;
  }
  if ( this->FreedSpace >= (3 * this->AllocatedSpace) >> 5 )
  {
    pSqueezePage = this->pSqueezePage;
    if ( !pSqueezePage
      || !Scaleform::Render::MatrixPoolImpl::MatrixPool::squeezeMemoryRange(
            this,
            pSqueezePage,
            this->DataPages.Root.pNext->pPrev,
            Squeeze_Incremental) )
    {
      Scaleform::Render::MatrixPoolImpl::MatrixPool::squeezeMemoryRange(
        this,
        this->DataPages.Root.pNext,
        this->DataPages.Root.pNext->pPrev,
        Squeeze_Incremental);
    }
  }
  pAllocPage = this->pAllocPage;
  return pAllocPage && pAllocPage->FreeTail >= size
      || Scaleform::Render::MatrixPoolImpl::MatrixPool::allocDataPage(this);
}

// File Line: 566
// RVA: 0x9CB890
Scaleform::Render::MatrixPoolImpl::DataHeader *__fastcall Scaleform::Render::MatrixPoolImpl::MatrixPool::allocData(
        Scaleform::Render::MatrixPoolImpl::MatrixPool *this,
        unsigned __int64 size,
        Scaleform::Render::MatrixPoolImpl::EntryHandle *handle)
{
  Scaleform::Render::MatrixPoolImpl::DataPage *pAllocPage; // rax
  unsigned __int64 v7; // rdi
  Scaleform::Render::MatrixPoolImpl::DataHeader *result; // rax
  Scaleform::Render::MatrixPoolImpl::DataPage *v9; // rcx

  pAllocPage = this->pAllocPage;
  v7 = size + 16;
  if ( (!pAllocPage || pAllocPage->FreeTail < v7)
    && !Scaleform::Render::MatrixPoolImpl::MatrixPool::ensureAllocSpace(this, size + 16) )
  {
    return 0i64;
  }
  v9 = this->pAllocPage;
  result = (Scaleform::Render::MatrixPoolImpl::DataHeader *)((char *)&v9[128] - v9->FreeTail);
  result->DataPageOffset = (_WORD)v9 - (_WORD)result;
  result->pHandle = handle;
  result->RefCount = 1;
  result->UnitSize = (size >> 4) + 1;
  result->Format = 0;
  v9->FreeTail -= v7;
  return result;
}

// File Line: 587
// RVA: 0x9CBEB0
Scaleform::Render::MatrixPoolImpl::EntryHandle *__fastcall Scaleform::Render::MatrixPoolImpl::MatrixPool::allocMatrixData(
        Scaleform::Render::MatrixPoolImpl::MatrixPool *this,
        char formatBits)
{
  int v4; // ebp
  Scaleform::Render::MatrixPoolImpl::EntryHandle *v5; // rax
  Scaleform::Render::MatrixPoolImpl::EntryHandle *v6; // rbx
  Scaleform::Render::MatrixPoolImpl::DataHeader *v7; // rax

  v4 = (unsigned __int8)Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[formatBits & 0xF].Offsets[4];
  v5 = Scaleform::Render::MatrixPoolImpl::EntryHandleTable::AllocEntry(&this->HandleTable, 0i64);
  v6 = v5;
  if ( !v5 )
    return 0i64;
  v7 = Scaleform::Render::MatrixPoolImpl::MatrixPool::allocData(
         this,
         16 * (v4 + ((formatBits & 0x10 | 0x20u) >> 4)),
         v5);
  v6->pHeader = v7;
  if ( !v7 )
  {
    Scaleform::Render::MatrixPoolImpl::EntryHandle::ReleaseHandle(v6);
    return 0i64;
  }
  v7->Format = formatBits;
  return v6;
}

// File Line: 605
// RVA: 0x9EEAD0
bool __fastcall Scaleform::Render::MatrixPoolImpl::MatrixPool::reallocMatrixData(
        Scaleform::Render::MatrixPoolImpl::MatrixPool *this,
        Scaleform::Render::MatrixPoolImpl::EntryHandle *handle,
        char formatBits)
{
  int v5; // edi
  Scaleform::Render::MatrixPoolImpl::DataHeader *v7; // rax
  Scaleform::Render::MatrixPoolImpl::DataHeader *v8; // r8
  Scaleform::Render::MatrixPoolImpl::DataHeader *pHeader; // r9
  char Format; // r11
  int v11; // eax
  __int64 v12; // rdx
  int v13; // eax
  int pHandle; // xmm0_4
  int pHandle_high; // xmm1_4
  unsigned int RefCount; // xmm6_4
  int v17; // xmm7_4
  unsigned int v18; // xmm2_4
  int v19; // xmm3_4
  int v20; // xmm4_4
  int v21; // xmm5_4
  int v22; // eax
  __int64 v23; // rdx
  int v24; // eax
  Scaleform::Render::Cxform *v25; // rdx
  __int64 v26; // rcx
  Scaleform::Render::Matrix2x4<float> *v27; // rdx
  Scaleform::Render::Matrix2x4<float> *v28; // r10
  int v29; // eax
  int v30; // eax
  int v31; // eax
  __int64 v32; // r10
  __int64 v33; // rdx
  __int64 v34; // rax
  unsigned __int16 UnitSize; // cx

  v5 = formatBits & 0x10;
  v7 = Scaleform::Render::MatrixPoolImpl::MatrixPool::allocData(
         this,
         16
       * ((unsigned __int8)Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[formatBits & 0xF].Offsets[4]
        + ((v5 | 0x20u) >> 4)),
         handle);
  v8 = v7;
  if ( v7 )
  {
    pHeader = handle->pHeader;
    v7->Format = formatBits;
    v7->RefCount = pHeader->RefCount;
    Format = pHeader->Format;
    v11 = (unsigned __int8)Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[Format & 0xF].Offsets[4];
    if ( v5 )
    {
      if ( (Format & 0x10) != 0 )
      {
        v12 = v11 * 16;
        v13 = (unsigned __int8)Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[formatBits & 0xF].Offsets[4];
        LODWORD(v8[v13 + 1].pHandle) = *(_DWORD *)((char *)&pHeader[1].pHandle + v12);
        HIDWORD(v8[v13 + 1].pHandle) = *(_DWORD *)((char *)&pHeader[1].pHandle + v12 + 4);
        v8[v13 + 1].RefCount = *(unsigned int *)((char *)&pHeader[1].RefCount + v12);
        *(_DWORD *)&v8[v13 + 1].DataPageOffset = *(_DWORD *)((char *)&pHeader[1].DataPageOffset + v12);
        LODWORD(v8[v13 + 2].pHandle) = *(_DWORD *)((char *)&pHeader[2].pHandle + v12);
        HIDWORD(v8[v13 + 2].pHandle) = *(_DWORD *)((char *)&pHeader[2].pHandle + v12 + 4);
        v8[v13 + 2].RefCount = *(unsigned int *)((char *)&pHeader[2].RefCount + v12);
        *(_DWORD *)&v8[v13 + 2].DataPageOffset = *(_DWORD *)((char *)&pHeader[2].DataPageOffset + v12);
        LODWORD(v8[v13 + 3].pHandle) = *(_DWORD *)((char *)&pHeader[3].pHandle + v12);
        HIDWORD(v8[v13 + 3].pHandle) = *(_DWORD *)((char *)&pHeader[3].pHandle + v12 + 4);
        v8[v13 + 3].RefCount = *(unsigned int *)((char *)&pHeader[3].RefCount + v12);
        *(_DWORD *)&v8[v13 + 3].DataPageOffset = *(_DWORD *)((char *)&pHeader[3].DataPageOffset + v12);
      }
      else
      {
        pHandle = (int)pHeader[v11 + 1].pHandle;
        pHandle_high = HIDWORD(pHeader[v11 + 1].pHandle);
        RefCount = pHeader[v11 + 2].RefCount;
        v17 = *(_DWORD *)&pHeader[v11 + 2].DataPageOffset;
        v18 = pHeader[v11 + 1].RefCount;
        v19 = *(_DWORD *)&pHeader[v11 + 1].DataPageOffset;
        v20 = (int)pHeader[v11 + 2].pHandle;
        v21 = HIDWORD(pHeader[v11 + 2].pHandle);
        v22 = (unsigned __int8)Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[formatBits & 0xF].Offsets[4];
        LODWORD(v8[v22 + 1].pHandle) = pHandle;
        HIDWORD(v8[v22 + 1].pHandle) = pHandle_high;
        v8[v22 + 1].RefCount = v18;
        *(_DWORD *)&v8[v22 + 1].DataPageOffset = v19;
        LODWORD(v8[v22 + 2].pHandle) = v20;
        HIDWORD(v8[v22 + 2].pHandle) = v21;
        v8[v22 + 2].RefCount = RefCount;
        *(_DWORD *)&v8[v22 + 2].DataPageOffset = v17;
        LODWORD(v8[v22 + 3].pHandle) = _xmm.m128_i32[0];
        HIDWORD(v8[v22 + 3].pHandle) = _mm_shuffle_ps(_xmm, _xmm, 85).m128_u32[0];
        v8[v22 + 3].RefCount = _mm_shuffle_ps(_xmm, _xmm, 170).m128_u32[0];
        *(_DWORD *)&v8[v22 + 3].DataPageOffset = _xmm.m128_i32[3];
      }
    }
    else
    {
      v23 = v11 * 16;
      v24 = (unsigned __int8)Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[formatBits & 0xF].Offsets[4];
      LODWORD(v8[v24 + 1].pHandle) = *(_DWORD *)((char *)&pHeader[1].pHandle + v23);
      HIDWORD(v8[v24 + 1].pHandle) = *(_DWORD *)((char *)&pHeader[1].pHandle + v23 + 4);
      v8[v24 + 1].RefCount = *(unsigned int *)((char *)&pHeader[1].RefCount + v23);
      *(_DWORD *)&v8[v24 + 1].DataPageOffset = *(_DWORD *)((char *)&pHeader[1].DataPageOffset + v23);
      LODWORD(v8[v24 + 2].pHandle) = *(_DWORD *)((char *)&pHeader[2].pHandle + v23);
      HIDWORD(v8[v24 + 2].pHandle) = *(_DWORD *)((char *)&pHeader[2].pHandle + v23 + 4);
      v8[v24 + 2].RefCount = *(unsigned int *)((char *)&pHeader[2].RefCount + v23);
      *(_DWORD *)&v8[v24 + 2].DataPageOffset = *(_DWORD *)((char *)&pHeader[2].DataPageOffset + v23);
    }
    if ( (formatBits & 1) != 0 )
    {
      if ( (Format & 1) != 0 )
        v25 = (Scaleform::Render::Cxform *)&pHeader[(unsigned __int8)Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[pHeader->Format & 0xF].Offsets[0]
                                                  + 1];
      else
        v25 = &Scaleform::Render::Cxform::Identity;
      v26 = (unsigned __int8)Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[v8->Format & 0xF].Offsets[0]
          + 1i64;
      v8[v26] = *(Scaleform::Render::MatrixPoolImpl::DataHeader *)&v25->M[0][0];
      v8[v26 + 1] = *(Scaleform::Render::MatrixPoolImpl::DataHeader *)&v25->M[1][0];
    }
    v27 = &Scaleform::Render::Matrix2x4<float>::Identity;
    if ( (formatBits & 2) != 0 )
    {
      if ( (Format & 2) != 0 )
        v28 = (Scaleform::Render::Matrix2x4<float> *)&pHeader[(unsigned __int8)Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[pHeader->Format & 0xF].Offsets[1]
                                                            + 1];
      else
        v28 = &Scaleform::Render::Matrix2x4<float>::Identity;
      v29 = (unsigned __int8)Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[v8->Format & 0xF].Offsets[1];
      *(float *)&v8[v29 + 1].pHandle = v28->M[0][0];
      HIDWORD(v8[v29 + 1].pHandle) = LODWORD(v28->M[0][1]);
      v8[v29 + 1].RefCount = LODWORD(v28->M[0][2]);
      *(float *)&v8[v29 + 1].DataPageOffset = v28->M[0][3];
      *(float *)&v8[v29 + 2].pHandle = v28->M[1][0];
      HIDWORD(v8[v29 + 2].pHandle) = LODWORD(v28->M[1][1]);
      v8[v29 + 2].RefCount = LODWORD(v28->M[1][2]);
      *(float *)&v8[v29 + 2].DataPageOffset = v28->M[1][3];
    }
    if ( (formatBits & 4) != 0 )
    {
      if ( (Format & 4) != 0 )
        v27 = (Scaleform::Render::Matrix2x4<float> *)&pHeader[(unsigned __int8)Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[pHeader->Format & 0xF].Offsets[2]
                                                            + 1];
      v30 = (unsigned __int8)Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[v8->Format & 0xF].Offsets[2];
      *(float *)&v8[v30 + 1].pHandle = v27->M[0][0];
      HIDWORD(v8[v30 + 1].pHandle) = LODWORD(v27->M[0][1]);
      v8[v30 + 1].RefCount = LODWORD(v27->M[0][2]);
      *(float *)&v8[v30 + 1].DataPageOffset = v27->M[0][3];
      *(float *)&v8[v30 + 2].pHandle = v27->M[1][0];
      HIDWORD(v8[v30 + 2].pHandle) = LODWORD(v27->M[1][1]);
      v8[v30 + 2].RefCount = LODWORD(v27->M[1][2]);
      *(float *)&v8[v30 + 2].DataPageOffset = v27->M[1][3];
    }
    if ( (formatBits & 8) != 0 )
    {
      v31 = (unsigned __int8)Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[v8->Format & 0xF].Offsets[3];
      v32 = v31 * 16;
      if ( (Format & 8) != 0 )
      {
        v33 = (unsigned __int8)Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[pHeader->Format & 0xF].Offsets[3]
            + 1i64;
        v8[v31 + 1].pHandle = pHeader[(unsigned __int8)Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[pHeader->Format & 0xF].Offsets[3]
                                    + 1].pHandle;
        *(_QWORD *)&v8[v31 + 1].RefCount = *(_QWORD *)&pHeader[v33].RefCount;
        v8[v31 + 2].pHandle = pHeader[v33 + 1].pHandle;
        *(_QWORD *)&v8[v31 + 2].RefCount = *(_QWORD *)&pHeader[v33 + 1].RefCount;
        v8[v31 + 3].pHandle = pHeader[v33 + 2].pHandle;
        *(_QWORD *)&v8[v31 + 3].RefCount = *(_QWORD *)&pHeader[v33 + 2].RefCount;
        v8[v31 + 4].pHandle = pHeader[v33 + 3].pHandle;
        v34 = *(_QWORD *)&pHeader[v33 + 3].RefCount;
      }
      else
      {
        v34 = 0i64;
        *(Scaleform::Render::MatrixPoolImpl::EntryHandle **)((char *)&v8[1].pHandle + v32) = 0i64;
        *(_QWORD *)((char *)&v8[1].RefCount + v32) = 0i64;
        *(Scaleform::Render::MatrixPoolImpl::EntryHandle **)((char *)&v8[2].pHandle + v32) = 0i64;
        *(_QWORD *)((char *)&v8[2].RefCount + v32) = 0i64;
        *(Scaleform::Render::MatrixPoolImpl::EntryHandle **)((char *)&v8[3].pHandle + v32) = 0i64;
        *(_QWORD *)((char *)&v8[3].RefCount + v32) = 0i64;
        *(Scaleform::Render::MatrixPoolImpl::EntryHandle **)((char *)&v8[4].pHandle + v32) = 0i64;
      }
      *(_QWORD *)((char *)&v8[4].RefCount + v32) = v34;
    }
    if ( pHeader->pHandle != &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle )
    {
      UnitSize = (unsigned __int8)pHeader->UnitSize;
      pHeader->pHandle = 0i64;
      pHeader->RefCount = 0;
      UnitSize *= 16;
      *(_WORD *)((char *)&pHeader[1].RefCount + pHeader->DataPageOffset + 2) += UnitSize;
      this->FreedSpace += UnitSize;
    }
    handle->pHeader = v8;
    LOBYTE(v7) = 1;
  }
  return (char)v7;
}

// File Line: 685
// RVA: 0x9F33C0
__int64 __fastcall Scaleform::Render::MatrixPoolImpl::MatrixPool::squeezeMemoryRange(
        Scaleform::Render::MatrixPoolImpl::MatrixPool *this,
        Scaleform::Render::MatrixPoolImpl::DataPage *squeezeStart,
        Scaleform::Render::MatrixPoolImpl::DataPage *squeezeEnd,
        Scaleform::Render::MatrixPoolImpl::MatrixPool::SqueezeType type)
{
  Scaleform::Render::MatrixPoolImpl::MatrixPool *v4; // rbp
  unsigned __int8 v5; // cl
  Scaleform::Render::MatrixPoolImpl::MatrixPool::SqueezeType v6; // r14d
  Scaleform::Render::MatrixPoolImpl::DataPage *pNext; // rsi
  Scaleform::Render::MatrixPoolImpl::DataPage *v8; // r13
  Scaleform::Render::MatrixPoolImpl::DataPage *v9; // rbx
  Scaleform::Render::MatrixPoolImpl::DataPage *v10; // r15
  __int64 FreeMiddle; // r8
  __int64 FreeTail; // rcx
  Scaleform::Render::MatrixPoolImpl::DataPage *v13; // rdx
  Scaleform::Render::MatrixPoolImpl::DataPage *v14; // rdi
  __int64 v15; // r12
  int v16; // ebp
  unsigned __int16 v17; // r15
  $E5F2B3BA179E0486073CE4F8756635B8 *v18; // rdx
  Scaleform::Render::MatrixPoolImpl::DataPage *v19; // rdi
  Scaleform::Render::MatrixPoolImpl::DataPage *pPrev; // rcx
  Scaleform::Render::MatrixPoolImpl::DataPage *pLastFreedPage; // rdx
  __int64 result; // rax
  unsigned int v23; // [rsp+20h] [rbp-58h]
  char v25; // [rsp+88h] [rbp+10h]

  v4 = this;
  v5 = 0;
  v6 = type;
  pNext = squeezeStart;
  v25 = 0;
  v4->pAllocPage = 0i64;
  v4->pSqueezePage = 0i64;
  v8 = 0i64;
  v9 = 0i64;
  v10 = 0i64;
  if ( squeezeStart == squeezeEnd )
    goto LABEL_30;
  do
  {
    FreeMiddle = pNext->FreeMiddle;
    FreeTail = pNext->FreeTail;
    v23 = pNext->FreeMiddle;
    if ( (int)FreeMiddle + (int)FreeTail <= 203 )
    {
      pNext = pNext->pNext;
      v5 = v25;
      continue;
    }
    v13 = pNext + 1;
    v14 = pNext + 1;
    v15 = (__int64)&pNext[128] - FreeTail;
    if ( v8 || (v8 = pNext, v9 = pNext + 1, v10 = pNext + 128, (_WORD)FreeMiddle) )
    {
      if ( v13 != (Scaleform::Render::MatrixPoolImpl::DataPage *)v15 )
      {
        do
        {
          v16 = BYTE6(v14->pVoidNext);
          if ( LODWORD(v14->pNext) )
          {
            if ( (Scaleform::Render::MatrixPoolImpl::DataPage *)((char *)v9 + (unsigned int)(16 * v16)) > v10 )
            {
              v17 = (_WORD)v10 - (_WORD)v9;
              v9 = v13;
              v8->FreeTail = v17;
              v8 = pNext;
              v10 = pNext + 128;
            }
            if ( v9 != v14 )
            {
              memmove(v9, v14, 16 * BYTE6(v14->pVoidNext));
              v13 = pNext + 1;
              WORD2(v9->pVoidNext) = (_WORD)v8 - (_WORD)v9;
              v9->pPrev->pPrev = v9;
            }
            v9 = (Scaleform::Render::MatrixPoolImpl::DataPage *)((char *)v9 + (unsigned int)(16 * v16));
          }
          v14 = (Scaleform::Render::MatrixPoolImpl::DataPage *)((char *)v14 + (unsigned int)(16 * v16));
        }
        while ( v14 != (Scaleform::Render::MatrixPoolImpl::DataPage *)v15 );
        v4 = this;
        FreeMiddle = v23;
        v6 = type;
      }
    }
    else
    {
      v9 = (Scaleform::Render::MatrixPoolImpl::DataPage *)((char *)pNext - FreeTail + 4096);
    }
    v4->FreedSpace -= pNext->FreeMiddle;
    pNext->FreeMiddle = 0;
    if ( v8 == pNext )
    {
      if ( v9 != &v8[1] )
      {
        if ( (_WORD)FreeMiddle && (char *)v10 - (char *)v9 >= 1016 )
        {
          v5 = 1;
          v25 = 1;
          if ( v6 == Squeeze_Incremental )
            break;
          pNext = pNext->pNext;
        }
        else
        {
          v5 = v25;
          pNext = pNext->pNext;
        }
        continue;
      }
      v8 = 0i64;
    }
    v18 = &pNext->8;
    v19 = pNext;
    pPrev = pNext->pPrev;
    pNext = pNext->pNext;
    pPrev->pNext = pNext;
    v18->pNext->pPrev = v19->pPrev;
    v19->pPrev = (Scaleform::Render::MatrixPoolImpl::DataPage *)-1i64;
    v18->pNext = (Scaleform::Render::MatrixPoolImpl::DataPage *)-1i64;
    pLastFreedPage = v4->pLastFreedPage;
    v4->AllocatedSpace -= 4064i64;
    --v4->DataPageCount;
    if ( pLastFreedPage )
      ((void (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::Render::MatrixPoolImpl::DataPage *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Free)(
        Scaleform::Memory::pGlobalHeap,
        pLastFreedPage,
        FreeMiddle);
    v5 = 1;
    v4->pLastFreedPage = v19;
    v25 = 1;
    if ( v6 == Squeeze_Incremental )
      break;
  }
  while ( pNext != squeezeEnd );
  if ( v8 )
  {
    result = v5;
    v8->FreeTail = (_WORD)v10 - (_WORD)v9;
    v4->pAllocPage = v8;
    v4->pSqueezePage = v8;
    return result;
  }
LABEL_30:
  v4->pAllocPage = 0i64;
  if ( pNext != (Scaleform::Render::MatrixPoolImpl::DataPage *)&v4->DataPages )
    v4->pSqueezePage = pNext;
  return v5;
}

