// File Line: 30
// RVA: 0x9A46E0
Scaleform::Render::Image *__fastcall Scaleform::Render::ImageFileReader::Read(Scaleform::Render::ImageFileReader *this, Scaleform::File *file, Scaleform::Render::ImageCreateArgs *args)
{
  Scaleform::Render::ImageCreateArgs *v3; // rsi
  __int64 v4; // rdi
  __int64 v5; // rax
  __int64 v6; // rbx
  int v8; // [rsp+28h] [rbp-30h]
  __int64 v9; // [rsp+30h] [rbp-28h]
  __int64 v10; // [rsp+38h] [rbp-20h]
  __int64 v11; // [rsp+40h] [rbp-18h]
  int v12; // [rsp+48h] [rbp-10h]

  v3 = args;
  v4 = 0i64;
  v8 = 0;
  v9 = 0i64;
  v10 = 0i64;
  v11 = 0i64;
  v12 = 0;
  v5 = ((__int64 (__fastcall *)(Scaleform::Render::ImageFileReader *, Scaleform::File *, int *))this->vfptr[1].GetFormat)(
         this,
         file,
         &v8);
  v6 = v5;
  if ( v5 )
    v4 = (*(__int64 (__fastcall **)(__int64, Scaleform::Render::ImageCreateArgs *))(*(_QWORD *)v5 + 96i64))(v5, v3);
  if ( v6 )
    (*(void (__fastcall **)(__int64))(*(_QWORD *)v6 + 16i64))(v6);
  return (Scaleform::Render::Image *)v4;
}

// File Line: 94
// RVA: 0x93DEC0
void Scaleform::Render::ImageFileHandlerRegistry::ImageFileHandlerRegistry(Scaleform::Render::ImageFileHandlerRegistry *this, unsigned int handlerCount, ...)
{
  Scaleform::ArrayDataBase<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::ArrayDefaultPolicy> *v2; // rdi
  int v3; // esi
  unsigned int *v4; // r14
  unsigned __int64 v5; // rbp
  unsigned __int64 v6; // rbx
  unsigned __int64 v7; // r8
  unsigned __int64 *v8; // rcx
  unsigned int v9; // [rsp+88h] [rbp+10h]

  v9 = handlerCount;
  this->vfptr = (Scaleform::Render::ImageFileHandlerRegistryVtbl *)&Scaleform::Render::ImageFileHandlerRegistry::`vftable';
  v2 = (Scaleform::ArrayDataBase<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::ArrayDefaultPolicy> *)&this->Handlers;
  v3 = 0;
  v2->Data = 0i64;
  v2->Size = 0i64;
  v2->Policy.Capacity = 0i64;
  if ( handlerCount > 0 )
  {
    v4 = &v9;
    while ( 1 )
    {
      v4 += 2;
      v5 = *(_QWORD *)v4;
      if ( *(_QWORD *)v4 )
        break;
LABEL_12:
      if ( ++v3 >= v9 )
        return;
    }
    v6 = v2->Size + 1;
    if ( v6 >= v2->Size )
    {
      if ( v6 <= v2->Policy.Capacity )
        goto LABEL_10;
      v7 = v6 + (v6 >> 2);
    }
    else
    {
      if ( v6 >= v2->Policy.Capacity >> 1 )
        goto LABEL_10;
      v7 = v2->Size + 1;
    }
    Scaleform::ArrayDataBase<Scaleform::Render::ImageFileHandler *,Scaleform::AllocatorGH<Scaleform::Render::ImageFileHandler *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      v2,
      v2,
      v7);
LABEL_10:
    v2->Size = v6;
    v8 = (unsigned __int64 *)&v2->Data[v6 - 1];
    if ( v8 )
      *v8 = v5;
    goto LABEL_12;
  }
}

// File Line: 108
// RVA: 0x954290
void __fastcall Scaleform::Render::ImageFileHandlerRegistry::AddHandler(Scaleform::Render::ImageFileHandlerRegistry *this, Scaleform::Render::ImageFileHandler *handler)
{
  unsigned int v2; // ebx
  Scaleform::Render::ImageFileHandler *v3; // r14
  Scaleform::Render::ImageFileHandlerRegistry *v4; // rsi
  __int64 v5; // r8
  int v6; // edi
  unsigned __int64 v7; // rax
  unsigned __int64 v8; // rdi
  unsigned __int64 v9; // r8
  Scaleform::Render::ImageFileHandler **v10; // rcx
  Scaleform::Render::ImageFileHandler **v11; // rcx

  if ( !handler )
    return;
  v2 = 0;
  v3 = handler;
  v4 = this;
  if ( !this->Handlers.Data.Size )
  {
LABEL_6:
    v7 = v4->Handlers.Data.Size;
    v8 = v7 + 1;
    if ( v7 + 1 >= v7 )
    {
      if ( v8 <= v4->Handlers.Data.Policy.Capacity )
        goto LABEL_12;
      v9 = v8 + (v8 >> 2);
    }
    else
    {
      if ( v8 >= v4->Handlers.Data.Policy.Capacity >> 1 )
        goto LABEL_12;
      v9 = v7 + 1;
    }
    Scaleform::ArrayDataBase<Scaleform::Render::ImageFileHandler *,Scaleform::AllocatorGH<Scaleform::Render::ImageFileHandler *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::ArrayDefaultPolicy> *)&v4->Handlers,
      &v4->Handlers,
      v9);
LABEL_12:
    v10 = v4->Handlers.Data.Data;
    v4->Handlers.Data.Size = v8;
    v11 = &v10[v8 - 1];
    if ( v11 )
      *v11 = v3;
    return;
  }
  v5 = 0i64;
  while ( 1 )
  {
    v6 = ((__int64 (*)(void))v4->Handlers.Data.Data[v5]->vfptr->GetFormat)();
    if ( v6 == v3->vfptr->GetFormat(v3) )
      break;
    v5 = ++v2;
    if ( v2 >= v4->Handlers.Data.Size )
      goto LABEL_6;
  }
}

// File Line: 127
// RVA: 0x98AF00
Scaleform::Render::ImageFileHandler *__fastcall Scaleform::Render::ImageFileHandlerRegistry::GetReader(Scaleform::Render::ImageFileHandlerRegistry *this, Scaleform::Render::ImageFileFormat format)
{
  __int64 v2; // rbx
  Scaleform::Render::ImageFileFormat v3; // esi
  Scaleform::Render::ImageFileHandlerRegistry *v4; // rdi

  v2 = 0i64;
  v3 = format;
  v4 = this;
  if ( !this->Handlers.Data.Size )
    return 0i64;
  while ( !((unsigned __int8 (*)(void))v4->Handlers.Data.Data[v2]->vfptr->IsReader)()
       || ((unsigned int (*)(void))v4->Handlers.Data.Data[v2]->vfptr->GetFormat)() != v3 )
  {
    if ( ++v2 >= v4->Handlers.Data.Size )
      return 0i64;
  }
  return v4->Handlers.Data.Data[v2];
}

// File Line: 144
// RVA: 0x96E160
__int64 __fastcall Scaleform::Render::ImageFileHandlerRegistry::DetectFormat(Scaleform::Render::ImageFileHandlerRegistry *this, Scaleform::Render::ImageFileReader **preader, Scaleform::File *file, char *header, unsigned __int64 headerSize)
{
  Scaleform::Render::ImageFileReader **v5; // r14
  char *v6; // r15
  __int64 v7; // rbx
  Scaleform::File *v8; // r12
  Scaleform::Render::ImageFileHandlerRegistry *v9; // rdi
  unsigned __int64 v10; // rbp
  Scaleform::Render::ImageFileReader *v11; // rsi
  __int64 result; // rax
  char v13; // [rsp+50h] [rbp+8h]

  v5 = (Scaleform::Render::ImageFileReader **)&v13;
  v6 = header;
  if ( preader )
    v5 = preader;
  v7 = 0i64;
  v8 = file;
  v9 = this;
  if ( this->Handlers.Data.Size )
  {
    v10 = headerSize;
    while ( 1 )
    {
      if ( ((unsigned __int8 (*)(void))v9->Handlers.Data.Data[v7]->vfptr->IsReader)() )
      {
        v11 = (Scaleform::Render::ImageFileReader *)v9->Handlers.Data.Data[v7];
        if ( ((unsigned __int8 (__fastcall *)(Scaleform::Render::ImageFileHandler *, Scaleform::File *, char *, unsigned __int64))v11->vfptr[1].__vecDelDtor)(
               v9->Handlers.Data.Data[v7],
               v8,
               v6,
               v10) )
        {
          break;
        }
      }
      if ( ++v7 >= v9->Handlers.Data.Size )
        goto LABEL_8;
    }
    *v5 = v11;
    result = v11->vfptr->GetFormat((Scaleform::Render::ImageFileHandler *)&v11->vfptr);
  }
  else
  {
LABEL_8:
    *v5 = 0i64;
    result = 1i64;
  }
  return result;
}

// File Line: 167
// RVA: 0x9A56C0
Scaleform::Render::Image *__fastcall Scaleform::Render::ImageFileHandlerRegistry::ReadImage(Scaleform::Render::ImageFileHandlerRegistry *this, Scaleform::File *file, Scaleform::Render::ImageCreateArgs *args)
{
  __int64 v3; // rbx
  Scaleform::Render::ImageCreateArgs *v4; // r14
  Scaleform::File *v5; // rbp
  Scaleform::Render::ImageFileHandlerRegistry *v6; // rdi
  Scaleform::Render::ImageFileHandler *v7; // rsi

  v3 = 0i64;
  v4 = args;
  v5 = file;
  v6 = this;
  if ( !this->Handlers.Data.Size )
    return 0i64;
  while ( 1 )
  {
    if ( ((unsigned __int8 (*)(void))v6->Handlers.Data.Data[v3]->vfptr->IsReader)() )
    {
      v7 = v6->Handlers.Data.Data[v3];
      if ( ((unsigned __int8 (__fastcall *)(Scaleform::Render::ImageFileHandler *, Scaleform::File *, _QWORD, _QWORD))v7->vfptr[1].__vecDelDtor)(
             v6->Handlers.Data.Data[v3],
             v5,
             0i64,
             0i64) )
      {
        break;
      }
    }
    if ( ++v3 >= v6->Handlers.Data.Size )
      return 0i64;
  }
  return (Scaleform::Render::Image *)((__int64 (__fastcall *)(Scaleform::Render::ImageFileHandler *, Scaleform::File *, Scaleform::Render::ImageCreateArgs *))v7->vfptr[1].IsReader)(
                                       v7,
                                       v5,
                                       v4);
}

