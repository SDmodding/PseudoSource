// File Line: 60
// RVA: 0xA072F0
Scaleform::Render::D3D1x::MeshCacheItem *__fastcall Scaleform::Render::D3D1x::MeshCacheItem::Create(Scaleform::Render::MeshCacheItem::MeshType type, Scaleform::Render::MeshCacheListSet *pcacheList, Scaleform::Render::MeshCacheItem::MeshBaseContent *mc, Scaleform::Render::D3D1x::VertexBuffer *pvb, Scaleform::Render::D3D1x::IndexBuffer *pib, unsigned __int64 vertexOffset, unsigned __int64 vertexAllocSize, unsigned int vertexCount, unsigned __int64 indexOffset, unsigned __int64 indexAllocSize, unsigned int indexCount)
{
  Scaleform::Render::D3D1x::VertexBuffer *v11; // rsi
  Scaleform::Render::D3D1x::MeshCacheItem *result; // rax

  v11 = pvb;
  result = (Scaleform::Render::D3D1x::MeshCacheItem *)Scaleform::Render::MeshCacheItem::Create(
                                                        type,
                                                        pcacheList,
                                                        0x88ui64,
                                                        mc,
                                                        vertexAllocSize + indexAllocSize,
                                                        vertexCount,
                                                        indexCount);
  if ( result )
  {
    result->pVertexBuffer = v11;
    result->VBAllocSize = vertexAllocSize;
    result->pIndexBuffer = pib;
    result->IBAllocSize = indexAllocSize;
    result->VBAllocOffset = vertexOffset;
    result->IBAllocOffset = indexOffset;
  }
  return result;
}

// File Line: 104
// RVA: 0xA066A0
void __fastcall Scaleform::Render::D3D1x::MeshBuffer::~MeshBuffer(Scaleform::Render::D3D1x::MeshBuffer *this)
{
  this->vfptr = (Scaleform::Render::MeshBufferVtbl *)&Scaleform::Render::D3D1x::MeshBuffer::`vftable;
  this->vfptr = (Scaleform::Render::MeshBufferVtbl *)&Scaleform::Render::MeshBuffer::`vftable;
}

// File Line: 169
// RVA: 0xA066E0
void __fastcall Scaleform::Render::D3D1x::MeshBufferSet::~MeshBufferSet(Scaleform::Render::D3D1x::MeshBufferSet *this)
{
  Scaleform::Render::D3D1x::MeshBufferSet *v1; // rbx

  v1 = this;
  this->vfptr = (Scaleform::Render::D3D1x::MeshBufferSetVtbl *)&Scaleform::Render::D3D1x::MeshBufferSet::`vftable;
  Scaleform::AllocAddr::~AllocAddr(&this->Allocator);
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v1->Buffers.Data.Data);
}

// File Line: 183
// RVA: 0xA07410
void __fastcall Scaleform::Render::D3D1x::MeshBufferSet::DestroyBuffers(Scaleform::Render::D3D1x::MeshBufferSet *this, Scaleform::Render::MeshBuffer::AllocType type)
{
  Scaleform::Render::MeshBuffer::AllocType v2; // ebp
  Scaleform::Render::D3D1x::MeshBufferSet *v3; // rsi
  unsigned __int64 v4; // rbx
  Scaleform::Render::D3D1x::MeshBuffer *v5; // rdi

  v2 = type;
  v3 = this;
  v4 = 0i64;
  if ( this->Buffers.Data.Size )
  {
    do
    {
      v5 = v3->Buffers.Data.Data[v4];
      if ( v5 && (v2 == AT_None || v5->Type == v2) )
      {
        Scaleform::AllocAddr::RemoveSegment(&v3->Allocator, v5->Index << 24, (v5->Size + 15) >> 4);
        v3->TotalSize -= v5->Size;
        v3->Buffers.Data.Data[v5->Index] = 0i64;
        v5->vfptr->__vecDelDtor((Scaleform::Render::MeshBuffer *)&v5->vfptr, 1u);
      }
      ++v4;
    }
    while ( v4 < v3->Buffers.Data.Size );
  }
}

// File Line: 211
// RVA: 0xA06AC0
char __fastcall Scaleform::Render::D3D1x::MeshBufferSet::Alloc(Scaleform::Render::D3D1x::MeshBufferSet *this, unsigned __int64 size, Scaleform::Render::D3D1x::MeshBuffer **pbuffer, unsigned __int64 *poffset)
{
  Scaleform::Render::D3D1x::MeshBufferSet *v4; // rbx
  unsigned __int64 *v5; // rdi
  Scaleform::Render::D3D1x::MeshBuffer **v6; // rsi
  unsigned __int64 v7; // rax
  int v8; // edx
  char result; // al
  Scaleform::Render::D3D1x::MeshBuffer *v10; // rcx

  v4 = this;
  v5 = poffset;
  v6 = pbuffer;
  v7 = Scaleform::AllocAddr::Alloc(&this->Allocator, (size + 15) >> 4);
  v8 = v7;
  if ( v7 == -1i64 )
    return 0;
  v10 = v4->Buffers.Data.Data[v7 >> 24];
  result = 1;
  *v6 = v10;
  *v5 = 16i64 * (v8 & 0xFFFFFF);
  return result;
}

// File Line: 238
// RVA: 0xA07390
Scaleform::Render::D3D1x::MeshBuffer *__fastcall Scaleform::Render::D3D1x::MeshBufferSetImpl<Scaleform::Render::D3D1x::IndexBuffer>::CreateBuffer(Scaleform::Render::D3D1x::MeshBufferSetImpl<Scaleform::Render::D3D1x::IndexBuffer> *this, unsigned __int64 size, Scaleform::Render::MeshBuffer::AllocType type, unsigned int arena, Scaleform::MemoryHeap *pheap, ID3D11Device *pdevice)
{
  return Scaleform::Render::D3D1x::MeshBufferImpl<ID3D11Buffer,Scaleform::Render::D3D1x::IndexBuffer>::Create(
           size,
           type,
           arena,
           pheap,
           pdevice,
           (Scaleform::Render::D3D1x::MeshBufferSet *)&this->vfptr);
}

// File Line: 263
// RVA: 0xA074C0
char __fastcall Scaleform::Render::D3D1x::MeshBufferImpl<ID3D11Buffer,Scaleform::Render::D3D1x::IndexBuffer>::DoLock(Scaleform::Render::D3D1x::MeshBufferImpl<ID3D11Buffer,Scaleform::Render::D3D1x::VertexBuffer> *this, ID3D11DeviceContext *pcontext)
{
  D3D11_MAPPED_SUBRESOURCE *v2; // rdi
  Scaleform::Render::D3D1x::MeshBufferImpl<ID3D11Buffer,Scaleform::Render::D3D1x::VertexBuffer> *v3; // rbx
  int v4; // ST20_4

  v2 = &this->MappedBuffer;
  v3 = this;
  v4 = 0;
  if ( ((signed int (__fastcall *)(ID3D11DeviceContext *, ID3D11Buffer *, _QWORD, signed __int64, int, D3D11_MAPPED_SUBRESOURCE *))pcontext->vfptr[4].Release)(
         pcontext,
         this->pBuffer.pObject,
         0i64,
         5i64,
         v4,
         &this->MappedBuffer) < 0 )
    return 0;
  v3->pData = v2->pData;
  return 1;
}

// File Line: 274
// RVA: 0xA08020
void __fastcall Scaleform::Render::D3D1x::MeshBufferImpl<ID3D11Buffer,Scaleform::Render::D3D1x::VertexBuffer>::Unlock(Scaleform::Render::D3D1x::MeshBufferImpl<ID3D11Buffer,Scaleform::Render::D3D1x::VertexBuffer> *this, ID3D11DeviceContext *pcontext)
{
  Scaleform::Render::D3D1x::MeshBufferImpl<ID3D11Buffer,Scaleform::Render::D3D1x::VertexBuffer> *v2; // rbx

  v2 = this;
  pcontext->vfptr[5].QueryInterface((IUnknown *)pcontext, (_GUID *)this->pBuffer.pObject, 0i64);
  v2->pData = 0i64;
}

// File Line: 283
// RVA: 0xA06FB0
Scaleform::Render::D3D1x::MeshBuffer *__fastcall Scaleform::Render::D3D1x::MeshBufferImpl<ID3D11Buffer,Scaleform::Render::D3D1x::IndexBuffer>::Create(unsigned __int64 size, Scaleform::Render::MeshBuffer::AllocType type, unsigned int arena, Scaleform::MemoryHeap *pheap, ID3D11Device *pdevice, Scaleform::Render::D3D1x::MeshBufferSet *mbs)
{
  unsigned int v6; // er14
  Scaleform::Render::MeshBuffer::AllocType v7; // er15
  unsigned __int64 v8; // rdi
  unsigned __int64 v9; // r10
  Scaleform::Render::D3D1x::MeshBuffer **v10; // rax
  unsigned __int64 v11; // rbp
  Scaleform::Render::D3D1x::MeshBuffer *v12; // rbx
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,2>,Scaleform::ArrayDefaultPolicy> *v14; // rdi
  unsigned __int64 v15; // rax
  unsigned __int64 v16; // rsi
  unsigned __int64 v17; // r8
  _QWORD *v18; // rcx

  v6 = arena;
  v7 = type;
  v8 = 0i64;
  v9 = mbs->Buffers.Data.Size;
  if ( v9 )
  {
    v10 = mbs->Buffers.Data.Data;
    do
    {
      if ( !*v10 )
        break;
      ++v8;
      ++v10;
    }
    while ( v8 < v9 );
    if ( v8 == 256 )
      return 0i64;
  }
  v11 = (size + 15) & 0xFFFFFFFFFFFFFFF0ui64;
  v12 = (Scaleform::Render::D3D1x::MeshBuffer *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))pheap->vfptr->Alloc)(
                                                  pheap,
                                                  88i64);
  if ( v12 )
  {
    v12->vfptr = (Scaleform::Render::MeshBufferVtbl *)&Scaleform::Render::MeshBuffer::`vftable;
    v12->Arena = v6;
    v12->Type = v7;
    v12->Size = v11;
    v12->pData = 0i64;
    v12->vfptr = (Scaleform::Render::MeshBufferVtbl *)&Scaleform::Render::D3D1x::MeshBuffer::`vftable;
    v12->vfptr = (Scaleform::Render::MeshBufferVtbl *)&Scaleform::Render::D3D1x::MeshBufferImpl<ID3D11Buffer,Scaleform::Render::D3D1x::IndexBuffer>::`vftable;
    v12[1].vfptr = 0i64;
    v12->vfptr = (Scaleform::Render::MeshBufferVtbl *)&Scaleform::Render::D3D1x::IndexBuffer::`vftable;
  }
  else
  {
    v12 = 0i64;
  }
  if ( !v12 )
    return 0i64;
  if ( !(unsigned __int8)v12->vfptr[1].__vecDelDtor((Scaleform::Render::MeshBuffer *)&v12->vfptr, (unsigned int)pdevice) )
  {
    v12->vfptr->__vecDelDtor((Scaleform::Render::MeshBuffer *)&v12->vfptr, 1u);
    return 0i64;
  }
  v12->Index = v8;
  Scaleform::AllocAddr::AddSegment(&mbs->Allocator, v8 << 24, v11 >> 4);
  mbs->TotalSize += v11;
  if ( v8 == mbs->Buffers.Data.Size )
  {
    v14 = (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,2>,Scaleform::ArrayDefaultPolicy> *)&mbs->Buffers;
    v15 = mbs->Buffers.Data.Size;
    v16 = v15 + 1;
    if ( v15 + 1 >= v15 )
    {
      if ( v16 <= mbs->Buffers.Data.Policy.Capacity )
        goto LABEL_20;
      v17 = v16 + (v16 >> 2);
    }
    else
    {
      if ( v16 >= mbs->Buffers.Data.Policy.Capacity >> 1 )
        goto LABEL_20;
      v17 = v15 + 1;
    }
    Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      v14,
      v14,
      v17);
LABEL_20:
    mbs->Buffers.Data.Size = v16;
    v18 = &v14->Data[v16 - 1].pObject;
    if ( v18 )
      *v18 = v12;
    return v12;
  }
  mbs->Buffers.Data.Data[v8] = v12;
  return v12;
}

// File Line: 324
// RVA: 0xA08380
bool __fastcall Scaleform::Render::D3D1x::VertexBuffer::allocBuffer(Scaleform::Render::D3D1x::VertexBuffer *this, ID3D11Device *pdevice)
{
  ID3D10DeviceVtbl *v2; // rax
  int v4; // [rsp+20h] [rbp-28h]
  int v5; // [rsp+24h] [rbp-24h]
  int v6; // [rsp+28h] [rbp-20h]
  __int64 v7; // [rsp+2Ch] [rbp-1Ch]
  int v8; // [rsp+34h] [rbp-14h]

  v4 = this->Size;
  v2 = pdevice->vfptr;
  v5 = 2;
  v6 = 1;
  v7 = 0x10000i64;
  v8 = 0;
  return ((signed int (__fastcall *)(ID3D11Device *, int *, _QWORD, Scaleform::Ptr<ID3D11Buffer> *, _QWORD, _QWORD, _QWORD))v2->VSSetConstantBuffers)(
           pdevice,
           &v4,
           0i64,
           &this->pBuffer,
           *(_QWORD *)&v4,
           *(_QWORD *)&v6,
           0i64) >= 0;
}

// File Line: 345
// RVA: 0xA080D0
bool __fastcall Scaleform::Render::D3D1x::IndexBuffer::allocBuffer(Scaleform::Render::D3D1x::IndexBuffer *this, ID3D11Device *pdevice)
{
  ID3D10DeviceVtbl *v2; // rax
  int v4; // [rsp+20h] [rbp-28h]
  int v5; // [rsp+24h] [rbp-24h]
  int v6; // [rsp+28h] [rbp-20h]
  __int64 v7; // [rsp+2Ch] [rbp-1Ch]
  int v8; // [rsp+34h] [rbp-14h]

  v4 = this->Size;
  v2 = pdevice->vfptr;
  v5 = 2;
  v6 = 2;
  v7 = 0x10000i64;
  v8 = 0;
  return ((signed int (__fastcall *)(ID3D11Device *, int *, _QWORD, Scaleform::Ptr<ID3D11Buffer> *, _QWORD, _QWORD, _QWORD))v2->VSSetConstantBuffers)(
           pdevice,
           &v4,
           0i64,
           &this->pBuffer,
           *(_QWORD *)&v4,
           *(_QWORD *)&v6,
           0i64) >= 0;
}

// File Line: 454
// RVA: 0xA06E40
_BOOL8 __fastcall Scaleform::Render::D3D1x::MeshCache::AreBuffersLocked(Scaleform::Render::D3D1x::MeshCache *this)
{
  return this->Locked;
}

