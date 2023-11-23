// File Line: 60
// RVA: 0xA072F0
Scaleform::Render::D3D1x::MeshCacheItem *__fastcall Scaleform::Render::D3D1x::MeshCacheItem::Create(
        Scaleform::Render::MeshCacheItem::MeshType type,
        Scaleform::Render::MeshCacheListSet *pcacheList,
        Scaleform::Render::MeshCacheItem::MeshBaseContent *mc,
        Scaleform::Render::D3D1x::VertexBuffer *pvb,
        Scaleform::Render::D3D1x::IndexBuffer *pib,
        unsigned __int64 vertexOffset,
        unsigned __int64 vertexAllocSize,
        unsigned int vertexCount,
        unsigned __int64 indexOffset,
        unsigned __int64 indexAllocSize,
        unsigned int indexCount)
{
  Scaleform::Render::D3D1x::MeshCacheItem *result; // rax

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
    result->pVertexBuffer = pvb;
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
  this->vfptr = (Scaleform::Render::D3D1x::MeshBufferSetVtbl *)&Scaleform::Render::D3D1x::MeshBufferSet::`vftable;
  Scaleform::AllocAddr::~AllocAddr(&this->Allocator);
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, this->Buffers.Data.Data);
}

// File Line: 183
// RVA: 0xA07410
void __fastcall Scaleform::Render::D3D1x::MeshBufferSet::DestroyBuffers(
        Scaleform::Render::D3D1x::MeshBufferSet *this,
        Scaleform::Render::MeshBuffer::AllocType type)
{
  unsigned __int64 i; // rbx
  Scaleform::Render::D3D1x::MeshBuffer *v5; // rdi

  for ( i = 0i64; i < this->Buffers.Data.Size; ++i )
  {
    v5 = this->Buffers.Data.Data[i];
    if ( v5 && (type == AT_None || v5->Type == type) )
    {
      Scaleform::AllocAddr::RemoveSegment(&this->Allocator, v5->Index << 24, (v5->Size + 15) >> 4);
      this->TotalSize -= v5->Size;
      this->Buffers.Data.Data[v5->Index] = 0i64;
      v5->vfptr->__vecDelDtor(v5, 1u);
    }
  }
}

// File Line: 211
// RVA: 0xA06AC0
bool __fastcall Scaleform::Render::D3D1x::MeshBufferSet::Alloc(
        Scaleform::Render::D3D1x::MeshBufferSet *this,
        unsigned __int64 size,
        Scaleform::Render::D3D1x::MeshBuffer **pbuffer,
        unsigned __int64 *poffset)
{
  unsigned __int64 v7; // rax
  int v8; // edx
  bool result; // al
  Scaleform::Render::D3D1x::MeshBuffer *v10; // rcx

  v7 = Scaleform::AllocAddr::Alloc(&this->Allocator, (size + 15) >> 4);
  v8 = v7;
  if ( v7 == -1i64 )
    return 0;
  v10 = this->Buffers.Data.Data[v7 >> 24];
  result = 1;
  *pbuffer = v10;
  *poffset = 16i64 * (v8 & 0xFFFFFF);
  return result;
}

// File Line: 238
// RVA: 0xA07390
Scaleform::Render::D3D1x::IndexBuffer *__fastcall Scaleform::Render::D3D1x::MeshBufferSetImpl<Scaleform::Render::D3D1x::IndexBuffer>::CreateBuffer(
        Scaleform::Render::D3D1x::MeshBufferSetImpl<Scaleform::Render::D3D1x::IndexBuffer> *this,
        unsigned __int64 size,
        Scaleform::Render::MeshBuffer::AllocType type,
        unsigned int arena,
        Scaleform::MemoryHeap *pheap,
        ID3D11Device *pdevice)
{
  return Scaleform::Render::D3D1x::MeshBufferImpl<ID3D11Buffer,Scaleform::Render::D3D1x::IndexBuffer>::Create(
           size,
           type,
           arena,
           pheap,
           pdevice,
           this);
}

// File Line: 263
// RVA: 0xA074C0
char __fastcall Scaleform::Render::D3D1x::MeshBufferImpl<ID3D11Buffer,Scaleform::Render::D3D1x::IndexBuffer>::DoLock(
        Scaleform::Render::D3D1x::MeshBufferImpl<ID3D11Buffer,Scaleform::Render::D3D1x::VertexBuffer> *this,
        ID3D11DeviceContext *pcontext)
{
  D3D11_MAPPED_SUBRESOURCE *p_MappedBuffer; // rdi

  p_MappedBuffer = &this->MappedBuffer;
  if ( ((int (__fastcall *)(ID3D11DeviceContext *, ID3D11Buffer *, _QWORD, __int64, _DWORD, D3D11_MAPPED_SUBRESOURCE *))pcontext->vfptr[4].Release)(
         pcontext,
         this->pBuffer.pObject,
         0i64,
         5i64,
         0,
         &this->MappedBuffer) < 0 )
    return 0;
  this->pData = p_MappedBuffer->pData;
  return 1;
}

// File Line: 274
// RVA: 0xA08020
void __fastcall Scaleform::Render::D3D1x::MeshBufferImpl<ID3D11Buffer,Scaleform::Render::D3D1x::VertexBuffer>::Unlock(
        Scaleform::Render::D3D1x::MeshBufferImpl<ID3D11Buffer,Scaleform::Render::D3D1x::VertexBuffer> *this,
        ID3D11DeviceContext *pcontext)
{
  pcontext->vfptr[5].QueryInterface(pcontext, (_GUID *)this->pBuffer.pObject, 0i64);
  this->pData = 0i64;
}

// File Line: 283
// RVA: 0xA06FB0
Scaleform::Render::D3D1x::IndexBuffer *__fastcall Scaleform::Render::D3D1x::MeshBufferImpl<ID3D11Buffer,Scaleform::Render::D3D1x::IndexBuffer>::Create(
        unsigned __int64 size,
        Scaleform::Render::MeshBuffer::AllocType type,
        unsigned int arena,
        Scaleform::MemoryHeap *pheap,
        ID3D11Device *pdevice,
        Scaleform::Render::D3D1x::MeshBufferSet *mbs)
{
  unsigned __int64 v8; // rdi
  unsigned __int64 v9; // r10
  Scaleform::Render::D3D1x::MeshBuffer **Data; // rax
  unsigned __int64 v11; // rbp
  Scaleform::Render::D3D1x::MeshBuffer *v12; // rbx
  Scaleform::ArrayLH<Scaleform::Render::D3D1x::MeshBuffer *,2,Scaleform::ArrayDefaultPolicy> *p_Buffers; // rdi
  unsigned __int64 v15; // rax
  unsigned __int64 v16; // rsi
  unsigned __int64 v17; // r8
  Scaleform::Render::D3D1x::MeshBuffer **v18; // rcx

  v8 = 0i64;
  v9 = mbs->Buffers.Data.Size;
  if ( v9 )
  {
    Data = mbs->Buffers.Data.Data;
    do
    {
      if ( !*Data )
        break;
      ++v8;
      ++Data;
    }
    while ( v8 < v9 );
    if ( v8 == 256 )
      return 0i64;
  }
  v11 = (size + 15) & 0xFFFFFFFFFFFFFFF0ui64;
  v12 = (Scaleform::Render::D3D1x::MeshBuffer *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))pheap->vfptr->Alloc)(
                                                  pheap,
                                                  88i64);
  if ( v12 )
  {
    v12->vfptr = (Scaleform::Render::MeshBufferVtbl *)&Scaleform::Render::MeshBuffer::`vftable;
    v12->Arena = arena;
    v12->Type = type;
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
  if ( !v12->vfptr[1].__vecDelDtor(v12, (unsigned int)pdevice) )
  {
    v12->vfptr->__vecDelDtor(v12, 1u);
    return 0i64;
  }
  v12->Index = v8;
  Scaleform::AllocAddr::AddSegment(&mbs->Allocator, v8 << 24, v11 >> 4);
  mbs->TotalSize += v11;
  if ( v8 == mbs->Buffers.Data.Size )
  {
    p_Buffers = &mbs->Buffers;
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
      (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,2>,Scaleform::ArrayDefaultPolicy> *)p_Buffers,
      p_Buffers,
      v17);
LABEL_20:
    mbs->Buffers.Data.Size = v16;
    v18 = &p_Buffers->Data.Data[v16 - 1];
    if ( v18 )
      *v18 = v12;
    return (Scaleform::Render::D3D1x::IndexBuffer *)v12;
  }
  mbs->Buffers.Data.Data[v8] = v12;
  return (Scaleform::Render::D3D1x::IndexBuffer *)v12;
}

// File Line: 324
// RVA: 0xA08380
bool __fastcall Scaleform::Render::D3D1x::VertexBuffer::allocBuffer(
        Scaleform::Render::D3D1x::VertexBuffer *this,
        ID3D11Device *pdevice)
{
  ID3D10DeviceVtbl *vfptr; // rax
  int v4[3]; // [rsp+20h] [rbp-28h] BYREF
  __int64 v5; // [rsp+2Ch] [rbp-1Ch]
  int v6; // [rsp+34h] [rbp-14h]

  v4[0] = this->Size;
  vfptr = pdevice->vfptr;
  v4[1] = 2;
  v4[2] = 1;
  v5 = 0x10000i64;
  v6 = 0;
  return ((int (__fastcall *)(ID3D11Device *, int *, _QWORD, Scaleform::Ptr<ID3D11Buffer> *))vfptr->VSSetConstantBuffers)(
           pdevice,
           v4,
           0i64,
           &this->pBuffer) >= 0;
}

// File Line: 345
// RVA: 0xA080D0
bool __fastcall Scaleform::Render::D3D1x::IndexBuffer::allocBuffer(
        Scaleform::Render::D3D1x::IndexBuffer *this,
        ID3D11Device *pdevice)
{
  ID3D10DeviceVtbl *vfptr; // rax
  int v4[3]; // [rsp+20h] [rbp-28h] BYREF
  __int64 v5; // [rsp+2Ch] [rbp-1Ch]
  int v6; // [rsp+34h] [rbp-14h]

  v4[0] = this->Size;
  vfptr = pdevice->vfptr;
  v4[1] = 2;
  v4[2] = 2;
  v5 = 0x10000i64;
  v6 = 0;
  return ((int (__fastcall *)(ID3D11Device *, int *, _QWORD, Scaleform::Ptr<ID3D11Buffer> *))vfptr->VSSetConstantBuffers)(
           pdevice,
           v4,
           0i64,
           &this->pBuffer) >= 0;
}

// File Line: 454
// RVA: 0xA06E40
_BOOL8 __fastcall Scaleform::Render::D3D1x::MeshCache::AreBuffersLocked(Scaleform::Render::D3D1x::MeshCache *this)
{
  return this->Locked;
}

