// File Line: 136
// RVA: 0x9A7EB0
void __fastcall Scaleform::Render::MatrixPoolImpl::EntryHandle::ReleaseHandle(Scaleform::Render::MatrixPoolImpl::EntryHandle *this)
{
  Scaleform::Render::MatrixPoolImpl::EntryHandle *v1; // r9
  char *v2; // r8
  __int64 v3; // rcx
  __int64 v4; // rax
  bool v5; // zf

  v1 = this;
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
  v1->pHeader = *(Scaleform::Render::MatrixPoolImpl::DataHeader **)(v2 + 24);
  v5 = (*((_DWORD *)v2 + 4))-- == 1;
  *((_QWORD *)v2 + 3) = v1;
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
bool __fastcall Scaleform::Render::MatrixPoolImpl::EntryHandleTable::allocEntryPage(Scaleform::Render::MatrixPoolImpl::EntryHandleTable *this)
{
  Scaleform::Render::MatrixPoolImpl::EntryHandleTable *v1; // rbx
  Scaleform::Render::MatrixPoolImpl::HandlePageBase *v2; // rax
  Scaleform::Render::MatrixPoolImpl::HandlePageBase *v3; // r8
  Scaleform::Render::MatrixPoolImpl::EntryHandle *v4; // rdx
  signed __int64 v5; // rcx
  Scaleform::Render::MatrixPoolImpl::EntryHandle **v6; // rax

  v1 = this;
  v2 = (Scaleform::Render::MatrixPoolImpl::HandlePageBase *)this->pHeap->vfptr->Alloc(
                                                              this->pHeap,
                                                              2032ui64,
                                                              2048ui64,
                                                              0i64);
  v3 = v2;
  if ( v2 )
  {
    v4 = 0i64;
    v2->pTable = v1;
    v5 = 249i64;
    v2->UseCount = 0;
    v6 = &v2[50].pFreeList;
    do
    {
      *v6 = v4;
      v4 = (Scaleform::Render::MatrixPoolImpl::EntryHandle *)v6;
      --v6;
      --v5;
    }
    while ( v5 );
    v3->pFreeList = v4;
    v2 = v1->PartiallyFreePages.Root.pPrev;
    v3->pNext = (Scaleform::Render::MatrixPoolImpl::HandlePageBase *)&v1->PartiallyFreePages;
    v3->pPrev = v2;
    v1->PartiallyFreePages.Root.pPrev->pNext = v3;
    v1->PartiallyFreePages.Root.pPrev = v3;
    LOBYTE(v2) = 1;
  }
  return (char)v2;
}

// File Line: 211
// RVA: 0x957AB0
Scaleform::Render::MatrixPoolImpl::DataHeader **__fastcall Scaleform::Render::MatrixPoolImpl::EntryHandleTable::AllocEntry(Scaleform::Render::MatrixPoolImpl::EntryHandleTable *this, Scaleform::Render::MatrixPoolImpl::DataHeader *header)
{
  Scaleform::Render::MatrixPoolImpl::DataHeader *v2; // rdi
  Scaleform::Render::MatrixPoolImpl::EntryHandleTable *v3; // rbx
  Scaleform::Render::MatrixPoolImpl::HandlePageBase *v5; // r8
  Scaleform::Render::MatrixPoolImpl::DataHeader **v6; // r9
  Scaleform::Render::MatrixPoolImpl::EntryHandle *v7; // rax

  v2 = header;
  v3 = this;
  if ( (Scaleform::List<Scaleform::Render::MatrixPoolImpl::HandlePage,Scaleform::Render::MatrixPoolImpl::HandlePageBase> *)this->PartiallyFreePages.Root.pNext == &this->PartiallyFreePages
    && !Scaleform::Render::MatrixPoolImpl::EntryHandleTable::allocEntryPage(this) )
  {
    return 0i64;
  }
  v5 = v3->PartiallyFreePages.Root.pNext;
  v6 = &v5->pFreeList->pHeader;
  v7 = (Scaleform::Render::MatrixPoolImpl::EntryHandle *)*v6;
  ++v5->UseCount;
  v5->pFreeList = v7;
  if ( !*v6 )
  {
    v5->pPrev->pNext = v5->pNext;
    v5->pNext->pPrev = v5->pPrev;
    v5->pPrev = (Scaleform::Render::MatrixPoolImpl::HandlePageBase *)-1i64;
    v5->pNext = (Scaleform::Render::MatrixPoolImpl::HandlePageBase *)-1i64;
    v5->pPrev = v3->FullPages.Root.pPrev;
    v5->pNext = (Scaleform::Render::MatrixPoolImpl::HandlePageBase *)&v3->FullPages;
    v3->FullPages.Root.pPrev->pNext = v5;
    v3->FullPages.Root.pPrev = v5;
  }
  *v6 = v2;
  return v6;
}

// File Line: 310
// RVA: 0x159CD50
char *Scaleform::Render::MatrixPoolImpl::_dynamic_initializer_for__HMatrix_DefaultMatrixData__()
{
  char *result; // rax
  char *v1; // rcx

  result = &Scaleform::Render::MatrixPoolImpl::HMatrix_DefaultMatrixData.DataBytes[16];
  v1 = &Scaleform::Render::MatrixPoolImpl::HMatrix_DefaultMatrixData.DataBytes[16
                                                                             * (unsigned __int8)Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[0].Offsets[4]
                                                                             + 16];
  *(_OWORD *)v1 = *(_OWORD *)&Scaleform::Render::Matrix2x4<float>::Identity.M[0][0];
  *((_OWORD *)v1 + 1) = *(_OWORD *)&Scaleform::Render::Matrix2x4<float>::Identity.M[1][0];
  return result;
}

// File Line: 315
// RVA: 0x9B1750
void __fastcall Scaleform::Render::MatrixPoolImpl::HMatrix::SetMatrix2D(Scaleform::Render::MatrixPoolImpl::HMatrix *this, Scaleform::Render::Matrix2x4<float> *m)
{
  Scaleform::Render::MatrixPoolImpl::EntryHandle *v2; // rdi
  Scaleform::Render::Matrix2x4<float> *v3; // rbx
  Scaleform::Render::MatrixPoolImpl::HMatrix *v4; // r14
  char v5; // si
  float v6; // xmm1_4
  float v7; // xmm0_4
  float v8; // xmm1_4
  float v9; // xmm0_4
  float v10; // xmm1_4
  Scaleform::Render::MatrixPoolImpl::DataHeader *v11; // r8
  __int64 v12; // rdx
  float Buf1; // [rsp+20h] [rbp-38h]
  float v14; // [rsp+24h] [rbp-34h]
  float v15; // [rsp+28h] [rbp-30h]
  float v16; // [rsp+2Ch] [rbp-2Ch]
  float v17; // [rsp+30h] [rbp-28h]
  float v18; // [rsp+34h] [rbp-24h]
  float v19; // [rsp+38h] [rbp-20h]
  float v20; // [rsp+3Ch] [rbp-1Ch]
  __m128 v21; // [rsp+40h] [rbp-18h]

  v2 = this->pHandle;
  v3 = m;
  v4 = this;
  v5 = this->pHandle->pHeader->Format;
  if ( v5 & 0x10 )
  {
    v6 = m->M[0][1];
    Buf1 = m->M[0][0];
    v7 = m->M[0][2];
    v14 = v6;
    v8 = m->M[0][3];
    v15 = v7;
    v17 = m->M[1][0];
    v9 = m->M[1][2];
    v16 = v8;
    v10 = m->M[1][1];
    v19 = v9;
    v21 = _xmm;
    v18 = v10;
    v20 = m->M[1][3];
    if ( !memcmp(&Buf1, &Scaleform::Render::Matrix3x4<float>::Identity, 0x30ui64) )
      return;
    Scaleform::Render::MatrixPoolImpl::MatrixPool::reallocMatrixData(
      *(Scaleform::Render::MatrixPoolImpl::MatrixPool **)(*(_QWORD *)(((unsigned __int64)v2 & 0xFFFFFFFFFFFFF800ui64)
                                                                    + 0x20)
                                                        + 8i64),
      v2,
      v5 & 0xEF);
  }
  v11 = v4->pHandle->pHeader;
  v12 = (unsigned __int8)Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[v11->Format & 0xF].Offsets[4];
  *(float *)&v11[v12 + 1].pHandle = v3->M[0][0];
  HIDWORD(v11[v12 + 1].pHandle) = LODWORD(v3->M[0][1]);
  v11[v12 + 1].RefCount = LODWORD(v3->M[0][2]);
  *(float *)&v11[v12 + 1].DataPageOffset = v3->M[0][3];
  *(float *)&v11[v12 + 2].pHandle = v3->M[1][0];
  HIDWORD(v11[v12 + 2].pHandle) = LODWORD(v3->M[1][1]);
  v11[v12 + 2].RefCount = LODWORD(v3->M[1][2]);
  *(float *)&v11[v12 + 2].DataPageOffset = v3->M[1][3];
}

// File Line: 327
// RVA: 0x9B18A0
void __fastcall Scaleform::Render::MatrixPoolImpl::HMatrix::SetMatrix3D(Scaleform::Render::MatrixPoolImpl::HMatrix *this, Scaleform::Render::Matrix3x4<float> *m)
{
  Scaleform::Render::MatrixPoolImpl::EntryHandle *v2; // rdi
  Scaleform::Render::Matrix3x4<float> *v3; // rbx
  Scaleform::Render::MatrixPoolImpl::HMatrix *v4; // r14
  unsigned __int8 v5; // si
  Scaleform::Render::MatrixPoolImpl::DataHeader *v6; // rcx

  v2 = this->pHandle;
  v3 = m;
  v4 = this;
  v5 = this->pHandle->pHeader->Format;
  if ( !(v5 & 0x10) )
  {
    if ( !memcmp(m, &Scaleform::Render::Matrix3x4<float>::Identity, 0x30ui64) )
      return;
    Scaleform::Render::MatrixPoolImpl::MatrixPool::reallocMatrixData(
      *(Scaleform::Render::MatrixPoolImpl::MatrixPool **)(*(_QWORD *)(((unsigned __int64)v2 & 0xFFFFFFFFFFFFF800ui64)
                                                                    + 0x20)
                                                        + 8i64),
      v2,
      v5 | 0x10);
  }
  v6 = &v4->pHandle->pHeader[(unsigned __int8)Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[v4->pHandle->pHeader->Format & 0xF].Offsets[4]];
  *(float *)&v6[1].pHandle = v3->M[0][0];
  HIDWORD(v6[1].pHandle) = LODWORD(v3->M[0][1]);
  v6[1].RefCount = LODWORD(v3->M[0][2]);
  *(float *)&v6[1].DataPageOffset = v3->M[0][3];
  *(float *)&v6[2].pHandle = v3->M[1][0];
  HIDWORD(v6[2].pHandle) = LODWORD(v3->M[1][1]);
  v6[2].RefCount = LODWORD(v3->M[1][2]);
  *(float *)&v6[2].DataPageOffset = v3->M[1][3];
  *(float *)&v6[3].pHandle = v3->M[2][0];
  HIDWORD(v6[3].pHandle) = LODWORD(v3->M[2][1]);
  v6[3].RefCount = LODWORD(v3->M[2][2]);
  *(float *)&v6[3].DataPageOffset = v3->M[2][3];
}

// File Line: 339
// RVA: 0x9AECE0
void __fastcall Scaleform::Render::MatrixPoolImpl::HMatrix::SetCxform(Scaleform::Render::MatrixPoolImpl::HMatrix *this, Scaleform::Render::Cxform *m)
{
  Scaleform::Render::Cxform *v2; // rbx
  Scaleform::Render::MatrixPoolImpl::HMatrix *v3; // rdi
  Scaleform::Render::MatrixPoolImpl::DataHeader *v4; // rax
  Scaleform::Render::MatrixPoolImpl::DataHeader *v5; // rdx
  signed __int64 v6; // rcx

  v2 = m;
  v3 = this;
  v4 = this->pHandle->pHeader;
  if ( v4->Format & 1 )
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
      *(Scaleform::Render::MatrixPoolImpl::MatrixPool **)(*(_QWORD *)(((_QWORD)this->pHandle & 0xFFFFFFFFFFFFF800ui64)
                                                                    + 0x20)
                                                        + 8i64),
      this->pHandle,
      (unsigned __int8)v4->Format | 1);
LABEL_11:
    v5 = v3->pHandle->pHeader;
    v6 = (unsigned __int8)Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[v5->Format & 0xF].Offsets[0]
       + 1i64;
    v5[v6] = *(Scaleform::Render::MatrixPoolImpl::DataHeader *)&v2->M[0][0];
    v5[v6 + 1] = *(Scaleform::Render::MatrixPoolImpl::DataHeader *)&v2->M[1][0];
  }
}

// File Line: 351
// RVA: 0x9B4C30
void __fastcall Scaleform::Render::MatrixPoolImpl::HMatrix::SetTextureMatrix(Scaleform::Render::MatrixPoolImpl::HMatrix *this, Scaleform::Render::Matrix2x4<float> *m, unsigned int index)
{
  Scaleform::Render::MatrixPoolImpl::EntryHandle *v3; // rdi
  unsigned int v4; // ebp
  Scaleform::Render::MatrixPoolImpl::HMatrix *v5; // r14
  signed int v6; // ebx
  Scaleform::Render::Matrix2x4<float> *v7; // rsi
  Scaleform::Render::MatrixPoolImpl::DataHeader *v8; // rdx
  __int64 v9; // rcx

  v3 = this->pHandle;
  v4 = index + 1;
  v5 = this;
  v6 = 1 << (index + 1);
  v7 = m;
  if ( !((unsigned __int8)v6 & this->pHandle->pHeader->Format) )
  {
    if ( !memcmp(m, &Scaleform::Render::Matrix2x4<float>::Identity, 0x20ui64) )
      return;
    Scaleform::Render::MatrixPoolImpl::MatrixPool::reallocMatrixData(
      *(Scaleform::Render::MatrixPoolImpl::MatrixPool **)(*(_QWORD *)(((unsigned __int64)v3 & 0xFFFFFFFFFFFFF800ui64)
                                                                    + 0x20)
                                                        + 8i64),
      v3,
      v6 | (unsigned __int8)v3->pHeader->Format);
  }
  v8 = v5->pHandle->pHeader;
  v9 = (unsigned __int8)Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[v8->Format & 0xF].Offsets[v4];
  *(float *)&v8[v9 + 1].pHandle = v7->M[0][0];
  HIDWORD(v8[v9 + 1].pHandle) = LODWORD(v7->M[0][1]);
  v8[v9 + 1].RefCount = LODWORD(v7->M[0][2]);
  *(float *)&v8[v9 + 1].DataPageOffset = v7->M[0][3];
  *(float *)&v8[v9 + 2].pHandle = v7->M[1][0];
  HIDWORD(v8[v9 + 2].pHandle) = LODWORD(v7->M[1][1]);
  v8[v9 + 2].RefCount = LODWORD(v7->M[1][2]);
  *(float *)&v8[v9 + 2].DataPageOffset = v7->M[1][3];
}

// File Line: 364
// RVA: 0x9B52C0
void __fastcall Scaleform::Render::MatrixPoolImpl::HMatrix::SetUserData(Scaleform::Render::MatrixPoolImpl::HMatrix *this, const void *data, unsigned __int64 size)
{
  const void *v3; // rbx
  unsigned __int64 v4; // rdi
  Scaleform::Render::MatrixPoolImpl::DataHeader *v5; // rax
  Scaleform::Render::MatrixPoolImpl::HMatrix *v6; // rsi
  Scaleform::Render::MatrixPoolImpl::DataHeader *v7; // rcx

  v3 = data;
  v4 = size;
  v5 = this->pHandle->pHeader;
  v6 = this;
  if ( !(v5->Format & 8) )
  {
    if ( !data )
      return;
    Scaleform::Render::MatrixPoolImpl::MatrixPool::reallocMatrixData(
      *(Scaleform::Render::MatrixPoolImpl::MatrixPool **)(*(_QWORD *)(((_QWORD)this->pHandle & 0xFFFFFFFFFFFFF800ui64)
                                                                    + 0x20)
                                                        + 8i64),
      this->pHandle,
      (unsigned __int8)v5->Format | 8);
  }
  v7 = &v6->pHandle->pHeader[(unsigned __int8)Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[v6->pHandle->pHeader->Format & 0xF].Offsets[3]
                           + 1];
  if ( v3 )
    memmove(v7, v3, v4);
  else
    memset(v7, 0, v4);
}

// File Line: 384
// RVA: 0x94DFB0
void __fastcall Scaleform::Render::MatrixPoolImpl::HMatrix::operator=(Scaleform::Render::MatrixPoolImpl::HMatrix *this, Scaleform::Render::MatrixPoolImpl::HMatrix *other)
{
  Scaleform::Render::MatrixPoolImpl::HMatrix *v2; // rdi
  Scaleform::Render::MatrixPoolImpl::HMatrix *v3; // rsi
  Scaleform::Render::MatrixPoolImpl::DataHeader *v4; // rbx
  bool v5; // zf
  __int64 v6; // rcx

  v2 = this;
  v3 = other;
  if ( other->pHandle != &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle )
    ++other->pHandle->pHeader->RefCount;
  if ( this->pHandle != &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle
    && (v4 = this->pHandle->pHeader, v5 = v4->RefCount == 1, --v4->RefCount, v5) )
  {
    v6 = v4->DataPageOffset;
    *(_WORD *)((char *)&v4[1].RefCount + v6 + 2) += 16 * (unsigned __int8)v4->UnitSize;
    (*(Scaleform::Render::MatrixPoolImpl::EntryHandle **)((char *)&v4[1].pHandle + v6))[5].pHeader += (unsigned __int8)v4->UnitSize;
    Scaleform::Render::MatrixPoolImpl::EntryHandle::ReleaseHandle(v4->pHandle);
    v4->pHandle = 0i64;
    v2->pHandle = v3->pHandle;
  }
  else
  {
    this->pHandle = other->pHandle;
  }
}

// File Line: 405
// RVA: 0x94B3A0
void __fastcall Scaleform::Render::MatrixPoolImpl::MatrixPool::~MatrixPool(Scaleform::Render::MatrixPoolImpl::MatrixPool *this)
{
  Scaleform::Render::MatrixPoolImpl::MatrixPool *v1; // rbx
  char **v2; // rsi
  Scaleform::Render::MatrixPoolImpl::DataPage *v3; // rdi

  v1 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::MatrixPoolImpl::MatrixPool::`vftable';
  v2 = (char **)&this->DataPages;
  if ( (Scaleform::List<Scaleform::Render::MatrixPoolImpl::DataPage,Scaleform::Render::MatrixPoolImpl::DataPage> *)this->DataPages.Root.pNext != &this->DataPages )
  {
    do
    {
      v3 = v1->DataPages.Root.pNext;
      v3->pPrev->pNext = v3->pNext;
      v3->pNext->pPrev = v3->pPrev;
      v3->pPrev = (Scaleform::Render::MatrixPoolImpl::DataPage *)-1i64;
      v3->pNext = (Scaleform::Render::MatrixPoolImpl::DataPage *)-1i64;
      v1->AllocatedSpace -= 4064i64;
      --v1->DataPageCount;
      if ( v1->pLastFreedPage )
        ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      v1->pLastFreedPage = v3;
    }
    while ( v2[1] != (char *)v2 );
  }
  if ( v1->pLastFreedPage )
    ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  v1->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable';
}

// File Line: 419
// RVA: 0x9DD420
Scaleform::Render::MatrixPoolImpl::EntryHandle *__fastcall Scaleform::Render::MatrixPoolImpl::MatrixPool::createMatrixHelper(Scaleform::Render::MatrixPoolImpl::MatrixPool *this, Scaleform::Render::Matrix2x4<float> *m, Scaleform::Render::Cxform *cx, unsigned int formatBits)
{
  Scaleform::Render::Matrix2x4<float> *v4; // rdi
  char v5; // bl
  Scaleform::Render::Cxform *v6; // rsi
  Scaleform::Render::MatrixPoolImpl::EntryHandle *result; // rax
  Scaleform::Render::MatrixPoolImpl::DataHeader *v8; // r9
  __int64 v9; // rdx
  signed __int64 v10; // rcx
  Scaleform::Render::MatrixPoolImpl::DataHeader *v11; // rdx
  __int64 v12; // rcx
  Scaleform::Render::MatrixPoolImpl::DataHeader *v13; // rdx
  __int64 v14; // rcx
  Scaleform::Render::MatrixPoolImpl::DataHeader *v15; // rdx
  __int64 v16; // rcx

  v4 = m;
  v5 = formatBits;
  v6 = cx;
  result = Scaleform::Render::MatrixPoolImpl::MatrixPool::allocMatrixData(this, formatBits);
  if ( !result )
    return &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle;
  v8 = result->pHeader;
  v9 = (unsigned __int8)Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[result->pHeader->Format & 0xF].Offsets[4];
  *(float *)&v8[v9 + 1].pHandle = v4->M[0][0];
  HIDWORD(v8[v9 + 1].pHandle) = LODWORD(v4->M[0][1]);
  v8[v9 + 1].RefCount = LODWORD(v4->M[0][2]);
  *(float *)&v8[v9 + 1].DataPageOffset = v4->M[0][3];
  *(float *)&v8[v9 + 2].pHandle = v4->M[1][0];
  HIDWORD(v8[v9 + 2].pHandle) = LODWORD(v4->M[1][1]);
  v8[v9 + 2].RefCount = LODWORD(v4->M[1][2]);
  *(float *)&v8[v9 + 2].DataPageOffset = v4->M[1][3];
  if ( v5 & 1 )
  {
    v10 = (unsigned __int8)Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[v8->Format & 0xF].Offsets[0]
        + 1i64;
    v8[v10] = *(Scaleform::Render::MatrixPoolImpl::DataHeader *)&v6->M[0][0];
    v8[v10 + 1] = *(Scaleform::Render::MatrixPoolImpl::DataHeader *)&v6->M[1][0];
  }
  if ( v5 & 2 )
  {
    v11 = result->pHeader;
    v12 = (unsigned __int8)Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[result->pHeader->Format & 0xF].Offsets[1];
    v11[v12 + 1].pHandle = (Scaleform::Render::MatrixPoolImpl::EntryHandle *)1065353216;
    *(_QWORD *)&v11[v12 + 1].RefCount = 0i64;
    LODWORD(v11[v12 + 2].pHandle) = 0;
    *(Scaleform::Render::MatrixPoolImpl::EntryHandle **)((char *)&v11[v12 + 2].pHandle + 4) = (Scaleform::Render::MatrixPoolImpl::EntryHandle *)1065353216;
    *(_DWORD *)&v11[v12 + 2].DataPageOffset = 0;
  }
  if ( v5 & 4 )
  {
    v13 = result->pHeader;
    v14 = (unsigned __int8)Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[result->pHeader->Format & 0xF].Offsets[2];
    v13[v14 + 1].pHandle = (Scaleform::Render::MatrixPoolImpl::EntryHandle *)1065353216;
    *(_QWORD *)&v13[v14 + 1].RefCount = 0i64;
    LODWORD(v13[v14 + 2].pHandle) = 0;
    *(Scaleform::Render::MatrixPoolImpl::EntryHandle **)((char *)&v13[v14 + 2].pHandle + 4) = (Scaleform::Render::MatrixPoolImpl::EntryHandle *)1065353216;
    *(_DWORD *)&v13[v14 + 2].DataPageOffset = 0;
  }
  if ( v5 & 8 )
  {
    v15 = result->pHeader;
    v16 = (unsigned __int8)Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[result->pHeader->Format & 0xF].Offsets[3];
    v15[v16 + 1].pHandle = 0i64;
    *(_QWORD *)&v15[v16 + 1].RefCount = 0i64;
    v15[v16 + 2].pHandle = 0i64;
    *(_QWORD *)&v15[v16 + 2].RefCount = 0i64;
    v15[v16 + 3].pHandle = 0i64;
    *(_QWORD *)&v15[v16 + 3].RefCount = 0i64;
    v15[v16 + 4].pHandle = 0i64;
    *(_QWORD *)&v15[v16 + 4].RefCount = 0i64;
  }
  return result;
}

// File Line: 444
// RVA: 0x9DD5E0
Scaleform::Render::MatrixPoolImpl::EntryHandle *__fastcall Scaleform::Render::MatrixPoolImpl::MatrixPool::createMatrixHelper(Scaleform::Render::MatrixPoolImpl::MatrixPool *this, Scaleform::Render::Matrix3x4<float> *m, Scaleform::Render::Cxform *cx, unsigned int formatBits)
{
  Scaleform::Render::Matrix3x4<float> *v4; // rdi
  char v5; // bl
  Scaleform::Render::Cxform *v6; // rsi
  Scaleform::Render::MatrixPoolImpl::EntryHandle *result; // rax
  Scaleform::Render::MatrixPoolImpl::DataHeader *v8; // r10
  __int64 v9; // rdx
  Scaleform::Render::MatrixPoolImpl::DataHeader *v10; // rdx
  signed __int64 v11; // rcx
  Scaleform::Render::MatrixPoolImpl::DataHeader *v12; // rdx
  __int64 v13; // rcx
  Scaleform::Render::MatrixPoolImpl::DataHeader *v14; // rdx
  __int64 v15; // rcx
  Scaleform::Render::MatrixPoolImpl::DataHeader *v16; // rdx
  __int64 v17; // rcx

  v4 = m;
  v5 = formatBits;
  v6 = cx;
  result = Scaleform::Render::MatrixPoolImpl::MatrixPool::allocMatrixData(this, formatBits);
  if ( !result )
    return &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle;
  v8 = result->pHeader;
  v9 = (unsigned __int8)Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[result->pHeader->Format & 0xF].Offsets[4];
  *(float *)&v8[v9 + 1].pHandle = v4->M[0][0];
  HIDWORD(v8[v9 + 1].pHandle) = LODWORD(v4->M[0][1]);
  v8[v9 + 1].RefCount = LODWORD(v4->M[0][2]);
  *(float *)&v8[v9 + 1].DataPageOffset = v4->M[0][3];
  *(float *)&v8[v9 + 2].pHandle = v4->M[1][0];
  HIDWORD(v8[v9 + 2].pHandle) = LODWORD(v4->M[1][1]);
  v8[v9 + 2].RefCount = LODWORD(v4->M[1][2]);
  *(float *)&v8[v9 + 2].DataPageOffset = v4->M[1][3];
  *(float *)&v8[v9 + 3].pHandle = v4->M[2][0];
  HIDWORD(v8[v9 + 3].pHandle) = LODWORD(v4->M[2][1]);
  v8[v9 + 3].RefCount = LODWORD(v4->M[2][2]);
  *(float *)&v8[v9 + 3].DataPageOffset = v4->M[2][3];
  if ( v5 & 1 )
  {
    v10 = result->pHeader;
    v11 = (unsigned __int8)Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[result->pHeader->Format & 0xF].Offsets[0]
        + 1i64;
    v10[v11] = *(Scaleform::Render::MatrixPoolImpl::DataHeader *)&v6->M[0][0];
    v10[v11 + 1] = *(Scaleform::Render::MatrixPoolImpl::DataHeader *)&v6->M[1][0];
  }
  if ( v5 & 2 )
  {
    v12 = result->pHeader;
    v13 = (unsigned __int8)Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[result->pHeader->Format & 0xF].Offsets[1];
    v12[v13 + 1].pHandle = (Scaleform::Render::MatrixPoolImpl::EntryHandle *)1065353216;
    *(_QWORD *)&v12[v13 + 1].RefCount = 0i64;
    LODWORD(v12[v13 + 2].pHandle) = 0;
    *(Scaleform::Render::MatrixPoolImpl::EntryHandle **)((char *)&v12[v13 + 2].pHandle + 4) = (Scaleform::Render::MatrixPoolImpl::EntryHandle *)1065353216;
    *(_DWORD *)&v12[v13 + 2].DataPageOffset = 0;
  }
  if ( v5 & 4 )
  {
    v14 = result->pHeader;
    v15 = (unsigned __int8)Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[result->pHeader->Format & 0xF].Offsets[2];
    v14[v15 + 1].pHandle = (Scaleform::Render::MatrixPoolImpl::EntryHandle *)1065353216;
    *(_QWORD *)&v14[v15 + 1].RefCount = 0i64;
    LODWORD(v14[v15 + 2].pHandle) = 0;
    *(Scaleform::Render::MatrixPoolImpl::EntryHandle **)((char *)&v14[v15 + 2].pHandle + 4) = (Scaleform::Render::MatrixPoolImpl::EntryHandle *)1065353216;
    *(_DWORD *)&v14[v15 + 2].DataPageOffset = 0;
  }
  if ( v5 & 8 )
  {
    v16 = result->pHeader;
    v17 = (unsigned __int8)Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[result->pHeader->Format & 0xF].Offsets[3];
    v16[v17 + 1].pHandle = 0i64;
    *(_QWORD *)&v16[v17 + 1].RefCount = 0i64;
    v16[v17 + 2].pHandle = 0i64;
    *(_QWORD *)&v16[v17 + 2].RefCount = 0i64;
    v16[v17 + 3].pHandle = 0i64;
    *(_QWORD *)&v16[v17 + 3].RefCount = 0i64;
    v16[v17 + 4].pHandle = 0i64;
    *(_QWORD *)&v16[v17 + 4].RefCount = 0i64;
  }
  return result;
}

// File Line: 471
// RVA: 0x967B70
Scaleform::Render::MatrixPoolImpl::HMatrix *__fastcall Scaleform::Render::MatrixPoolImpl::MatrixPool::CreateMatrix(Scaleform::Render::MatrixPoolImpl::MatrixPool *this, Scaleform::Render::MatrixPoolImpl::HMatrix *result, Scaleform::Render::Matrix2x4<float> *m, unsigned int formatBits)
{
  Scaleform::Render::MatrixPoolImpl::HMatrix *v4; // rbx

  v4 = result;
  result->pHandle = Scaleform::Render::MatrixPoolImpl::MatrixPool::createMatrixHelper(
                      this,
                      m,
                      &Scaleform::Render::Cxform::Identity,
                      formatBits);
  return v4;
}

// File Line: 475
// RVA: 0x967C10
Scaleform::Render::MatrixPoolImpl::HMatrix *__fastcall Scaleform::Render::MatrixPoolImpl::MatrixPool::CreateMatrix(Scaleform::Render::MatrixPoolImpl::MatrixPool *this, Scaleform::Render::MatrixPoolImpl::HMatrix *result, Scaleform::Render::Matrix3x4<float> *m, unsigned int formatBits)
{
  Scaleform::Render::MatrixPoolImpl::HMatrix *v4; // rbx

  v4 = result;
  result->pHandle = Scaleform::Render::MatrixPoolImpl::MatrixPool::createMatrixHelper(
                      this,
                      m,
                      &Scaleform::Render::Cxform::Identity,
                      formatBits);
  return v4;
}

// File Line: 479
// RVA: 0x967B20
Scaleform::Render::MatrixPoolImpl::HMatrix *__fastcall Scaleform::Render::MatrixPoolImpl::MatrixPool::CreateMatrix(Scaleform::Render::MatrixPoolImpl::MatrixPool *this, Scaleform::Render::MatrixPoolImpl::HMatrix *result, Scaleform::Render::Matrix2x4<float> *m, Scaleform::Render::Cxform *cx, unsigned int formatBits)
{
  Scaleform::Render::MatrixPoolImpl::HMatrix *v5; // rbx

  v5 = result;
  result->pHandle = Scaleform::Render::MatrixPoolImpl::MatrixPool::createMatrixHelper(this, m, cx, formatBits);
  return v5;
}

// File Line: 483
// RVA: 0x967BC0
Scaleform::Render::MatrixPoolImpl::HMatrix *__fastcall Scaleform::Render::MatrixPoolImpl::MatrixPool::CreateMatrix(Scaleform::Render::MatrixPoolImpl::MatrixPool *this, Scaleform::Render::MatrixPoolImpl::HMatrix *result, Scaleform::Render::Matrix3x4<float> *m, Scaleform::Render::Cxform *cx, unsigned int formatBits)
{
  Scaleform::Render::MatrixPoolImpl::HMatrix *v5; // rbx

  v5 = result;
  result->pHandle = Scaleform::Render::MatrixPoolImpl::MatrixPool::createMatrixHelper(this, m, cx, formatBits);
  return v5;
}

// File Line: 511
// RVA: 0x9CB9F0
bool __fastcall Scaleform::Render::MatrixPoolImpl::MatrixPool::allocDataPage(Scaleform::Render::MatrixPoolImpl::MatrixPool *this)
{
  Scaleform::Render::MatrixPoolImpl::DataPage *v1; // rdx
  Scaleform::Render::MatrixPoolImpl::MatrixPool *v2; // rbx
  Scaleform::Render::MatrixPoolImpl::DataPage *v3; // rax

  v1 = this->pLastFreedPage;
  v2 = this;
  if ( v1 )
  {
    this->pLastFreedPage = 0i64;
  }
  else
  {
    v3 = (Scaleform::Render::MatrixPoolImpl::DataPage *)this->pHeap->vfptr->Alloc(this->pHeap, 4096ui64, 16ui64, 0i64);
    v1 = v3;
    if ( !v3 )
      return (char)v3;
  }
  v1->pPool = v2;
  *(_DWORD *)&v1->FreeTail = 4064;
  v3 = v2->DataPages.Root.pPrev;
  v1->pNext = (Scaleform::Render::MatrixPoolImpl::DataPage *)&v2->DataPages;
  v1->pPrev = v3;
  v2->DataPages.Root.pPrev->pNext = v1;
  v2->DataPages.Root.pPrev = v1;
  v2->AllocatedSpace += 4064i64;
  ++v2->DataPageCount;
  v2->pAllocPage = v1;
  LOBYTE(v3) = 1;
  return (char)v3;
}

// File Line: 546
// RVA: 0x9E1D70
bool __fastcall Scaleform::Render::MatrixPoolImpl::MatrixPool::ensureAllocSpace(Scaleform::Render::MatrixPoolImpl::MatrixPool *this, unsigned __int64 size)
{
  char **v2; // rax
  Scaleform::Render::MatrixPoolImpl::MatrixPool *v3; // rbx
  unsigned __int64 v4; // rdi
  Scaleform::Render::MatrixPoolImpl::DataPage *v5; // rcx
  bool result; // al
  Scaleform::Render::MatrixPoolImpl::DataPage *v7; // rdx
  Scaleform::Render::MatrixPoolImpl::DataPage *v8; // rax

  v2 = (char **)&this->DataPages;
  v3 = this;
  v4 = size;
  v5 = this->DataPages.Root.pPrev;
  if ( v3->pAllocPage != v5 && v2[1] != (char *)v2 )
  {
    v3->pAllocPage = v5;
    if ( v5->FreeTail >= size )
      goto LABEL_14;
  }
  if ( v3->FreedSpace >= 3 * v3->AllocatedSpace >> 5 )
  {
    v7 = v3->pSqueezePage;
    if ( !v7
      || !Scaleform::Render::MatrixPoolImpl::MatrixPool::squeezeMemoryRange(v3, v7, v3->DataPages.Root.pNext->pPrev, 0) )
    {
      Scaleform::Render::MatrixPoolImpl::MatrixPool::squeezeMemoryRange(
        v3,
        v3->DataPages.Root.pNext,
        v3->DataPages.Root.pNext->pPrev,
        0);
    }
  }
  v8 = v3->pAllocPage;
  if ( v8 && v8->FreeTail >= v4 )
LABEL_14:
    result = 1;
  else
    result = Scaleform::Render::MatrixPoolImpl::MatrixPool::allocDataPage(v3);
  return result;
}

// File Line: 566
// RVA: 0x9CB890
Scaleform::Render::MatrixPoolImpl::DataHeader *__fastcall Scaleform::Render::MatrixPoolImpl::MatrixPool::allocData(Scaleform::Render::MatrixPoolImpl::MatrixPool *this, unsigned __int64 size, Scaleform::Render::MatrixPoolImpl::EntryHandle *handle)
{
  Scaleform::Render::MatrixPoolImpl::DataPage *v3; // rax
  Scaleform::Render::MatrixPoolImpl::EntryHandle *v4; // rbp
  unsigned __int64 v5; // rbx
  Scaleform::Render::MatrixPoolImpl::MatrixPool *v6; // rsi
  unsigned __int64 v7; // rdi
  Scaleform::Render::MatrixPoolImpl::DataHeader *result; // rax
  Scaleform::Render::MatrixPoolImpl::DataPage *v9; // rcx

  v3 = this->pAllocPage;
  v4 = handle;
  v5 = size;
  v6 = this;
  v7 = size + 16;
  if ( (!v3 || v3->FreeTail < v7) && !Scaleform::Render::MatrixPoolImpl::MatrixPool::ensureAllocSpace(this, size + 16) )
    return 0i64;
  v9 = v6->pAllocPage;
  result = (Scaleform::Render::MatrixPoolImpl::DataHeader *)((char *)&v6->pAllocPage[128] - v9->FreeTail);
  result->DataPageOffset = (_WORD)v9 - (_WORD)result;
  result->pHandle = v4;
  result->RefCount = 1;
  result->UnitSize = (v5 >> 4) + 1;
  result->Format = 0;
  v9->FreeTail -= v7;
  return result;
}

// File Line: 587
// RVA: 0x9CBEB0
Scaleform::Render::MatrixPoolImpl::EntryHandle *__fastcall Scaleform::Render::MatrixPoolImpl::MatrixPool::allocMatrixData(Scaleform::Render::MatrixPoolImpl::MatrixPool *this, unsigned int formatBits)
{
  Scaleform::Render::MatrixPoolImpl::MatrixPool *v2; // rsi
  char v3; // di
  int v4; // ebp
  Scaleform::Render::MatrixPoolImpl::EntryHandle *v5; // rax
  Scaleform::Render::MatrixPoolImpl::EntryHandle *v6; // rbx
  Scaleform::Render::MatrixPoolImpl::DataHeader *v7; // rax

  v2 = this;
  v3 = formatBits;
  v4 = (unsigned __int8)Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[formatBits & 0xF].Offsets[4];
  v5 = (Scaleform::Render::MatrixPoolImpl::EntryHandle *)Scaleform::Render::MatrixPoolImpl::EntryHandleTable::AllocEntry(
                                                           &this->HandleTable,
                                                           0i64);
  v6 = v5;
  if ( !v5 )
    return 0i64;
  v7 = Scaleform::Render::MatrixPoolImpl::MatrixPool::allocData(v2, 16 * (v4 + ((v3 & 0x10 | 0x20u) >> 4)), v5);
  v6->pHeader = v7;
  if ( !v7 )
  {
    Scaleform::Render::MatrixPoolImpl::EntryHandle::ReleaseHandle(v6);
    return 0i64;
  }
  v7->Format = v3;
  return v6;
}

// File Line: 605
// RVA: 0x9EEAD0
bool __fastcall Scaleform::Render::MatrixPoolImpl::MatrixPool::reallocMatrixData(Scaleform::Render::MatrixPoolImpl::MatrixPool *this, Scaleform::Render::MatrixPoolImpl::EntryHandle *handle, unsigned int formatBits)
{
  Scaleform::Render::MatrixPoolImpl::EntryHandle *v3; // rsi
  char v4; // bl
  unsigned int v5; // edi
  Scaleform::Render::MatrixPoolImpl::MatrixPool *v6; // rbp
  Scaleform::Render::MatrixPoolImpl::DataHeader *v7; // rax
  Scaleform::Render::MatrixPoolImpl::DataHeader *v8; // r8
  Scaleform::Render::MatrixPoolImpl::DataHeader *v9; // r9
  char v10; // r11
  int v11; // eax
  __int64 v12; // rcx
  int v13; // xmm1_4
  unsigned int v14; // xmm6_4
  int v15; // xmm7_4
  unsigned int v16; // xmm2_4
  int v17; // xmm3_4
  int v18; // xmm4_4
  int v19; // xmm5_4
  __int64 v20; // rcx
  __int64 v21; // rcx
  Scaleform::Render::Cxform *v22; // rdx
  signed __int64 v23; // rcx
  Scaleform::Render::Matrix2x4<float> *v24; // rdx
  Scaleform::Render::Matrix2x4<float> *v25; // r10
  __int64 v26; // rcx
  __int64 v27; // rcx
  int v28; // eax
  __int64 v29; // r10
  signed __int64 v30; // rdx
  __int64 v31; // rax
  unsigned __int16 v32; // cx

  v3 = handle;
  v4 = formatBits;
  v5 = formatBits & 0x10;
  v6 = this;
  v7 = Scaleform::Render::MatrixPoolImpl::MatrixPool::allocData(
         this,
         16
       * ((unsigned __int8)Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[formatBits & 0xF].Offsets[4]
        + ((v5 | 0x20) >> 4)),
         handle);
  v8 = v7;
  if ( v7 )
  {
    v9 = v3->pHeader;
    v7->Format = v4;
    v7->RefCount = v9->RefCount;
    v10 = v9->Format;
    v11 = (unsigned __int8)Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[v9->Format & 0xF].Offsets[4];
    if ( v5 )
    {
      if ( v10 & 0x10 )
      {
        v12 = (unsigned __int8)Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[v4 & 0xF].Offsets[4];
        LODWORD(v8[v12 + 1].pHandle) = v9[v11 + 1].pHandle;
        HIDWORD(v8[v12 + 1].pHandle) = HIDWORD(v9[v11 + 1].pHandle);
        v8[v12 + 1].RefCount = v9[v11 + 1].RefCount;
        *(_DWORD *)&v8[v12 + 1].DataPageOffset = *(_DWORD *)&v9[v11 + 1].DataPageOffset;
        LODWORD(v8[v12 + 2].pHandle) = v9[v11 + 2].pHandle;
        HIDWORD(v8[v12 + 2].pHandle) = HIDWORD(v9[v11 + 2].pHandle);
        v8[v12 + 2].RefCount = v9[v11 + 2].RefCount;
        *(_DWORD *)&v8[v12 + 2].DataPageOffset = *(_DWORD *)&v9[v11 + 2].DataPageOffset;
        LODWORD(v8[v12 + 3].pHandle) = v9[v11 + 3].pHandle;
        HIDWORD(v8[v12 + 3].pHandle) = HIDWORD(v9[v11 + 3].pHandle);
        v8[v12 + 3].RefCount = v9[v11 + 3].RefCount;
        *(_DWORD *)&v8[v12 + 3].DataPageOffset = *(_DWORD *)&v9[v11 + 3].DataPageOffset;
      }
      else
      {
        v13 = HIDWORD(v9[v11 + 1].pHandle);
        v14 = v9[v11 + 2].RefCount;
        v15 = *(_DWORD *)&v9[v11 + 2].DataPageOffset;
        v16 = v9[v11 + 1].RefCount;
        v17 = *(_DWORD *)&v9[v11 + 1].DataPageOffset;
        v18 = (int)v9[v11 + 2].pHandle;
        v19 = HIDWORD(v9[v11 + 2].pHandle);
        v20 = (unsigned __int8)Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[v4 & 0xF].Offsets[4];
        LODWORD(v8[v20 + 1].pHandle) = v9[v11 + 1].pHandle;
        HIDWORD(v8[v20 + 1].pHandle) = v13;
        v8[v20 + 1].RefCount = v16;
        *(_DWORD *)&v8[v20 + 1].DataPageOffset = v17;
        LODWORD(v8[v20 + 2].pHandle) = v18;
        HIDWORD(v8[v20 + 2].pHandle) = v19;
        v8[v20 + 2].RefCount = v14;
        *(_DWORD *)&v8[v20 + 2].DataPageOffset = v15;
        LODWORD(v8[v20 + 3].pHandle) = _xmm.m128_i32[0];
        HIDWORD(v8[v20 + 3].pHandle) = (unsigned __int128)_mm_shuffle_ps(_xmm, _xmm, 85);
        v8[v20 + 3].RefCount = (unsigned __int128)_mm_shuffle_ps(_xmm, _xmm, 170);
        *(float *)&v8[v20 + 3].DataPageOffset = _xmm.m128_f32[3];
      }
    }
    else
    {
      v21 = (unsigned __int8)Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[v4 & 0xF].Offsets[4];
      LODWORD(v8[v21 + 1].pHandle) = v9[v11 + 1].pHandle;
      HIDWORD(v8[v21 + 1].pHandle) = HIDWORD(v9[v11 + 1].pHandle);
      v8[v21 + 1].RefCount = v9[v11 + 1].RefCount;
      *(_DWORD *)&v8[v21 + 1].DataPageOffset = *(_DWORD *)&v9[v11 + 1].DataPageOffset;
      LODWORD(v8[v21 + 2].pHandle) = v9[v11 + 2].pHandle;
      HIDWORD(v8[v21 + 2].pHandle) = HIDWORD(v9[v11 + 2].pHandle);
      v8[v21 + 2].RefCount = v9[v11 + 2].RefCount;
      *(_DWORD *)&v8[v21 + 2].DataPageOffset = *(_DWORD *)&v9[v11 + 2].DataPageOffset;
    }
    if ( v4 & 1 )
    {
      if ( v10 & 1 )
        v22 = (Scaleform::Render::Cxform *)&v9[(unsigned __int8)Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[v9->Format & 0xF].Offsets[0]
                                             + 1];
      else
        v22 = &Scaleform::Render::Cxform::Identity;
      v23 = (unsigned __int8)Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[v8->Format & 0xF].Offsets[0]
          + 1i64;
      v8[v23] = *(Scaleform::Render::MatrixPoolImpl::DataHeader *)&v22->M[0][0];
      v8[v23 + 1] = *(Scaleform::Render::MatrixPoolImpl::DataHeader *)&v22->M[1][0];
    }
    v24 = &Scaleform::Render::Matrix2x4<float>::Identity;
    if ( v4 & 2 )
    {
      if ( v10 & 2 )
        v25 = (Scaleform::Render::Matrix2x4<float> *)&v9[(unsigned __int8)Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[v9->Format & 0xF].Offsets[1]
                                                       + 1];
      else
        v25 = &Scaleform::Render::Matrix2x4<float>::Identity;
      v26 = (unsigned __int8)Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[v8->Format & 0xF].Offsets[1];
      *(float *)&v8[v26 + 1].pHandle = v25->M[0][0];
      HIDWORD(v8[v26 + 1].pHandle) = LODWORD(v25->M[0][1]);
      v8[v26 + 1].RefCount = LODWORD(v25->M[0][2]);
      *(float *)&v8[v26 + 1].DataPageOffset = v25->M[0][3];
      *(float *)&v8[v26 + 2].pHandle = v25->M[1][0];
      HIDWORD(v8[v26 + 2].pHandle) = LODWORD(v25->M[1][1]);
      v8[v26 + 2].RefCount = LODWORD(v25->M[1][2]);
      *(float *)&v8[v26 + 2].DataPageOffset = v25->M[1][3];
    }
    if ( v4 & 4 )
    {
      if ( v10 & 4 )
        v24 = (Scaleform::Render::Matrix2x4<float> *)&v9[(unsigned __int8)Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[v9->Format & 0xF].Offsets[2]
                                                       + 1];
      v27 = (unsigned __int8)Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[v8->Format & 0xF].Offsets[2];
      *(float *)&v8[v27 + 1].pHandle = v24->M[0][0];
      HIDWORD(v8[v27 + 1].pHandle) = LODWORD(v24->M[0][1]);
      v8[v27 + 1].RefCount = LODWORD(v24->M[0][2]);
      *(float *)&v8[v27 + 1].DataPageOffset = v24->M[0][3];
      *(float *)&v8[v27 + 2].pHandle = v24->M[1][0];
      HIDWORD(v8[v27 + 2].pHandle) = LODWORD(v24->M[1][1]);
      v8[v27 + 2].RefCount = LODWORD(v24->M[1][2]);
      *(float *)&v8[v27 + 2].DataPageOffset = v24->M[1][3];
    }
    if ( v4 & 8 )
    {
      v28 = (unsigned __int8)Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[v8->Format & 0xF].Offsets[3];
      v29 = v28 * 16;
      if ( v10 & 8 )
      {
        v30 = (unsigned __int8)Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[v9->Format & 0xF].Offsets[3]
            + 1i64;
        v8[v28 + 1].pHandle = v9[(unsigned __int8)Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[v9->Format & 0xF].Offsets[3]
                               + 1i64].pHandle;
        *(_QWORD *)&v8[v28 + 1].RefCount = *(_QWORD *)&v9[v30].RefCount;
        v8[v28 + 2].pHandle = v9[v30 + 1].pHandle;
        *(_QWORD *)&v8[v28 + 2].RefCount = *(_QWORD *)&v9[v30 + 1].RefCount;
        v8[v28 + 3].pHandle = v9[v30 + 2].pHandle;
        *(_QWORD *)&v8[v28 + 3].RefCount = *(_QWORD *)&v9[v30 + 2].RefCount;
        v8[v28 + 4].pHandle = v9[v30 + 3].pHandle;
        v31 = *(_QWORD *)&v9[v30 + 3].RefCount;
      }
      else
      {
        v31 = 0i64;
        *(Scaleform::Render::MatrixPoolImpl::EntryHandle **)((char *)&v8[1].pHandle + v29) = 0i64;
        *(_QWORD *)((char *)&v8[1].RefCount + v29) = 0i64;
        *(Scaleform::Render::MatrixPoolImpl::EntryHandle **)((char *)&v8[2].pHandle + v29) = 0i64;
        *(_QWORD *)((char *)&v8[2].RefCount + v29) = 0i64;
        *(Scaleform::Render::MatrixPoolImpl::EntryHandle **)((char *)&v8[3].pHandle + v29) = 0i64;
        *(_QWORD *)((char *)&v8[3].RefCount + v29) = 0i64;
        *(Scaleform::Render::MatrixPoolImpl::EntryHandle **)((char *)&v8[4].pHandle + v29) = 0i64;
      }
      *(_QWORD *)((char *)&v8[4].RefCount + v29) = v31;
    }
    if ( v9->pHandle != &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle )
    {
      v32 = (unsigned __int8)v9->UnitSize;
      v9->pHandle = 0i64;
      v9->RefCount = 0;
      v32 *= 16;
      *(_WORD *)((char *)&v9[1].RefCount + v9->DataPageOffset + 2) += v32;
      v6->FreedSpace += v32;
    }
    v3->pHeader = v8;
    LOBYTE(v7) = 1;
  }
  return (char)v7;
}

// File Line: 685
// RVA: 0x9F33C0
__int64 __fastcall Scaleform::Render::MatrixPoolImpl::MatrixPool::squeezeMemoryRange(Scaleform::Render::MatrixPoolImpl::MatrixPool *this, Scaleform::Render::MatrixPoolImpl::DataPage *squeezeStart, Scaleform::Render::MatrixPoolImpl::DataPage *squeezeEnd, Scaleform::Render::MatrixPoolImpl::MatrixPool::SqueezeType type)
{
  Scaleform::Render::MatrixPoolImpl::MatrixPool *v4; // rbp
  unsigned __int8 v5; // cl
  Scaleform::Render::MatrixPoolImpl::MatrixPool::SqueezeType v6; // er14
  Scaleform::Render::MatrixPoolImpl::DataPage *v7; // rsi
  Scaleform::Render::MatrixPoolImpl::DataPage *v8; // r13
  Scaleform::Render::MatrixPoolImpl::DataPage *v9; // rbx
  unsigned __int64 v10; // r15
  __int64 v11; // r8
  __int64 v12; // rcx
  signed __int64 v13; // rdx
  signed __int64 v14; // rdi
  signed __int64 v15; // r12
  int v16; // ebp
  unsigned __int16 v17; // r15
  $E5F2B3BA179E0486073CE4F8756635B8 *v18; // rdx
  Scaleform::Render::MatrixPoolImpl::DataPage *v19; // rdi
  Scaleform::Render::MatrixPoolImpl::DataPage *v20; // rcx
  Scaleform::Render::MatrixPoolImpl::DataPage *v21; // rdx
  __int64 result; // rax
  unsigned int v23; // [rsp+20h] [rbp-58h]
  Scaleform::Render::MatrixPoolImpl::MatrixPool *v24; // [rsp+80h] [rbp+8h]
  char v25; // [rsp+88h] [rbp+10h]
  Scaleform::Render::MatrixPoolImpl::DataPage *v26; // [rsp+90h] [rbp+18h]
  Scaleform::Render::MatrixPoolImpl::MatrixPool::SqueezeType v27; // [rsp+98h] [rbp+20h]

  v27 = type;
  v26 = squeezeEnd;
  v24 = this;
  v4 = this;
  v5 = 0;
  v6 = type;
  v7 = squeezeStart;
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
    v11 = v7->FreeMiddle;
    v12 = v7->FreeTail;
    v23 = v7->FreeMiddle;
    if ( (signed int)v11 + (signed int)v12 <= 203 )
    {
      v7 = v7->pNext;
      v5 = v25;
      continue;
    }
    v13 = (signed __int64)&v7[1];
    v14 = (signed __int64)&v7[1];
    v15 = (signed __int64)&v7[128] - v12;
    if ( v8 || (v8 = v7, v9 = v7 + 1, v10 = (unsigned __int64)&v7[128], (_WORD)v11) )
    {
      if ( v13 != v15 )
      {
        do
        {
          v16 = *(unsigned __int8 *)(v14 + 14);
          if ( *(_DWORD *)(v14 + 8) )
          {
            if ( (unsigned __int64)v9 + (unsigned int)(16 * v16) > v10 )
            {
              v17 = v10 - (_WORD)v9;
              v9 = (Scaleform::Render::MatrixPoolImpl::DataPage *)v13;
              v8->FreeTail = v17;
              v8 = v7;
              v10 = (unsigned __int64)&v7[128];
            }
            if ( v9 != (Scaleform::Render::MatrixPoolImpl::DataPage *)v14 )
            {
              memmove(v9, (const void *)v14, 16 * *(unsigned __int8 *)(v14 + 14));
              v13 = (signed __int64)&v7[1];
              WORD2(v9->pVoidNext) = (_WORD)v8 - (_WORD)v9;
              v9->pPrev->pPrev = v9;
            }
            v9 = (Scaleform::Render::MatrixPoolImpl::DataPage *)((char *)v9 + (unsigned int)(16 * v16));
          }
          v14 += (unsigned int)(16 * v16);
        }
        while ( v14 != v15 );
        v4 = v24;
        v11 = v23;
        v6 = v27;
      }
    }
    else
    {
      v9 = (Scaleform::Render::MatrixPoolImpl::DataPage *)((char *)v7 - v12 + 4096);
    }
    v4->FreedSpace -= v7->FreeMiddle;
    v7->FreeMiddle = 0;
    if ( v8 == v7 )
    {
      if ( v9 != &v8[1] )
      {
        if ( (_WORD)v11 && (signed __int64)(v10 - (_QWORD)v9) >= 1016 )
        {
          v5 = 1;
          v25 = 1;
          if ( v6 == Squeeze_Incremental )
            break;
          v7 = v7->pNext;
        }
        else
        {
          v5 = v25;
          v7 = v7->pNext;
        }
        continue;
      }
      v8 = 0i64;
    }
    v18 = &v7->8;
    v19 = v7;
    v20 = v7->pPrev;
    v7 = v7->pNext;
    v20->pNext = v7;
    v18->pNext->pPrev = v19->pPrev;
    v19->pPrev = (Scaleform::Render::MatrixPoolImpl::DataPage *)-1i64;
    v18->pNext = (Scaleform::Render::MatrixPoolImpl::DataPage *)-1i64;
    v21 = v4->pLastFreedPage;
    v4->AllocatedSpace -= 4064i64;
    --v4->DataPageCount;
    if ( v21 )
      ((void (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::Render::MatrixPoolImpl::DataPage *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Free)(
        Scaleform::Memory::pGlobalHeap,
        v21,
        v11);
    v5 = 1;
    v4->pLastFreedPage = v19;
    v25 = 1;
    if ( v6 == Squeeze_Incremental )
      break;
  }
  while ( v7 != v26 );
  if ( v8 )
  {
    result = v5;
    v8->FreeTail = v10 - (_WORD)v9;
    v4->pAllocPage = v8;
    v4->pSqueezePage = v8;
    return result;
  }
LABEL_30:
  v4->pAllocPage = 0i64;
  if ( v7 != (Scaleform::Render::MatrixPoolImpl::DataPage *)&v4->DataPages )
    v4->pSqueezePage = v7;
  return v5;
}

