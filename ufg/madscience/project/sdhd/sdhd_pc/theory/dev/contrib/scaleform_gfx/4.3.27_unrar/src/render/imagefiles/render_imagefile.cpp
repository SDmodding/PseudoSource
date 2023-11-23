// File Line: 30
// RVA: 0x9A46E0
Scaleform::Render::Image *__fastcall Scaleform::Render::ImageFileReader::Read(
        Scaleform::Render::ImageFileReader *this,
        Scaleform::File *file,
        Scaleform::Render::ImageCreateArgs *args)
{
  __int64 v4; // rdi
  __int64 v5; // rax
  __int64 v6; // rbx
  int v8; // [rsp+28h] [rbp-30h] BYREF
  __int64 v9; // [rsp+30h] [rbp-28h]
  __int64 v10; // [rsp+38h] [rbp-20h]
  __int64 v11; // [rsp+40h] [rbp-18h]
  int v12; // [rsp+48h] [rbp-10h]

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
    v4 = (*(__int64 (__fastcall **)(__int64, Scaleform::Render::ImageCreateArgs *))(*(_QWORD *)v5 + 96i64))(v5, args);
  if ( v6 )
    (*(void (__fastcall **)(__int64))(*(_QWORD *)v6 + 16i64))(v6);
  return (Scaleform::Render::Image *)v4;
}

// File Line: 94
// RVA: 0x93DEC0
void Scaleform::Render::ImageFileHandlerRegistry::ImageFileHandlerRegistry(
        Scaleform::Render::ImageFileHandlerRegistry *this,
        unsigned int handlerCount,
        ...)
{
  Scaleform::ArrayDataBase<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::ArrayDefaultPolicy> *p_Handlers; // rdi
  int v3; // esi
  unsigned int *v4; // r14
  unsigned __int64 v5; // rbp
  unsigned __int64 v6; // rbx
  unsigned __int64 v7; // r8
  unsigned __int64 *v8; // rcx
  unsigned int v9; // [rsp+88h] [rbp+10h] BYREF

  v9 = handlerCount;
  this->vfptr = (Scaleform::Render::ImageFileHandlerRegistryVtbl *)&Scaleform::Render::ImageFileHandlerRegistry::`vftable;
  p_Handlers = (Scaleform::ArrayDataBase<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::ArrayDefaultPolicy> *)&this->Handlers;
  v3 = 0;
  this->Handlers.Data.Data = 0i64;
  this->Handlers.Data.Size = 0i64;
  this->Handlers.Data.Policy.Capacity = 0i64;
  if ( handlerCount )
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
    v6 = p_Handlers->Size + 1;
    if ( v6 >= p_Handlers->Size )
    {
      if ( v6 <= p_Handlers->Policy.Capacity )
        goto LABEL_10;
      v7 = v6 + (v6 >> 2);
    }
    else
    {
      if ( v6 >= p_Handlers->Policy.Capacity >> 1 )
        goto LABEL_10;
      v7 = p_Handlers->Size + 1;
    }
    Scaleform::ArrayDataBase<Scaleform::Render::ImageFileHandler *,Scaleform::AllocatorGH<Scaleform::Render::ImageFileHandler *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      p_Handlers,
      p_Handlers,
      v7);
LABEL_10:
    p_Handlers->Size = v6;
    v8 = (unsigned __int64 *)&p_Handlers->Data[v6 - 1];
    if ( v8 )
      *v8 = v5;
    goto LABEL_12;
  }
}

// File Line: 108
// RVA: 0x954290
void __fastcall Scaleform::Render::ImageFileHandlerRegistry::AddHandler(
        Scaleform::Render::ImageFileHandlerRegistry *this,
        Scaleform::Render::ImageFileHandler *handler)
{
  unsigned int v2; // ebx
  __int64 v5; // r8
  Scaleform::Render::ImageFileHandler *v6; // rcx
  Scaleform::Render::ImageFileFormat v7; // edi
  unsigned __int64 Size; // rax
  unsigned __int64 v9; // rdi
  unsigned __int64 v10; // r8
  Scaleform::Render::ImageFileHandler **Data; // rcx
  Scaleform::Render::ImageFileHandler **v12; // rcx

  if ( !handler )
    return;
  v2 = 0;
  if ( !this->Handlers.Data.Size )
  {
LABEL_6:
    Size = this->Handlers.Data.Size;
    v9 = Size + 1;
    if ( Size + 1 >= Size )
    {
      if ( v9 <= this->Handlers.Data.Policy.Capacity )
        goto LABEL_12;
      v10 = v9 + (v9 >> 2);
    }
    else
    {
      if ( v9 >= this->Handlers.Data.Policy.Capacity >> 1 )
        goto LABEL_12;
      v10 = Size + 1;
    }
    Scaleform::ArrayDataBase<Scaleform::Render::ImageFileHandler *,Scaleform::AllocatorGH<Scaleform::Render::ImageFileHandler *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::ArrayDefaultPolicy> *)&this->Handlers,
      &this->Handlers,
      v10);
LABEL_12:
    Data = this->Handlers.Data.Data;
    this->Handlers.Data.Size = v9;
    v12 = &Data[v9 - 1];
    if ( v12 )
      *v12 = handler;
    return;
  }
  v5 = 0i64;
  while ( 1 )
  {
    v6 = this->Handlers.Data.Data[v5];
    v7 = v6->vfptr->GetFormat(v6);
    if ( v7 == handler->vfptr->GetFormat(handler) )
      break;
    v5 = ++v2;
    if ( v2 >= this->Handlers.Data.Size )
      goto LABEL_6;
  }
}

// File Line: 127
// RVA: 0x98AF00
Scaleform::Render::ImageFileReader *__fastcall Scaleform::Render::ImageFileHandlerRegistry::GetReader(
        Scaleform::Render::ImageFileHandlerRegistry *this,
        Scaleform::Render::ImageFileFormat format)
{
  __int64 v2; // rbx
  Scaleform::Render::ImageFileHandler *v5; // rcx
  Scaleform::Render::ImageFileHandler *v6; // rcx

  v2 = 0i64;
  if ( !this->Handlers.Data.Size )
    return 0i64;
  while ( 1 )
  {
    v5 = this->Handlers.Data.Data[v2];
    if ( v5->vfptr->IsReader(v5) )
    {
      v6 = this->Handlers.Data.Data[v2];
      if ( v6->vfptr->GetFormat(v6) == format )
        break;
    }
    if ( ++v2 >= this->Handlers.Data.Size )
      return 0i64;
  }
  return (Scaleform::Render::ImageFileReader *)this->Handlers.Data.Data[v2];
}

// File Line: 144
// RVA: 0x96E160
__int64 __fastcall Scaleform::Render::ImageFileHandlerRegistry::DetectFormat(
        Scaleform::Render::ImageFileHandlerRegistry *this,
        Scaleform::Render::ImageFileReader **preader,
        Scaleform::File *file,
        char *header,
        unsigned __int64 headerSize)
{
  char *v5; // r14
  __int64 v7; // rbx
  unsigned __int64 v10; // rbp
  Scaleform::Render::ImageFileHandler *v11; // rcx
  Scaleform::Render::ImageFileHandler *v12; // rsi
  char v14; // [rsp+50h] [rbp+8h] BYREF

  v5 = &v14;
  if ( preader )
    v5 = (char *)preader;
  v7 = 0i64;
  if ( this->Handlers.Data.Size )
  {
    v10 = headerSize;
    while ( 1 )
    {
      v11 = this->Handlers.Data.Data[v7];
      if ( v11->vfptr->IsReader(v11) )
      {
        v12 = this->Handlers.Data.Data[v7];
        if ( ((unsigned __int8 (__fastcall *)(Scaleform::Render::ImageFileHandler *, Scaleform::File *, char *, unsigned __int64))v12->vfptr[1].__vecDelDtor)(
               v12,
               file,
               header,
               v10) )
        {
          break;
        }
      }
      if ( ++v7 >= this->Handlers.Data.Size )
        goto LABEL_8;
    }
    *(_QWORD *)v5 = v12;
    return ((__int64 (__fastcall *)(Scaleform::Render::ImageFileHandler *))v12->vfptr->GetFormat)(v12);
  }
  else
  {
LABEL_8:
    *(_QWORD *)v5 = 0i64;
    return 1i64;
  }
}

// File Line: 167
// RVA: 0x9A56C0
Scaleform::Render::Image *__fastcall Scaleform::Render::ImageFileHandlerRegistry::ReadImage(
        Scaleform::Render::ImageFileHandlerRegistry *this,
        Scaleform::File *file,
        Scaleform::Render::ImageCreateArgs *args)
{
  __int64 v3; // rbx
  Scaleform::Render::ImageFileHandler *v7; // rcx
  Scaleform::Render::ImageFileHandler *v8; // rsi

  v3 = 0i64;
  if ( !this->Handlers.Data.Size )
    return 0i64;
  while ( 1 )
  {
    v7 = this->Handlers.Data.Data[v3];
    if ( v7->vfptr->IsReader(v7) )
    {
      v8 = this->Handlers.Data.Data[v3];
      if ( ((unsigned __int8 (__fastcall *)(Scaleform::Render::ImageFileHandler *, Scaleform::File *, _QWORD, _QWORD))v8->vfptr[1].__vecDelDtor)(
             v8,
             file,
             0i64,
             0i64) )
      {
        break;
      }
    }
    if ( ++v3 >= this->Handlers.Data.Size )
      return 0i64;
  }
  return (Scaleform::Render::Image *)((__int64 (__fastcall *)(Scaleform::Render::ImageFileHandler *, Scaleform::File *, Scaleform::Render::ImageCreateArgs *))v8->vfptr[1].IsReader)(
                                       v8,
                                       file,
                                       args);
}

