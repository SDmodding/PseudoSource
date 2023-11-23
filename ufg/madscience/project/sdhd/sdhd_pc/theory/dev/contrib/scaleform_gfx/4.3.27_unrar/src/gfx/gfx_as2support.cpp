// File Line: 37
// RVA: 0x8C0EA0
Scaleform::GFx::MovieImpl *__fastcall Scaleform::GFx::AS2Support::CreateMovie(
        Scaleform::GFx::AS2Support *this,
        Scaleform::GFx::Resource *memContext)
{
  Scaleform::RefCountImplCoreVtbl *pLib; // rsi
  Scaleform::GFx::MovieImpl *v5; // rax
  Scaleform::Render::RenderBuffer *v6; // rdi
  Scaleform::GFx::MovieImpl *v7; // rax
  Scaleform::GFx::MovieImpl *v8; // rbx
  Scaleform::GFx::AS2::MovieRoot *v9; // rax
  Scaleform::Render::RenderBuffer *v10; // rax

  pLib = (Scaleform::RefCountImplCoreVtbl *)memContext->pLib;
  v5 = (Scaleform::GFx::MovieImpl *)(*((__int64 (__fastcall **)(Scaleform::RefCountImplCoreVtbl *, __int64, _QWORD))pLib->__vecDelDtor
                                     + 10))(
                                      pLib,
                                      21648i64,
                                      0i64);
  v6 = 0i64;
  if ( v5 )
  {
    Scaleform::GFx::MovieImpl::MovieImpl(v5, (Scaleform::MemoryHeap *)pLib);
    v8 = v7;
  }
  else
  {
    v8 = 0i64;
  }
  v9 = (Scaleform::GFx::AS2::MovieRoot *)(*((__int64 (__fastcall **)(Scaleform::RefCountImplCoreVtbl *, __int64, _QWORD))pLib->__vecDelDtor
                                          + 10))(
                                           pLib,
                                           1600i64,
                                           0i64);
  if ( v9 )
  {
    Scaleform::GFx::AS2::MovieRoot::MovieRoot(v9, memContext, v8, (Scaleform::GFx::Resource *)this);
    v6 = v10;
  }
  v8->Flags2 |= 1u;
  if ( v6 )
    Scaleform::RefCountImpl::Release(v6);
  return v8;
}

// File Line: 48
// RVA: 0x8BE610
Scaleform::Ptr<Scaleform::GFx::ASIMEManager> *__fastcall Scaleform::GFx::AS3Support::CreateASIMEManager(
        Scaleform::GFx::AS3Support *this,
        Scaleform::Ptr<Scaleform::GFx::ASIMEManager> *result)
{
  result->pObject = 0i64;
  return result;
}

// File Line: 60
// RVA: 0x8C0AD0
Scaleform::GFx::MemoryContext *__fastcall Scaleform::GFx::AS2Support::CreateMemoryContext(
        Scaleform::GFx::AS2Support *this,
        const char *heapName,
        Scaleform::GFx::MemoryParams *memParams,
        bool debugHeap)
{
  __int64 InitialDynamicLimit; // rax
  Scaleform::MemoryHeap *v6; // rdi
  Scaleform::GFx::AS2::MemoryContextImpl *v7; // rax
  __int64 v8; // rsi
  __int64 v9; // rax
  __int64 v10; // rbx
  Scaleform::GFx::AS2::ASRefCountCollector *v11; // rax
  Scaleform::GFx::AS2::ASRefCountCollector *v12; // rax
  Scaleform::GFx::AS2::ASRefCountCollector *v13; // r14
  Scaleform::Render::RenderBuffer *v14; // rcx
  Scaleform::GFx::ASStringManager *v15; // rax
  __int64 v16; // rax
  Scaleform::Render::RenderBuffer *v17; // rcx
  __m128i v19[2]; // [rsp+30h] [rbp-58h] BYREF
  __int128 v20; // [rsp+50h] [rbp-38h]
  __int128 v21; // [rsp+60h] [rbp-28h]

  v19[0] = *(__m128i *)&memParams->Desc.Flags;
  v19[1] = *(__m128i *)&memParams->Desc.Granularity;
  v20 = *(_OWORD *)&memParams->Desc.Threshold;
  v21 = *(_OWORD *)&memParams->Desc.HeapId;
  v19[0].m128i_i32[0] = (debugHeap ? 0x1000 : 0) | 3 | _mm_cvtsi128_si32(v19[0]);
  *(_QWORD *)&v21 = 3i64;
  InitialDynamicLimit = memParams->InitialDynamicLimit;
  if ( (_DWORD)InitialDynamicLimit == -1 )
    InitialDynamicLimit = 0x20000i64;
  *((_QWORD *)&v20 + 1) = InitialDynamicLimit;
  v6 = (Scaleform::MemoryHeap *)(*(__int64 (__fastcall **)(Scaleform::MemoryHeap *, const char *, __m128i *))&Scaleform::Memory::pGlobalHeap->vfptr->gap8[24])(
                                  Scaleform::Memory::pGlobalHeap,
                                  heapName,
                                  v19);
  Scaleform::MemoryHeap::AssignToCurrentThread(v6);
  v7 = (Scaleform::GFx::AS2::MemoryContextImpl *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))v6->vfptr->Alloc)(
                                                   v6,
                                                   104i64);
  v8 = 0i64;
  if ( v7 )
  {
    Scaleform::GFx::AS2::MemoryContextImpl::MemoryContextImpl(v7);
    v10 = v9;
  }
  else
  {
    v10 = 0i64;
  }
  *(_QWORD *)(v10 + 16) = v6;
  v11 = (Scaleform::GFx::AS2::ASRefCountCollector *)v6->vfptr->Alloc(v6, 152ui64, 0i64);
  if ( v11 )
  {
    Scaleform::GFx::AS2::ASRefCountCollector::ASRefCountCollector(v11);
    v13 = v12;
  }
  else
  {
    v13 = 0i64;
  }
  v14 = *(Scaleform::Render::RenderBuffer **)(v10 + 32);
  if ( v14 )
    Scaleform::RefCountImpl::Release(v14);
  *(_QWORD *)(v10 + 32) = v13;
  Scaleform::GFx::AS2::ASRefCountCollector::SetParams(
    v13,
    memParams->FramesBetweenCollections,
    memParams->MaxCollectionRoots);
  v15 = (Scaleform::GFx::ASStringManager *)v6->vfptr->Alloc(v6, 160ui64, 0i64);
  if ( v15 )
  {
    Scaleform::GFx::ASStringManager::ASStringManager(v15, v6);
    v8 = v16;
  }
  v17 = *(Scaleform::Render::RenderBuffer **)(v10 + 24);
  if ( v17 )
    Scaleform::RefCountImpl::Release(v17);
  *(_QWORD *)(v10 + 24) = v8;
  *(_QWORD *)(v10 + 72) = memParams->Desc.Limit;
  *(float *)(v10 + 96) = memParams->HeapLimitMultiplier;
  v6->vfptr->SetLimitHandler(v6, (Scaleform::MemoryHeap::LimitHandler *)(v10 + 48));
  Scaleform::MemoryHeap::ReleaseOnFree((ANTLR3_COMMON_TOKEN_struct *)v6, v10);
  return (Scaleform::GFx::MemoryContext *)v10;
}

// File Line: 100
// RVA: 0x8BEAB0
Scaleform::GFx::Button *__fastcall Scaleform::GFx::AS2Support::CreateCharacterInstance(
        Scaleform::GFx::AS2Support *this,
        Scaleform::GFx::MovieImpl *proot,
        Scaleform::GFx::CharacterCreateInfo *ccinfo,
        Scaleform::GFx::InteractiveObject *pparent,
        unsigned int *rid,
        unsigned int type)
{
  Scaleform::GFx::CharacterDef::CharacterDefType v9; // eax
  __int32 v10; // eax
  __int32 v11; // eax
  __int32 v12; // eax
  int v13; // eax
  char *v15; // rdi
  Scaleform::GFx::Button *v16; // rax
  Scaleform::GFx::Button *v17; // rbx
  Scaleform::GFx::StaticTextCharacter *v18; // rax
  __int64 v19; // rax
  char *v20; // rdi
  Scaleform::GFx::Button *v21; // rax
  char *v22; // rdi
  Scaleform::GFx::Button *v23; // rax
  Scaleform::GFx::AS2::GenericDisplayObj *v24; // rax
  __int64 v25; // rax
  Scaleform::GFx::ResourceId v26; // [rsp+40h] [rbp-20h] BYREF
  __int64 v27; // [rsp+48h] [rbp-18h]
  Scaleform::GFx::StaticTextCharacter *v28; // [rsp+50h] [rbp-10h]
  Scaleform::MemoryHeap *pHeap; // [rsp+58h] [rbp-8h]

  v27 = -2i64;
  v9 = type;
  if ( !type )
    v9 = ((unsigned int (__fastcall *)(Scaleform::GFx::CharacterDef *))ccinfo->pCharDef->vfptr[1].__vecDelDtor)(ccinfo->pCharDef);
  v10 = v9 - 1;
  if ( v10 )
  {
    v11 = v10 - 2;
    if ( v11 )
    {
      v12 = v11 - 1;
      if ( v12 )
      {
        v13 = v12 - 1;
        if ( v13 )
        {
          if ( v13 != 1 )
            return 0i64;
          v15 = (char *)proot->pHeap->vfptr->Alloc(proot->pHeap, 424i64, 0i64);
          v28 = (Scaleform::GFx::StaticTextCharacter *)v15;
          pHeap = (Scaleform::MemoryHeap *)v15;
          if ( v15 )
          {
            type = *rid;
            Scaleform::GFx::Button::Button(
              (Scaleform::GFx::Button *)v15,
              (Scaleform::GFx::ButtonDef *)ccinfo->pCharDef,
              ccinfo->pBindDefImpl,
              proot->pASMovieRoot.pObject,
              pparent,
              &type);
            v17 = v16;
          }
          else
          {
            v17 = 0i64;
          }
          pHeap = (Scaleform::MemoryHeap *)(v15 + 368);
          if ( v15 != (char *)-368i64 )
            Scaleform::GFx::AS2::AvmButton::AvmButton((Scaleform::GFx::AS2::AvmButton *)(v15 + 368), v17);
        }
        else
        {
          pHeap = proot->pHeap;
          v18 = (Scaleform::GFx::StaticTextCharacter *)pHeap->vfptr->Alloc((Scaleform::MemoryHeap *)this, 400ui64, 0i64);
          v28 = v18;
          if ( v18 )
          {
            type = *rid;
            Scaleform::GFx::StaticTextCharacter::StaticTextCharacter(
              v18,
              (Scaleform::GFx::StaticTextDef *)ccinfo->pCharDef,
              ccinfo->pBindDefImpl,
              proot->pASMovieRoot.pObject);
            return (Scaleform::GFx::Button *)v19;
          }
          else
          {
            return 0i64;
          }
        }
      }
      else
      {
        v20 = (char *)proot->pHeap->vfptr->Alloc(proot->pHeap, 408i64, 0i64);
        pHeap = (Scaleform::MemoryHeap *)v20;
        v28 = (Scaleform::GFx::StaticTextCharacter *)v20;
        if ( v20 )
        {
          type = *rid;
          Scaleform::GFx::TextField::TextField(
            (Scaleform::GFx::TextField *)v20,
            (Scaleform::GFx::TextFieldDef *)ccinfo->pCharDef,
            ccinfo->pBindDefImpl,
            proot->pASMovieRoot.pObject,
            pparent,
            (Scaleform::MemoryHeap *)&type);
          v17 = v21;
        }
        else
        {
          v17 = 0i64;
        }
        v28 = (Scaleform::GFx::StaticTextCharacter *)(v20 + 312);
        if ( v20 != (char *)-312i64 )
          Scaleform::GFx::AS2::AvmTextField::AvmTextField(
            (Scaleform::GFx::AS2::AvmTextField *)(v20 + 312),
            (Scaleform::GFx::TextField *)v17);
      }
    }
    else
    {
      v22 = (char *)proot->pHeap->vfptr->Alloc(proot->pHeap, 824i64, 0i64);
      pHeap = (Scaleform::MemoryHeap *)v22;
      v28 = (Scaleform::GFx::StaticTextCharacter *)v22;
      if ( v22 )
      {
        type = *rid;
        Scaleform::GFx::Sprite::Sprite(
          (Scaleform::GFx::Sprite *)v22,
          (Scaleform::GFx::TimelineDef *)ccinfo->pCharDef,
          ccinfo->pBindDefImpl,
          proot->pASMovieRoot.pObject,
          pparent,
          &type,
          0);
        v17 = v23;
      }
      else
      {
        v17 = 0i64;
      }
      v28 = (Scaleform::GFx::StaticTextCharacter *)(v22 + 320);
      if ( v22 != (char *)-320i64 )
        Scaleform::GFx::AS2::AvmSprite::AvmSprite(
          (Scaleform::GFx::AS2::AvmSprite *)(v22 + 320),
          (Scaleform::GFx::Sprite *)v17);
    }
  }
  else
  {
    type = 322;
    v24 = (Scaleform::GFx::AS2::GenericDisplayObj *)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                                                      Scaleform::Memory::pGlobalHeap,
                                                      pparent,
                                                      120i64,
                                                      &type);
    pHeap = (Scaleform::MemoryHeap *)v24;
    if ( v24 )
    {
      v26.Id = *rid;
      Scaleform::GFx::AS2::GenericDisplayObj::GenericDisplayObj(
        v24,
        (Scaleform::GFx::ShapeBaseCharacterDef *)ccinfo->pCharDef,
        proot->pASMovieRoot.pObject,
        pparent,
        &v26);
      return (Scaleform::GFx::Button *)v25;
    }
    else
    {
      return 0i64;
    }
  }
  return v17;
}

// File Line: 181
// RVA: 0x8A7130
void __fastcall Scaleform::GFx::AS2::PlaceObject2EH::~PlaceObject2EH(Scaleform::GFx::AS2::PlaceObject2EH *this)
{
  __int64 v2; // rsi
  unsigned __int64 v3; // rbx
  unsigned __int64 v4; // rbp
  _QWORD *v5; // rdi
  Scaleform::Render::RenderBuffer *v6; // rcx

  this->vfptr = (Scaleform::GFx::ExecuteTagVtbl *)&Scaleform::GFx::AS2::PlaceObject2EH::`vftable;
  if ( this->pData[0] < 0 )
  {
    v2 = *(_QWORD *)&this->pData[1];
    if ( v2 )
    {
      v3 = 0i64;
      v4 = *(_QWORD *)(v2 + 8);
      if ( v4 )
      {
        do
        {
          v5 = *(_QWORD **)(*(_QWORD *)v2 + 8 * v3);
          if ( v5 )
          {
            v6 = (Scaleform::Render::RenderBuffer *)v5[3];
            if ( v6 )
              Scaleform::RefCountImpl::Release(v6);
            Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v5);
          }
          ++v3;
        }
        while ( v3 < v4 );
      }
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, *(void **)v2);
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, (void *)v2);
    }
  }
  this->vfptr = (Scaleform::GFx::ExecuteTagVtbl *)&Scaleform::GFx::PlaceObject2Tag::`vftable;
  this->vfptr = (Scaleform::GFx::ExecuteTagVtbl *)&Scaleform::GFx::ExecuteTag::`vftable;
}

// File Line: 198
// RVA: 0x915680
void __fastcall Scaleform::GFx::PlaceObject2Tag::Unpack(
        Scaleform::GFx::PlaceObject2Tag *this,
        Scaleform::GFx::GFxPlaceObjectBase::UnpackedData *data)
{
  Scaleform::GFx::PlaceObject2Tag::UnpackBase(this, data, 6);
}

// File Line: 202
// RVA: 0x8C9F80
void __fastcall Scaleform::GFx::PlaceObject2Tag::Execute(
        Scaleform::GFx::PlaceObject2Tag *this,
        Scaleform::GFx::DisplayObjContainer *m)
{
  Scaleform::GFx::PlaceObject2Tag::ExecuteBase(this, m, 6);
}

// File Line: 212
// RVA: 0x915690
void __fastcall Scaleform::GFx::PlaceObject2Taga::Unpack(
        Scaleform::GFx::PlaceObject2Taga *this,
        Scaleform::GFx::GFxPlaceObjectBase::UnpackedData *data)
{
  Scaleform::GFx::PlaceObject2Tag::UnpackBase(this, data, 3);
}

// File Line: 216
// RVA: 0x8C9F90
void __fastcall Scaleform::GFx::AS2::PlaceObject2EHa::Execute(
        Scaleform::GFx::PlaceObject2Taga *this,
        Scaleform::GFx::DisplayObjContainer *m)
{
  Scaleform::GFx::PlaceObject2Tag::ExecuteBase(this, m, 3);
}

// File Line: 221
// RVA: 0x8F0F90
void __fastcall Scaleform::GFx::AS2::PlaceObject2EHa::ProcessEventHandlers(
        Scaleform::GFx::AS2::PlaceObject2EHa *this,
        Scaleform::GFx::GFxPlaceObjectBase::UnpackedData *data,
        Scaleform::GFx::StreamContext *sc,
        const char *prawdata)
{
  Scaleform::GFx::AS2::PlaceObject2EH::ProcessEventHandlers(this, data, sc, prawdata, 3u);
}

// File Line: 232
// RVA: 0x8A7240
void __fastcall Scaleform::GFx::AS2::PlaceObject3EH::~PlaceObject3EH(Scaleform::GFx::AS2::PlaceObject3EH *this)
{
  __int64 v2; // rsi
  unsigned __int64 v3; // rbx
  unsigned __int64 v4; // rbp
  _QWORD *v5; // rdi
  Scaleform::Render::RenderBuffer *v6; // rcx

  this->vfptr = (Scaleform::GFx::ExecuteTagVtbl *)&Scaleform::GFx::AS2::PlaceObject3EH::`vftable;
  if ( this->pData[0] < 0 )
  {
    v2 = *(_QWORD *)&this->pData[1];
    if ( v2 )
    {
      v3 = 0i64;
      v4 = *(_QWORD *)(v2 + 8);
      if ( v4 )
      {
        do
        {
          v5 = *(_QWORD **)(*(_QWORD *)v2 + 8 * v3);
          if ( v5 )
          {
            v6 = (Scaleform::Render::RenderBuffer *)v5[3];
            if ( v6 )
              Scaleform::RefCountImpl::Release(v6);
            Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v5);
          }
          ++v3;
        }
        while ( v3 < v4 );
      }
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, *(void **)v2);
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, (void *)v2);
    }
  }
  this->vfptr = (Scaleform::GFx::ExecuteTagVtbl *)&Scaleform::GFx::PlaceObject3Tag::`vftable;
  this->vfptr = (Scaleform::GFx::ExecuteTagVtbl *)&Scaleform::GFx::ExecuteTag::`vftable;
}

// File Line: 254
// RVA: 0x8F0DA0
void __fastcall Scaleform::GFx::AS2::PlaceObject2EH::ProcessEventHandlers(
        Scaleform::GFx::AS2::PlaceObject2EH *this,
        Scaleform::GFx::GFxPlaceObjectBase::UnpackedData *data,
        Scaleform::GFx::StreamContext *sc,
        const char *prawdata,
        unsigned __int8 version)
{
  Scaleform::ArrayLH<Scaleform::GFx::SwfEvent *,260,Scaleform::ArrayDefaultPolicy> *v8; // rax
  unsigned __int64 CurByteIndex; // rax
  unsigned __int64 v10; // rax
  Scaleform::ArrayLH<Scaleform::GFx::SwfEvent *,260,Scaleform::ArrayDefaultPolicy> *v11; // rax
  Scaleform::ArrayLH<Scaleform::GFx::SwfEvent *,260,Scaleform::ArrayDefaultPolicy> *v12; // rsi
  unsigned __int64 v13; // rdx
  int v14; // ebp
  unsigned __int64 v15; // rax
  __int64 v16; // rax
  Scaleform::GFx::AS2::AvmSwfEvent *v17; // rbx
  unsigned __int64 Size; // rax
  unsigned __int64 v19; // rbp
  unsigned __int64 v20; // r8
  Scaleform::GFx::AS2::AvmSwfEvent **v21; // rcx

  v8 = *(Scaleform::ArrayLH<Scaleform::GFx::SwfEvent *,260,Scaleform::ArrayDefaultPolicy> **)(prawdata + 1);
  if ( !v8 )
  {
    if ( sc->CurBitIndex )
      ++sc->CurByteIndex;
    sc->CurBitIndex = 0;
    sc->CurByteIndex += 2i64;
    CurByteIndex = sc->CurByteIndex;
    sc->CurBitIndex = 0;
    if ( version < 6u )
      v10 = CurByteIndex + 2;
    else
      v10 = CurByteIndex + 4;
    sc->CurByteIndex = v10;
    v11 = (Scaleform::ArrayLH<Scaleform::GFx::SwfEvent *,260,Scaleform::ArrayDefaultPolicy> *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                                                                                Scaleform::Memory::pGlobalHeap,
                                                                                                24i64);
    v12 = v11;
    if ( v11 )
    {
      v11->Data.Data = 0i64;
      v11->Data.Size = 0i64;
      v11->Data.Policy.Capacity = 0i64;
    }
    else
    {
      v12 = 0i64;
    }
    while ( 1 )
    {
      if ( sc->CurBitIndex )
        ++sc->CurByteIndex;
      sc->CurBitIndex = 0;
      sc->CurBitIndex = 0;
      v13 = sc->CurByteIndex;
      if ( version < 6u )
      {
        v15 = v13 + 2;
        v14 = *(unsigned __int16 *)&sc->pData[v13];
      }
      else
      {
        v14 = (unsigned __int8)sc->pData[v13] | (((unsigned __int8)sc->pData[v13 + 1] | (*(unsigned __int16 *)&sc->pData[v13 + 2] << 8)) << 8);
        v15 = v13 + 4;
      }
      sc->CurByteIndex = v15;
      if ( !v14 )
      {
        *(_QWORD *)&this->pData[1] = v12;
        data->pEventHandlers = v12;
        return;
      }
      v16 = ((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
              Scaleform::Memory::pGlobalHeap,
              32i64);
      v17 = (Scaleform::GFx::AS2::AvmSwfEvent *)v16;
      if ( v16 )
      {
        *(_QWORD *)v16 = 0i64;
        *(_DWORD *)(v16 + 8) = 0;
        *(_BYTE *)(v16 + 12) = 0;
        *(_DWORD *)(v16 + 16) = 65280;
        *(_QWORD *)(v16 + 24) = 0i64;
      }
      else
      {
        v17 = 0i64;
      }
      Scaleform::GFx::AS2::AvmSwfEvent::Read(v17, sc, v14);
      Size = v12->Data.Size;
      v19 = Size + 1;
      if ( Size + 1 >= Size )
      {
        if ( v19 > v12->Data.Policy.Capacity )
        {
          v20 = v19 + (v19 >> 2);
          goto LABEL_24;
        }
      }
      else if ( v19 < v12->Data.Policy.Capacity >> 1 )
      {
        v20 = Size + 1;
LABEL_24:
        Scaleform::ArrayDataBase<Scaleform::GFx::SwfEvent *,Scaleform::AllocatorLH<Scaleform::GFx::SwfEvent *,260>,Scaleform::ArrayDefaultPolicy>::Reserve(
          &v12->Data,
          v12,
          v20);
      }
      v12->Data.Size = v19;
      v21 = &v12->Data.Data[v19 - 1];
      if ( v21 )
        *v21 = v17;
    }
  }
  data->pEventHandlers = v8;
}

// File Line: 296
// RVA: 0x8F0FA0
void __fastcall Scaleform::GFx::AS2::PlaceObject3EH::ProcessEventHandlers(
        Scaleform::GFx::AS2::PlaceObject3EH *this,
        Scaleform::GFx::GFxPlaceObjectBase::UnpackedData *data,
        Scaleform::GFx::StreamContext *sc,
        const char *__formal)
{
  Scaleform::ArrayLH<Scaleform::GFx::SwfEvent *,260,Scaleform::ArrayDefaultPolicy> *v7; // rax
  Scaleform::ArrayLH<Scaleform::GFx::SwfEvent *,260,Scaleform::ArrayDefaultPolicy> *v8; // rax
  Scaleform::ArrayLH<Scaleform::GFx::SwfEvent *,260,Scaleform::ArrayDefaultPolicy> *v9; // rdi
  unsigned __int64 CurByteIndex; // rdx
  const char *v11; // rcx
  bool v12; // zf
  int v13; // esi
  __int64 v14; // rax
  Scaleform::GFx::AS2::AvmSwfEvent *v15; // rbx
  unsigned __int64 Size; // rax
  unsigned __int64 v17; // rsi
  unsigned __int64 v18; // r8
  Scaleform::GFx::AS2::AvmSwfEvent **v19; // rcx

  v7 = *(Scaleform::ArrayLH<Scaleform::GFx::SwfEvent *,260,Scaleform::ArrayDefaultPolicy> **)&this->pData[1];
  if ( !v7 )
  {
    if ( sc->CurBitIndex )
      ++sc->CurByteIndex;
    sc->CurBitIndex = 0;
    sc->CurByteIndex += 6i64;
    v8 = (Scaleform::ArrayLH<Scaleform::GFx::SwfEvent *,260,Scaleform::ArrayDefaultPolicy> *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64, _QWORD, const char *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                                                                               Scaleform::Memory::pGlobalHeap,
                                                                                               24i64,
                                                                                               0i64,
                                                                                               __formal,
                                                                                               -2i64);
    v9 = v8;
    if ( v8 )
    {
      v8->Data.Data = 0i64;
      v8->Data.Size = 0i64;
      v8->Data.Policy.Capacity = 0i64;
    }
    else
    {
      v9 = 0i64;
    }
    while ( 1 )
    {
      if ( sc->CurBitIndex )
        ++sc->CurByteIndex;
      sc->CurBitIndex = 0;
      CurByteIndex = sc->CurByteIndex;
      v11 = &sc->pData[CurByteIndex];
      v12 = (*(unsigned __int8 *)v11 | ((*((unsigned __int8 *)v11 + 1) | (*((unsigned __int16 *)v11 + 1) << 8)) << 8)) == 0;
      v13 = *(unsigned __int8 *)v11 | ((*((unsigned __int8 *)v11 + 1) | (*((unsigned __int16 *)v11 + 1) << 8)) << 8);
      sc->CurByteIndex = CurByteIndex + 4;
      if ( v12 )
      {
        *(_QWORD *)&this->pData[1] = v9;
        data->pEventHandlers = v9;
        return;
      }
      v14 = ((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
              Scaleform::Memory::pGlobalHeap,
              32i64);
      v15 = (Scaleform::GFx::AS2::AvmSwfEvent *)v14;
      if ( v14 )
      {
        *(_QWORD *)v14 = 0i64;
        *(_DWORD *)(v14 + 8) = 0;
        *(_BYTE *)(v14 + 12) = 0;
        *(_DWORD *)(v14 + 16) = 65280;
        *(_QWORD *)(v14 + 24) = 0i64;
      }
      else
      {
        v15 = 0i64;
      }
      Scaleform::GFx::AS2::AvmSwfEvent::Read(v15, sc, v13);
      Size = v9->Data.Size;
      v17 = Size + 1;
      if ( Size + 1 >= Size )
      {
        if ( v17 > v9->Data.Policy.Capacity )
        {
          v18 = v17 + (v17 >> 2);
          goto LABEL_18;
        }
      }
      else if ( v17 < v9->Data.Policy.Capacity >> 1 )
      {
        v18 = Size + 1;
LABEL_18:
        Scaleform::ArrayDataBase<Scaleform::GFx::SwfEvent *,Scaleform::AllocatorLH<Scaleform::GFx::SwfEvent *,260>,Scaleform::ArrayDefaultPolicy>::Reserve(
          &v9->Data,
          v9,
          v18);
      }
      v9->Data.Size = v17;
      v19 = &v9->Data.Data[v17 - 1];
      if ( v19 )
        *v19 = v15;
    }
  }
  data->pEventHandlers = v7;
}

// File Line: 370
// RVA: 0x8BA980
void __fastcall Scaleform::GFx::AS2::RemoveObjectEH::CheckEventHandlers(
        Scaleform::GFx::AS2::RemoveObjectEH *this,
        void **pse,
        Scaleform::ArrayLH<Scaleform::GFx::SwfEvent *,260,Scaleform::ArrayDefaultPolicy> *pevts)
{
  unsigned __int64 Size; // r10
  _BYTE *v4; // r9
  unsigned __int64 v5; // rcx
  Scaleform::GFx::SwfEvent **Data; // r8

  Size = pevts->Data.Size;
  v4 = *pse;
  v5 = 0i64;
  if ( Size )
  {
    Data = pevts->Data.Data;
    while ( ((*Data)->Event.Id & 4) == 0 )
    {
      ++v5;
      ++Data;
      if ( v5 >= Size )
        goto LABEL_5;
    }
    v4[105] |= 2u;
    *pse = 0i64;
  }
  else
  {
LABEL_5:
    *pse = v4;
  }
}

// File Line: 389
// RVA: 0x8F58D0
void __fastcall Scaleform::GFx::AS2::ButtonAction::Read(
        Scaleform::GFx::AS2::ButtonAction *this,
        Scaleform::GFx::Stream *pin,
        Scaleform::GFx::TagType tagType,
        unsigned int actionLength)
{
  unsigned int v4; // esi
  __int64 Pos; // r9
  unsigned __int16 v8; // r8
  Scaleform::GFx::AS2::ActionBufferData *New; // rdi
  Scaleform::Ptr<Scaleform::GFx::AS2::ActionBufferData> *v10; // rbx

  if ( actionLength )
  {
    v4 = actionLength;
    if ( tagType == Tag_ButtonCharacter )
    {
      this->Conditions = 8;
    }
    else
    {
      pin->UnusedBits = 0;
      if ( (signed int)(pin->DataSize - pin->Pos) < 2 )
        Scaleform::GFx::Stream::PopulateBuffer(pin, 2);
      Pos = pin->Pos;
      v8 = (unsigned __int8)pin->pBuffer[Pos] | ((unsigned __int8)pin->pBuffer[(unsigned int)(Pos + 1)] << 8);
      pin->Pos = Pos + 2;
      this->Conditions = v8;
      v4 -= 2;
    }
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(pin, "-- action conditions %X\n");
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(pin, "-- actions in button\n");
    New = Scaleform::GFx::AS2::ActionBufferData::CreateNew();
    Scaleform::GFx::AS2::ActionBufferData::Read(New, pin, v4);
    Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ButtonActionBase>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ButtonActionBase>,258>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ButtonActionBase>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ButtonActionBase>,258>,Scaleform::ArrayDefaultPolicy> *)&this->Actions,
      &this->Actions,
      this->Actions.Data.Size + 1);
    v10 = &this->Actions.Data.Data[this->Actions.Data.Size - 1];
    if ( v10 )
    {
      if ( New )
        Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)New);
      v10->pObject = New;
    }
    if ( New )
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)New);
  }
}

// File Line: 424
// RVA: 0x8F6680
void __fastcall Scaleform::GFx::AS2::DoActionTag::Read(
        Scaleform::GFx::AS2::DoActionTag *this,
        Scaleform::GFx::LoadProcess *p)
{
  Scaleform::GFx::SWFProcessInfo *pAltStream; // rdi
  Scaleform::GFx::AS2::ActionBufferData *New; // rax
  Scaleform::Render::RenderBuffer *pObject; // rcx
  Scaleform::GFx::AS2::ActionBufferData *v7; // rbp
  Scaleform::GFx::SWFProcessInfo *v8; // rcx
  Scaleform::GFx::SWFProcessInfo *p_ProcessInfo; // rdx
  __int64 v10; // rax
  int v11; // r9d

  pAltStream = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  if ( !pAltStream )
    pAltStream = &p->ProcessInfo;
  New = Scaleform::GFx::AS2::ActionBufferData::CreateNew();
  pObject = (Scaleform::Render::RenderBuffer *)this->pBuf.pObject;
  v7 = New;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  this->pBuf.pObject = v7;
  v8 = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  p_ProcessInfo = &p->ProcessInfo;
  if ( v8 )
    p_ProcessInfo = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  v10 = p_ProcessInfo->Stream.TagStackEntryCount - 1;
  if ( (unsigned int)v10 >= 2 )
    v11 = 0;
  else
    v11 = p_ProcessInfo->Stream.TagStack[v10];
  if ( !v8 )
    v8 = &p->ProcessInfo;
  Scaleform::GFx::AS2::ActionBufferData::Read(
    v7,
    &pAltStream->Stream,
    v11 + v8->Stream.DataSize - v8->Stream.FilePos - v8->Stream.Pos);
}

// File Line: 448
// RVA: 0x8C9380
void __fastcall Scaleform::GFx::AS2::DoActionTag::Execute(
        Scaleform::GFx::AS2::DoActionTag *this,
        Scaleform::GFx::DisplayObjContainer *m)
{
  Scaleform::GFx::AS2::AvmSprite *v3; // rdi
  __int64 v4; // rax
  Scaleform::GFx::AS2::ActionBufferData *pObject; // rcx
  char *pBuffer; // rcx
  Scaleform::GFx::AS2::ASStringContext *v7; // rbx
  Scaleform::GFx::AS2::ActionBuffer *v8; // rax
  Scaleform::GFx::AS2::ActionBuffer *v9; // rax
  Scaleform::GFx::AS2::ActionBuffer *v10; // rbx

  v3 = (Scaleform::GFx::AS2::AvmSprite *)((char *)m + 4 * (unsigned __int8)m->AvmObjOffset);
  v4 = ((__int64 (__fastcall *)(Scaleform::GFx::AS2::AvmSprite *))v3->Scaleform::GFx::AS2::AvmCharacter::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::vfptr[2].GetAbsolutePath)(v3);
  pObject = this->pBuf.pObject;
  if ( pObject )
  {
    if ( pObject->BufferLen )
    {
      pBuffer = pObject->pBuffer;
      if ( *pBuffer )
      {
        v7 = (Scaleform::GFx::AS2::ASStringContext *)(v4 + 232);
        v8 = (Scaleform::GFx::AS2::ActionBuffer *)(*(__int64 (__fastcall **)(char *, __int64))(**(_QWORD **)(*(_QWORD *)(v4 + 232) + 48i64)
                                                                                             + 80i64))(
                                                    pBuffer,
                                                    64i64);
        if ( v8 )
        {
          Scaleform::GFx::AS2::ActionBuffer::ActionBuffer(v8, v7, (Scaleform::GFx::Resource *)this->pBuf.pObject);
          v10 = v9;
        }
        else
        {
          v10 = 0i64;
        }
        Scaleform::GFx::AS2::AvmSprite::AddActionBuffer(v3, v10, AP_Frame);
        if ( v10 )
          Scaleform::RefCountNTSImpl::Release(v10);
      }
    }
  }
}

// File Line: 460
// RVA: 0x8CB190
void __fastcall Scaleform::GFx::AS2::DoActionTag::ExecuteWithPriority(
        Scaleform::GFx::AS2::DoActionTag *this,
        Scaleform::GFx::DisplayObjContainer *m,
        Scaleform::GFx::ActionPriority::Priority prio)
{
  Scaleform::GFx::AS2::AvmSprite *v5; // rdi
  Scaleform::GFx::AS2::ActionBufferData *pObject; // rax
  Scaleform::GFx::AS2::ASStringContext *v7; // r14
  __int64 v8; // rcx
  Scaleform::GFx::AS2::ActionBuffer *v9; // rax
  Scaleform::GFx::AS2::ActionBuffer *v10; // rax
  Scaleform::GFx::AS2::ActionBuffer *v11; // rbx

  v5 = (Scaleform::GFx::AS2::AvmSprite *)((char *)m + 4 * (unsigned __int8)m->AvmObjOffset);
  pObject = this->pBuf.pObject;
  if ( pObject && pObject->BufferLen && *pObject->pBuffer )
  {
    v7 = (Scaleform::GFx::AS2::ASStringContext *)(((__int64 (__fastcall *)(char *))v5->Scaleform::GFx::AS2::AvmCharacter::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::vfptr[2].GetAbsolutePath)((char *)m + 4 * (unsigned __int8)m->AvmObjOffset)
                                                + 232);
    v9 = (Scaleform::GFx::AS2::ActionBuffer *)((__int64 (__fastcall *)(__int64, __int64))v7->pContext->pHeap->vfptr->Alloc)(
                                                v8,
                                                64i64);
    if ( v9 )
    {
      Scaleform::GFx::AS2::ActionBuffer::ActionBuffer(v9, v7, (Scaleform::GFx::Resource *)this->pBuf.pObject);
      v11 = v10;
    }
    else
    {
      v11 = 0i64;
    }
    Scaleform::GFx::AS2::AvmSprite::AddActionBuffer(v5, v11, prio);
    if ( v11 )
      Scaleform::RefCountNTSImpl::Release(v11);
  }
}

// File Line: 496
// RVA: 0x8C9440
void __fastcall Scaleform::GFx::AS2::DoInitActionTag::Execute(
        Scaleform::GFx::AS2::DoInitActionTag *this,
        Scaleform::GFx::DisplayObjContainer *m)
{
  Scaleform::GFx::AS2::ActionBufferData *pObject; // rax
  Scaleform::GFx::AS2::AvmSprite *v4; // rdi
  Scaleform::GFx::AS2::ASStringContext *v5; // rsi
  __int64 v6; // rcx
  Scaleform::GFx::AS2::ActionBuffer *v7; // rax
  Scaleform::GFx::AS2::ActionBuffer *v8; // rax
  Scaleform::GFx::AS2::ActionBuffer *v9; // rbx

  pObject = this->pBuf.pObject;
  if ( pObject && pObject->BufferLen && *pObject->pBuffer )
  {
    v4 = (Scaleform::GFx::AS2::AvmSprite *)((char *)m + 4 * (unsigned __int8)m->AvmObjOffset);
    v5 = (Scaleform::GFx::AS2::ASStringContext *)(((__int64 (__fastcall *)(Scaleform::GFx::AS2::AvmSprite *))v4->Scaleform::GFx::AS2::AvmCharacter::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::vfptr[2].GetAbsolutePath)(v4)
                                                + 232);
    v7 = (Scaleform::GFx::AS2::ActionBuffer *)((__int64 (__fastcall *)(__int64, __int64))v5->pContext->pHeap->vfptr->Alloc)(
                                                v6,
                                                64i64);
    if ( v7 )
    {
      Scaleform::GFx::AS2::ActionBuffer::ActionBuffer(v7, v5, (Scaleform::GFx::Resource *)this->pBuf.pObject);
      v9 = v8;
    }
    else
    {
      v9 = 0i64;
    }
    Scaleform::GFx::AS2::AvmSprite::AddActionBuffer(v4, v9, AP_InitClip);
    if ( v9 )
      Scaleform::RefCountNTSImpl::Release(v9);
  }
}

// File Line: 517
// RVA: 0x8FAB60
void __fastcall Scaleform::GFx::AS2Support::ReadButtonActions(
        Scaleform::GFx::AS2Support *this,
        Scaleform::GFx::LoadProcess *p,
        Scaleform::GFx::ButtonDef *pbuttonDef,
        unsigned int tagType)
{
  __int64 v7; // rbx
  int v8; // edi
  Scaleform::GFx::SWFProcessInfo *pAltStream; // rdx
  Scaleform::GFx::SWFProcessInfo *p_ProcessInfo; // r8
  Scaleform::GFx::SWFProcessInfo *v11; // rcx
  __int64 v12; // rax

  v7 = ((__int64 (__fastcall *)(Scaleform::GFx::AS2Support *, __int64))p->pLoadData.pObject->pHeap->vfptr->Alloc)(
         this,
         48i64);
  if ( v7 )
  {
    *(_QWORD *)v7 = &Scaleform::RefCountImplCore::`vftable;
    *(_DWORD *)(v7 + 8) = 1;
    *(_QWORD *)v7 = &Scaleform::RefCountImpl::`vftable;
    *(_QWORD *)v7 = &Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,258>::`vftable;
    *(_QWORD *)v7 = &Scaleform::RefCountBase<Scaleform::GFx::ButtonActionBase,258>::`vftable;
    *(_QWORD *)v7 = &Scaleform::GFx::ButtonActionBase::`vftable;
    *(_QWORD *)v7 = &Scaleform::GFx::AS2::ButtonAction::`vftable;
    v8 = 0;
    *(_QWORD *)(v7 + 24) = 0i64;
    *(_QWORD *)(v7 + 32) = 0i64;
    *(_QWORD *)(v7 + 40) = 0i64;
  }
  else
  {
    v8 = 0;
    v7 = 0i64;
  }
  Scaleform::GFx::ButtonDef::AddButtonAction(pbuttonDef, (Scaleform::GFx::Resource *)v7);
  pAltStream = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  p_ProcessInfo = &p->ProcessInfo;
  if ( pAltStream )
  {
    p_ProcessInfo = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
    v11 = p_ProcessInfo;
  }
  else
  {
    v11 = &p->ProcessInfo;
  }
  v12 = v11->Stream.TagStackEntryCount - 1;
  if ( (unsigned int)v12 < 2 )
    v8 = v11->Stream.TagStack[v12];
  if ( !pAltStream )
    pAltStream = &p->ProcessInfo;
  (*(void (__fastcall **)(__int64, Scaleform::GFx::SWFProcessInfo *, _QWORD, _QWORD))(*(_QWORD *)v7 + 8i64))(
    v7,
    pAltStream,
    tagType,
    v8 + p_ProcessInfo->Stream.DataSize - p_ProcessInfo->Stream.FilePos - p_ProcessInfo->Stream.Pos);
  Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v7);
}

// File Line: 526
// RVA: 0x8FA8F0
void __fastcall Scaleform::GFx::AS2Support::ReadButton2ActionConditions(
        Scaleform::GFx::AS2Support *this,
        Scaleform::GFx::LoadProcess *p,
        Scaleform::GFx::ButtonDef *pbuttonDef,
        unsigned int tagType)
{
  Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::ButtonActionBase>,258,Scaleform::ArrayDefaultPolicy> *p_ButtonActions; // r12
  Scaleform::GFx::SWFProcessInfo *pAltStream; // rbx
  __int64 Pos; // r9
  unsigned __int16 v9; // r8
  int v10; // r15d
  unsigned int v11; // r14d
  signed int v12; // ebp
  __int64 v13; // rcx
  __int64 v14; // rbx
  _QWORD *p_pObject; // rdi
  int TagEndPosition; // r14d
  __int64 v17; // rdi
  Scaleform::GFx::SWFProcessInfo *Stream; // rax
  int v19; // edi
  Scaleform::GFx::SWFProcessInfo *p_ProcessInfo; // rdi
  signed int FilePos; // edx
  unsigned int DataSize; // eax
  __int64 v23; // [rsp+20h] [rbp-68h]
  __int64 v24; // [rsp+28h] [rbp-60h]
  __int64 v25; // [rsp+30h] [rbp-58h]

  v23 = -2i64;
  p_ButtonActions = &pbuttonDef->ButtonActions;
  while ( 1 )
  {
    pAltStream = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
    if ( !pAltStream )
      pAltStream = &p->ProcessInfo;
    pAltStream->Stream.UnusedBits = 0;
    if ( (signed int)(pAltStream->Stream.DataSize - pAltStream->Stream.Pos) < 2 )
      Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
    Pos = pAltStream->Stream.Pos;
    v9 = (unsigned __int8)pAltStream->Stream.pBuffer[Pos] | ((unsigned __int8)pAltStream->Stream.pBuffer[(unsigned int)(Pos + 1)] << 8);
    pAltStream->Stream.Pos = Pos + 2;
    v10 = v9;
    v11 = v9 - 2;
    v12 = v11 + Scaleform::GFx::LoadProcess::Tell(p);
    v14 = ((__int64 (__fastcall *)(__int64, __int64))p->pLoadData.pObject->pHeap->vfptr->Alloc)(v13, 48i64);
    if ( v14 )
    {
      *(_QWORD *)v14 = &Scaleform::RefCountImplCore::`vftable;
      *(_DWORD *)(v14 + 8) = 1;
      *(_QWORD *)v14 = &Scaleform::RefCountImpl::`vftable;
      *(_QWORD *)v14 = &Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,258>::`vftable;
      *(_QWORD *)v14 = &Scaleform::RefCountBase<Scaleform::GFx::ButtonActionBase,258>::`vftable;
      *(_QWORD *)v14 = &Scaleform::GFx::ButtonActionBase::`vftable;
      *(_QWORD *)v14 = &Scaleform::GFx::AS2::ButtonAction::`vftable;
      v24 = v14 + 24;
      v25 = v14 + 24;
      *(_QWORD *)(v14 + 24) = 0i64;
      *(_QWORD *)(v14 + 32) = 0i64;
      *(_QWORD *)(v14 + 40) = 0i64;
    }
    else
    {
      v14 = 0i64;
    }
    if ( v14 )
      Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)v14);
    Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ButtonActionBase>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ButtonActionBase>,258>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      &p_ButtonActions->Data,
      p_ButtonActions,
      p_ButtonActions->Data.Size + 1);
    p_pObject = &p_ButtonActions->Data.Data[p_ButtonActions->Data.Size - 1].pObject;
    if ( p_pObject )
    {
      if ( v14 )
        Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)v14);
      *p_pObject = v14;
    }
    if ( v14 )
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v14);
    if ( !v10 )
    {
      TagEndPosition = Scaleform::GFx::LoadProcess::GetTagEndPosition(p);
      v11 = TagEndPosition - Scaleform::GFx::LoadProcess::Tell(p);
    }
    v17 = *(_QWORD *)v14;
    Stream = Scaleform::GFx::LoadProcess::GetStream(p);
    (*(void (__fastcall **)(__int64, Scaleform::GFx::SWFProcessInfo *, _QWORD, _QWORD, __int64, __int64, __int64, __int64, __int64))(v17 + 8))(
      v14,
      Stream,
      tagType,
      v11,
      v23,
      v24,
      v25,
      v14,
      v14);
    if ( !v10 )
      break;
    v19 = Scaleform::GFx::LoadProcess::Tell(p);
    if ( v19 >= (int)Scaleform::GFx::LoadProcess::GetTagEndPosition(p) )
      break;
    p_ProcessInfo = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
    if ( !p_ProcessInfo )
      p_ProcessInfo = &p->ProcessInfo;
    p_ProcessInfo->Stream.UnusedBits = 0;
    FilePos = p_ProcessInfo->Stream.FilePos;
    DataSize = p_ProcessInfo->Stream.DataSize;
    if ( v12 < (int)(FilePos - DataSize) || v12 >= FilePos )
    {
      if ( (p_ProcessInfo->Stream.ResyncFile || p_ProcessInfo->Stream.Pos + FilePos - DataSize != v12)
        && ((int (__fastcall *)(Scaleform::File *, _QWORD, _QWORD))p_ProcessInfo->Stream.pInput.pObject->vfptr[14].__vecDelDtor)(
             p_ProcessInfo->Stream.pInput.pObject,
             (unsigned int)v12,
             0i64) >= 0 )
      {
        p_ProcessInfo->Stream.ResyncFile = 0;
        *(_QWORD *)&p_ProcessInfo->Stream.Pos = 0i64;
        p_ProcessInfo->Stream.FilePos = v12;
      }
    }
    else
    {
      p_ProcessInfo->Stream.Pos = v12 + DataSize - FilePos;
    }
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v14);
  }
  if ( v14 )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v14);
}

// File Line: 551
// RVA: 0x8C77C0
void __fastcall Scaleform::GFx::AS2Support::DoActionLoader(
        Scaleform::GFx::AS2Support *this,
        Scaleform::GFx::LoadProcess *p,
        Scaleform::GFx::TagInfo *tagInfo)
{
  Scaleform::GFx::AS2::DoActionTag *v4; // rbx

  Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
    (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&p->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>,
    "tag %d: DoActionLoader\n",
    (unsigned int)tagInfo->TagType);
  Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
    (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&p->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>,
    "-- actions in frame %d\n",
    p->pLoadData.pObject->LoadingFrame);
  v4 = Scaleform::GFx::LoadProcess::AllocTag<Scaleform::GFx::AS2::DoActionTag>(p);
  Scaleform::GFx::AS2::DoActionTag::Read(v4, p);
  Scaleform::GFx::LoadProcess::AddExecuteTag(p, v4);
}

// File Line: 564
// RVA: 0x8C7830
void __fastcall Scaleform::GFx::AS2Support::DoInitActionLoader(
        Scaleform::GFx::AS2Support *this,
        Scaleform::GFx::LoadProcess *p,
        Scaleform::GFx::TagInfo *tagInfo)
{
  Scaleform::GFx::SWFProcessInfo *pAltStream; // rbx
  unsigned int DataSize; // eax
  __int64 Pos; // r9
  char *pBuffer; // rdx
  __int16 v9; // r8
  __int16 v10; // ax
  unsigned int v11; // ebx
  Scaleform::GFx::AS2::DoInitActionTag *inited; // rbx
  Scaleform::GFx::ResourceId spriteId; // [rsp+38h] [rbp+10h] BYREF

  pAltStream = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  if ( !pAltStream )
    pAltStream = &p->ProcessInfo;
  DataSize = pAltStream->Stream.DataSize;
  pAltStream->Stream.UnusedBits = 0;
  if ( (int)(DataSize - pAltStream->Stream.Pos) < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
  Pos = pAltStream->Stream.Pos;
  pBuffer = pAltStream->Stream.pBuffer;
  v9 = (unsigned __int8)pBuffer[(unsigned int)(Pos + 1)];
  v10 = (unsigned __int8)pBuffer[Pos];
  pAltStream->Stream.Pos = Pos + 2;
  v11 = (unsigned __int16)(v10 | (v9 << 8));
  Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
    (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&p->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>,
    "  tag %d: DoInitActionLoader\n",
    (unsigned int)tagInfo->TagType);
  Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
    (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&p->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>,
    "  -- init actions for sprite %d\n",
    v11);
  inited = Scaleform::GFx::LoadProcess::AllocTag<Scaleform::GFx::AS2::DoInitActionTag>(p);
  Scaleform::GFx::AS2::DoActionTag::Read(inited, p);
  Scaleform::GFx::LoadProcess::AddInitAction(p, (Scaleform::GFx::ResourceId)&spriteId, inited);
}

// File Line: 578
// RVA: 0x8B5C90
Scaleform::GFx::AS2::PlaceObject2EHa *__fastcall Scaleform::GFx::AS2Support::AllocPlaceObject2Tag(
        Scaleform::GFx::AS2Support *this,
        Scaleform::GFx::LoadProcess *p,
        unsigned __int64 dataSz,
        unsigned __int8 swfVer)
{
  if ( swfVer >= 6u )
    return (Scaleform::GFx::AS2::PlaceObject2EHa *)Scaleform::GFx::LoadProcess::AllocTag<Scaleform::GFx::AS2::PlaceObject2EH>(
                                                     p,
                                                     dataSz);
  else
    return Scaleform::GFx::LoadProcess::AllocTag<Scaleform::GFx::AS2::PlaceObject2EHa>(p, dataSz);
}

// File Line: 588
// RVA: 0x8B5CC0
Scaleform::GFx::AS2::PlaceObject3EH *__fastcall Scaleform::GFx::AS2Support::AllocPlaceObject3Tag(
        Scaleform::GFx::AS2Support *this,
        Scaleform::GFx::LoadProcess *p,
        unsigned __int64 dataSz)
{
  return Scaleform::GFx::LoadProcess::AllocTag<Scaleform::GFx::AS2::PlaceObject3EH>(p, dataSz);
}

// File Line: 593
// RVA: 0x8B5D00
Scaleform::GFx::AS2::RemoveObjectEH *__fastcall Scaleform::GFx::AS2Support::AllocRemoveObjectTag(
        Scaleform::GFx::AS2Support *this,
        Scaleform::GFx::LoadProcess *p)
{
  return Scaleform::GFx::LoadProcess::AllocTag<Scaleform::GFx::AS2::RemoveObjectEH>(p);
}

// File Line: 598
// RVA: 0x8B5CE0
Scaleform::GFx::AS2::RemoveObject2EH *__fastcall Scaleform::GFx::AS2Support::AllocRemoveObject2Tag(
        Scaleform::GFx::AS2Support *this,
        Scaleform::GFx::LoadProcess *p)
{
  return Scaleform::GFx::LoadProcess::AllocTag<Scaleform::GFx::AS2::RemoveObject2EH>(p);
}

