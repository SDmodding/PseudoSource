// File Line: 43
// RVA: 0x992100
__int64 __fastcall Scaleform::Render::ImageSize_MipLevelCount(Scaleform::Render::Size<unsigned long> sz)
{
  __int64 result; // rax
  unsigned int v3; // edx
  unsigned int v4; // ecx
  int v5; // edx

  result = 1i64;
  if ( *(_DWORD *)sz.Width > 1u )
  {
    do
    {
      v3 = *(_DWORD *)(*(_QWORD *)&sz + 4i64);
      if ( v3 <= 1 )
        break;
      v4 = *(_DWORD *)sz.Width >> 1;
      if ( !v4 )
        v4 = 1;
      v5 = v3 >> 1;
      *(_DWORD *)sz.Width = v4;
      if ( !v5 )
        v5 = 1;
      result = (unsigned int)(result + 1);
      *(_DWORD *)(*(_QWORD *)&sz + 4i64) = v5;
    }
    while ( v4 > 1 );
  }
  return result;
}

// File Line: 59
// RVA: 0x989700
void __fastcall Scaleform::Render::ImagePlane::GetMipLevel(
        Scaleform::Render::ImagePlane *this,
        Scaleform::Render::ImageFormat format,
        unsigned int level,
        Scaleform::Render::ImagePlane *p,
        unsigned int plane)
{
  unsigned int Width; // ebx
  Scaleform::Render::ImagePlane *v6; // r12
  Scaleform::Render::ImagePlane *v7; // r14
  unsigned int Height; // edi
  char *pData; // rax
  __int64 v11; // rcx
  __int32 v12; // ebp
  char *v13; // r12
  unsigned int v14; // ecx
  unsigned int v15; // eax
  unsigned int v16; // ecx
  unsigned __int64 v17; // rsi
  unsigned int v18; // ecx
  unsigned int v19; // eax
  unsigned __int64 FormatPitch; // rax
  bool v21; // zf
  __int64 v22; // [rsp+20h] [rbp-48h]
  unsigned int v24; // [rsp+80h] [rbp+18h]

  Width = this->Width;
  v6 = this;
  v7 = p;
  p->Width = this->Width;
  Height = this->Height;
  v24 = level;
  p->Height = Height;
  p->Pitch = this->Pitch;
  p->DataSize = this->DataSize;
  pData = this->pData;
  v11 = 0i64;
  v22 = 0i64;
  p->pData = pData;
  if ( level )
  {
    v12 = format & 0xFFF;
    v13 = pData;
    while ( v12 != 50 )
    {
      if ( (unsigned int)(v12 - 51) <= 2 || (unsigned int)(v12 - 64) <= 1 )
      {
        v18 = (Height + 3) >> 2;
        v19 = (Width + 3) >> 2;
        if ( !v18 )
          v18 = 1;
        if ( !v19 )
          v19 = 1;
        v16 = 16 * v19 * v18;
        goto LABEL_17;
      }
      v17 = Height * Scaleform::Render::ImageData::GetFormatPitch(format, Width, plane);
LABEL_18:
      Width >>= 1;
      v13 += v17;
      if ( !Width )
        Width = 1;
      Height >>= 1;
      if ( !Height )
        Height = 1;
      FormatPitch = Scaleform::Render::ImageData::GetFormatPitch(format, Width, plane);
      v11 = v17 + v22;
      v21 = v24-- == 1;
      v22 += v17;
      if ( v21 )
      {
        v7 = p;
        p->pData = v13;
        v6 = this;
        p->Width = Width;
        p->Height = Height;
        p->Pitch = FormatPitch;
        goto LABEL_24;
      }
    }
    v14 = (Height + 3) >> 2;
    v15 = (Width + 3) >> 2;
    if ( !v14 )
      v14 = 1;
    if ( !v15 )
      v15 = 1;
    v16 = 8 * v15 * v14;
LABEL_17:
    v17 = v16;
    goto LABEL_18;
  }
LABEL_24:
  v7->DataSize = v6->DataSize - v11;
}

// File Line: 80
// RVA: 0x965950
Scaleform::Render::Palette *__fastcall Scaleform::Render::Palette::Create(
        unsigned int colorCount,
        bool hasAlpha,
        Scaleform::MemoryHeap *pheap)
{
  Scaleform::MemoryHeap *v3; // r10
  Scaleform::Render::Palette *result; // rax
  Scaleform::Render::Palette *v7; // rbx

  v3 = pheap;
  if ( !pheap )
    v3 = Scaleform::Memory::pGlobalHeap;
  result = (Scaleform::Render::Palette *)v3->vfptr->Alloc(v3, 4i64 * (colorCount - 1) + 12, 0i64);
  v7 = result;
  if ( result )
  {
    result->RefCount.Value = 1;
    result->ColorCount = colorCount;
    result->HasAlphaFlag = hasAlpha;
    memset(result->Colors, 0, 4i64 * colorCount);
    return v7;
  }
  return result;
}

// File Line: 103
// RVA: 0x9CD490
char __fastcall Scaleform::Render::ImageData::allocPlanes(
        Scaleform::Render::ImageData *this,
        Scaleform::Render::ImageFormat format,
        unsigned int mipLevelCount,
        bool separateMipmaps)
{
  char v6; // r14
  int v8; // eax
  unsigned int v9; // edi
  unsigned int v10; // edi
  Scaleform::MemoryHeap *v11; // rcx
  Scaleform::Render::ImagePlane *v12; // rax

  v6 = mipLevelCount;
  if ( (format & 0xFFF) != 0 )
  {
    if ( (format & 0xFFF) == 200 )
    {
      v8 = 3;
    }
    else if ( (format & 0xFFF) == 201 )
    {
      v8 = 4;
    }
    else
    {
      v8 = 1;
    }
  }
  else
  {
    v8 = 0;
  }
  v9 = 1;
  if ( separateMipmaps )
    v9 = mipLevelCount;
  v10 = v8 * v9;
  if ( v10 > 1 )
  {
    v11 = Scaleform::Memory::pGlobalHeap;
    if ( (this->Flags & 4) != 0 )
      v11 = Scaleform::Memory::pGlobalHeap->vfptr->GetAllocHeap(Scaleform::Memory::pGlobalHeap, this);
    v12 = (Scaleform::Render::ImagePlane *)v11->vfptr->Alloc(v11, 32i64 * v10, 0i64);
    this->pPlanes = v12;
    if ( !v12 )
    {
      this->RawPlaneCount = 1;
      this->pPlanes = &this->Plane0;
      return 0;
    }
    memset(v12, 0, 32i64 * v10);
    this->Flags |= 2u;
  }
  this->Format = format;
  this->RawPlaneCount = v10;
  this->LevelCount = v6;
  if ( separateMipmaps )
    this->Flags |= 1u;
  return 1;
}

// File Line: 136
// RVA: 0x9E3770
void __fastcall Scaleform::Render::ImageData::freePlanes(Scaleform::Render::ImageData *this)
{
  char Flags; // al
  Scaleform::Render::ImagePlane *pPlanes; // rdx

  Flags = this->Flags;
  if ( (Flags & 2) != 0 )
  {
    pPlanes = this->pPlanes;
    this->Flags = Flags & 0xFD;
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, pPlanes);
    this->pPlanes = &this->Plane0;
  }
  else
  {
    this->pPlanes = &this->Plane0;
  }
}

// File Line: 147
// RVA: 0x94E050
Scaleform::Render::ImageData *__fastcall Scaleform::Render::ImageData::operator=(
        Scaleform::Render::ImageData *this,
        Scaleform::Render::ImageData *rhs)
{
  char Flags; // al
  Scaleform::Render::ImagePlane *pPlanes; // rdx
  Scaleform::Render::ImagePlane *p_Plane0; // rsi
  Scaleform::Render::Palette *pObject; // rcx
  Scaleform::Render::Palette *v8; // rdx
  unsigned __int16 v9; // si
  Scaleform::Render::ImagePlane *v10; // rax
  __int64 v11; // r11
  unsigned int v12; // edx
  unsigned int v13; // r8d
  char *v14; // r10
  unsigned __int64 v15; // r9
  unsigned __int64 v16; // rcx
  Scaleform::Render::ImagePlane *v17; // rax

  Flags = this->Flags;
  if ( (Flags & 2) != 0 )
  {
    pPlanes = this->pPlanes;
    this->Flags = Flags & 0xFD;
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, pPlanes);
  }
  p_Plane0 = &this->Plane0;
  this->pPlanes = &this->Plane0;
  this->Format = rhs->Format;
  this->Use = rhs->Use;
  this->Flags = rhs->Flags;
  this->LevelCount = rhs->LevelCount;
  this->RawPlaneCount = rhs->RawPlaneCount;
  pObject = rhs->pPalette.pObject;
  if ( pObject )
    _InterlockedExchangeAdd(&pObject->RefCount.Value, 1u);
  v8 = this->pPalette.pObject;
  if ( v8 && !_InterlockedDecrement(&v8->RefCount.Value) )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  this->pPalette.pObject = rhs->pPalette.pObject;
  p_Plane0->Width = rhs->Plane0.Width;
  this->Plane0.Height = rhs->Plane0.Height;
  this->Plane0.Pitch = rhs->Plane0.Pitch;
  this->Plane0.DataSize = rhs->Plane0.DataSize;
  this->Plane0.pData = rhs->Plane0.pData;
  if ( (rhs->Flags & 2) == 0 )
  {
    this->pPlanes = p_Plane0;
    return this;
  }
  this->Flags &= ~2u;
  Scaleform::Render::ImageData::allocPlanes(this, this->Format, (unsigned __int8)this->LevelCount, this->Flags & 1);
  v9 = 0;
  if ( !rhs->RawPlaneCount )
    return this;
  do
  {
    v10 = rhs->pPlanes;
    v11 = v9++;
    v11 *= 32i64;
    v12 = *(unsigned int *)((char *)&v10->Width + v11);
    v13 = *(unsigned int *)((char *)&v10->Height + v11);
    v14 = *(char **)((char *)&v10->pData + v11);
    v15 = *(unsigned __int64 *)((char *)&v10->DataSize + v11);
    v16 = *(unsigned __int64 *)((char *)&v10->Pitch + v11);
    v17 = this->pPlanes;
    *(unsigned int *)((char *)&v17->Width + v11) = v12;
    *(unsigned int *)((char *)&v17->Height + v11) = v13;
    *(unsigned __int64 *)((char *)&v17->Pitch + v11) = v16;
    *(unsigned __int64 *)((char *)&v17->DataSize + v11) = v15;
    *(char **)((char *)&v17->pData + v11) = v14;
  }
  while ( v9 < rhs->RawPlaneCount );
  return this;
}

// File Line: 178
// RVA: 0x95F780
void __fastcall Scaleform::Render::ImageData::Clear(Scaleform::Render::ImageData *this)
{
  char Flags; // al
  Scaleform::Render::ImagePlane *pPlanes; // rdx
  Scaleform::Render::Palette *pObject; // rdx

  Flags = this->Flags;
  if ( (Flags & 2) != 0 )
  {
    pPlanes = this->pPlanes;
    this->Flags = Flags & 0xFD;
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, pPlanes);
  }
  this->Flags &= ~4u;
  *(_QWORD *)&this->Format = 0i64;
  this->LevelCount = 0;
  this->pPlanes = &this->Plane0;
  this->RawPlaneCount = 1;
  pObject = this->pPalette.pObject;
  if ( pObject && !_InterlockedDecrement(&pObject->RefCount.Value) )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  this->pPalette.pObject = 0i64;
  *(_QWORD *)&this->Plane0.Width = 0i64;
  this->Plane0.Pitch = 0i64;
  this->Plane0.DataSize = 0i64;
  this->Plane0.pData = 0i64;
}

// File Line: 195
// RVA: 0x9940D0
bool __fastcall Scaleform::Render::ImageData::Initialize(
        Scaleform::Render::ImageData *this,
        Scaleform::Render::ImageData *source,
        unsigned int levelIndex,
        unsigned int levelCount)
{
  unsigned int v4; // esi
  Scaleform::Render::ImageFormat v8; // ebx
  bool result; // al
  unsigned int plane; // ebx
  Scaleform::Render::ImageFormat Format; // r10d
  int v12; // edx
  int v13; // ebx
  bool separateMipmaps; // al

  v4 = levelCount;
  if ( !levelCount )
    v4 = (unsigned __int8)source->LevelCount - levelIndex;
  if ( !levelIndex || (source->Flags & 1) != 0 )
  {
    Format = source->Format;
    v12 = 1;
    if ( (Format & 0xFFF) != 0 )
    {
      if ( (Format & 0xFFF) == 200 )
      {
        v13 = 3;
      }
      else if ( (Format & 0xFFF) == 201 )
      {
        v13 = 4;
      }
      else
      {
        v13 = 1;
      }
    }
    else
    {
      v13 = 0;
    }
    separateMipmaps = source->Flags & 1;
    if ( separateMipmaps )
      v12 = v4;
    Scaleform::Render::ImageData::Initialize(
      this,
      Format,
      v4,
      &source->pPlanes[levelIndex * v13],
      v13 * v12,
      separateMipmaps);
  }
  else
  {
    v8 = source->Format;
    Scaleform::Render::ImageData::Clear(this);
    result = Scaleform::Render::ImageData::allocPlanes(this, v8, v4, 0);
    if ( !result )
      return result;
    for ( plane = 0; plane < source->RawPlaneCount; ++plane )
      Scaleform::Render::ImagePlane::GetMipLevel(
        &source->pPlanes[plane],
        source->Format,
        levelIndex,
        &this->pPlanes[plane],
        plane);
  }
  return 1;
}

// File Line: 239
// RVA: 0x98AB10
void __fastcall Scaleform::Render::ImageData::GetPlane(
        Scaleform::Render::ImageData *this,
        unsigned int index,
        Scaleform::Render::ImagePlane *pplane)
{
  unsigned int RawPlaneCount; // ecx

  RawPlaneCount = this->RawPlaneCount;
  if ( index >= RawPlaneCount )
    Scaleform::Render::ImagePlane::GetMipLevel(
      &this->pPlanes[index % RawPlaneCount],
      this->Format,
      index / RawPlaneCount,
      pplane,
      index % RawPlaneCount);
  else
    *pplane = this->pPlanes[index];
}

// File Line: 269
// RVA: 0x9B2A70
void __fastcall Scaleform::Render::ImageData::SetPixelInScanline(
        Scaleform::Render::ImageData *this,
        char *pline,
        unsigned int x,
        unsigned int color)
{
  signed __int32 v4; // r10d
  signed __int32 v5; // r10d
  signed __int32 v6; // r10d
  __int64 v7; // rcx
  __int64 v8; // rcx
  __int64 v9; // rcx
  __int64 v10; // rcx
  __int64 v11; // rcx

  v4 = this->Format & 0xFFEFFFFF;
  if ( v4 > 4 )
  {
    if ( v4 == 9 )
    {
      pline[x] = HIBYTE(color);
    }
    else if ( v4 == 12289 )
    {
      v11 = 4 * x;
      pline[v11 + 3] = color;
      pline[v11] = HIBYTE(color);
      pline[v11 + 1] = BYTE2(color);
      pline[v11 + 2] = BYTE1(color);
    }
  }
  else if ( v4 == 4 )
  {
    v10 = 3 * x;
    pline[v10] = color;
    pline[v10 + 2] = BYTE2(color);
    pline[v10 + 1] = BYTE1(color);
  }
  else
  {
    v5 = v4 - 1;
    if ( v5 )
    {
      v6 = v5 - 1;
      if ( v6 )
      {
        if ( v6 == 1 )
        {
          v7 = 3 * x;
          pline[v7 + 2] = color;
          pline[v7] = BYTE2(color);
          pline[v7 + 1] = BYTE1(color);
        }
      }
      else
      {
        v8 = 4 * x;
        *(_DWORD *)&pline[v8] = color;
      }
    }
    else
    {
      v9 = 4 * x;
      pline[v9 + 2] = color;
      pline[v9] = BYTE2(color);
      pline[v9 + 3] = HIBYTE(color);
      pline[v9 + 1] = BYTE1(color);
    }
  }
}

// File Line: 327
// RVA: 0x98A8B0
Scaleform::Render::Color *__fastcall Scaleform::Render::ImageData::GetPixelInScanline(
        Scaleform::Render::ImageData *this,
        Scaleform::Render::Color *result,
        const char *pline,
        unsigned int x)
{
  signed __int32 v4; // r10d
  signed __int32 v5; // r10d
  signed __int32 v6; // r10d
  __int64 v7; // rcx
  __int64 v9; // rcx
  __int64 v10; // rcx
  __int64 v11; // rcx
  __int64 v12; // rcx

  v4 = this->Format & 0xFFEFFFFF;
  if ( v4 <= 4 )
  {
    if ( v4 != 4 )
    {
      v5 = v4 - 1;
      if ( !v5 )
      {
        v10 = 4 * x;
        result->Channels.Red = pline[v10];
        result->Channels.Green = pline[v10 + 1];
        result->Channels.Blue = pline[v10 + 2];
        result->Channels.Alpha = pline[v10 + 3];
        return result;
      }
      v6 = v5 - 1;
      if ( !v6 )
      {
        v9 = 4 * x;
        *result = *(Scaleform::Render::Color *)&pline[v9];
        return result;
      }
      if ( v6 == 1 )
      {
        result->Channels.Alpha = -1;
        v7 = 4 * x;
        result->Channels.Red = pline[v7];
        result->Channels.Green = pline[v7 + 1];
        result->Channels.Blue = pline[v7 + 2];
        return result;
      }
      return result;
    }
    result->Channels.Alpha = -1;
    v11 = 4 * x;
    result->Channels.Red = pline[v11 + 2];
    result->Channels.Green = pline[v11 + 1];
    result->Channels.Blue = pline[v11];
    goto LABEL_10;
  }
  if ( v4 == 9 )
  {
LABEL_10:
    *(_WORD *)&result->Channels.Green = -1;
    result->Channels.Blue = -1;
    result->Channels.Alpha = pline[4 * x];
    return result;
  }
  if ( v4 != 12289 )
    return result;
  v12 = 4 * x;
  result->Channels.Red = pline[v12 + 1];
  result->Channels.Green = pline[v12 + 2];
  result->Channels.Blue = pline[v12 + 3];
  result->Channels.Alpha = pline[v12];
  return result;
}

// File Line: 574
// RVA: 0x984C90
__int64 __fastcall Scaleform::Render::ImageData::GetFormatPlaneCount(Scaleform::Render::ImageFormat fmt)
{
  __int32 v1; // ecx
  __int32 v2; // ecx

  v1 = fmt & 0xFFF;
  if ( !v1 )
    return 0i64;
  v2 = v1 - 200;
  if ( !v2 )
    return 3i64;
  if ( v2 == 1 )
    return 4i64;
  return 1i64;
}

// File Line: 589
// RVA: 0x9849B0
__int64 __fastcall Scaleform::Render::ImageData::GetFormatBitsPerPixel(
        Scaleform::Render::ImageFormat fmt,
        unsigned int plane)
{
  __int64 result; // rax

  switch ( fmt & 0xFFF )
  {
    case 1:
    case 2:
    case 0x33:
    case 0x34:
    case 0x35:
      result = 32i64;
      break;
    case 3:
    case 4:
      result = 24i64;
      break;
    case 9:
    case 0x64:
    case 0xC8:
    case 0xC9:
      result = 8i64;
      break;
    case 0x32:
      result = 16i64;
      break;
    case 0x36:
    case 0x37:
    case 0x3A:
      result = 4i64;
      break;
    case 0x38:
    case 0x39:
      result = 2i64;
      break;
    default:
      result = 0i64;
      break;
  }
  return result;
}

// File Line: 628
// RVA: 0x984B30
unsigned __int64 __fastcall Scaleform::Render::ImageData::GetFormatPitch(
        Scaleform::Render::ImageFormat fmt,
        unsigned int width,
        unsigned int plane)
{
  unsigned __int64 result; // rax

  switch ( fmt & 0xFFF )
  {
    case 1:
    case 2:
      result = 4 * width;
      break;
    case 3:
    case 4:
      result = (3 * (width + 1)) & 0xFFFFFFFC;
      break;
    case 9:
    case 0x3D:
    case 0x40:
    case 0x64:
    case 0xC8:
    case 0xC9:
      result = width;
      break;
    case 0x32:
      result = 8 * ((width + 3) >> 2);
      break;
    case 0x33:
    case 0x34:
    case 0x35:
      result = 16 * ((width + 3) >> 2);
      break;
    case 0x36:
    case 0x37:
    case 0x3A:
    case 0x3C:
    case 0x3E:
    case 0x3F:
      result = (unsigned __int64)width >> 1;
      break;
    case 0x38:
    case 0x39:
      result = (unsigned __int64)width >> 2;
      break;
    default:
      result = 0i64;
      break;
  }
  return result;
}

// File Line: 686
// RVA: 0x984CC0
Scaleform::Render::Size<unsigned long> *__fastcall Scaleform::Render::ImageData::GetFormatPlaneSize(
        Scaleform::Render::Size<unsigned long> *result,
        Scaleform::Render::ImageFormat fmt,
        Scaleform::Render::Size<unsigned long> *sz,
        unsigned int plane)
{
  if ( (fmt & 0xFFFu) - 200 > 1 || plane - 1 > 1 )
  {
    *result = *sz;
    return result;
  }
  else
  {
    result->Width = sz->Width >> 1;
    result->Height = sz->Height >> 1;
    return result;
  }
}

// File Line: 702
// RVA: 0x989880
unsigned __int64 __fastcall Scaleform::Render::ImageData::GetMipLevelSize(
        Scaleform::Render::ImageFormat format,
        Scaleform::Render::Size<unsigned long> *sz,
        unsigned int plane)
{
  __int32 v3; // r9d
  unsigned int v4; // eax
  unsigned int v5; // ecx
  unsigned int v7; // eax
  unsigned int v8; // ecx

  v3 = format & 0xFFF;
  if ( v3 == 50 )
  {
    v4 = (sz->Height + 3) >> 2;
    v5 = (sz->Width + 3) >> 2;
    if ( !v4 )
      v4 = 1;
    if ( !v5 )
      v5 = 1;
    return 8 * v5 * v4;
  }
  else if ( (unsigned int)(v3 - 51) <= 2 || (unsigned int)(v3 - 64) <= 1 )
  {
    v7 = (sz->Height + 3) >> 2;
    v8 = (sz->Width + 3) >> 2;
    if ( !v7 )
      v7 = 1;
    if ( !v8 )
      v8 = 1;
    return 16 * v8 * v7;
  }
  else
  {
    return sz->Height * Scaleform::Render::ImageData::GetFormatPitch(format, sz->Width, plane);
  }
}

// File Line: 718
// RVA: 0x989920
__int64 __fastcall Scaleform::Render::ImageData::GetMipLevelsSize(
        Scaleform::Render::ImageFormat format,
        Scaleform::Render::Size<unsigned long> *sz,
        unsigned int levels,
        unsigned int plane)
{
  unsigned int Width; // edi
  unsigned int Height; // esi
  __int64 v6; // rbp
  unsigned int v8; // r15d
  __int32 v10; // ebx
  unsigned int v11; // ecx
  unsigned int v12; // eax
  unsigned int v13; // ecx
  unsigned __int64 v14; // rdx
  unsigned int v15; // ecx
  unsigned int v16; // eax

  Width = sz->Width;
  Height = sz->Height;
  v6 = 0i64;
  v8 = levels;
  if ( levels )
  {
    v10 = format & 0xFFF;
    while ( v10 != 50 )
    {
      if ( (unsigned int)(v10 - 51) <= 2 || (unsigned int)(v10 - 64) <= 1 )
      {
        v15 = (Height + 3) >> 2;
        v16 = (Width + 3) >> 2;
        if ( !v15 )
          v15 = 1;
        if ( !v16 )
          v16 = 1;
        v13 = 16 * v16 * v15;
        goto LABEL_17;
      }
      v14 = Height * Scaleform::Render::ImageData::GetFormatPitch(format, Width, plane);
LABEL_18:
      Width >>= 1;
      v6 += v14;
      if ( !Width )
        Width = 1;
      Height >>= 1;
      if ( !Height )
        Height = 1;
      if ( !--v8 )
        return v6;
    }
    v11 = (Height + 3) >> 2;
    v12 = (Width + 3) >> 2;
    if ( !v11 )
      v11 = 1;
    if ( !v12 )
      v12 = 1;
    v13 = 8 * v12 * v11;
LABEL_17:
    v14 = v13;
    goto LABEL_18;
  }
  return v6;
}

// File Line: 733
// RVA: 0x95B8E0
void __fastcall Scaleform::Render::ImageSwizzler::CacheScanline(
        Scaleform::Render::ImageSwizzler *this,
        Scaleform::Render::ImageSwizzlerContext *ctx,
        unsigned int y)
{
  ctx->pCurrentScanline = &ctx->pImage->pPlanes->pData[y * ctx->pImage->pPlanes->Pitch];
}

// File Line: 738
// RVA: 0x9B2B90
void __fastcall Scaleform::Render::ImageSwizzler::SetPixelInScanline(
        Scaleform::Render::ImageSwizzler *this,
        Scaleform::Render::ImageSwizzlerContext *ctx,
        __int64 x,
        unsigned int *c)
{
  this->vfptr->SetPixelInScanline(this, ctx, x, *c);
}

// File Line: 743
// RVA: 0x9B2B80
void __fastcall Scaleform::Render::ImageSwizzler::SetPixelInScanline(
        Scaleform::Render::ImageSwizzler *this,
        Scaleform::Render::ImageSwizzlerContext *ctx,
        unsigned int x,
        unsigned int c)
{
  Scaleform::Render::ImageData::SetPixelInScanline(ctx->pImage, ctx->pCurrentScanline, x, c);
}

// File Line: 748
// RVA: 0x98A9F0
Scaleform::Render::Color *__fastcall Scaleform::Render::ImageSwizzler::GetPixelInScanline(
        Scaleform::Render::ImageSwizzler *this,
        Scaleform::Render::Color *result,
        Scaleform::Render::ImageSwizzlerContext *ctx,
        unsigned int x)
{
  Scaleform::Render::ImageData::GetPixelInScanline(ctx->pImage, result, ctx->pCurrentScanline, x);
  return result;
}

// File Line: 754
// RVA: 0x9BB610
void __fastcall Scaleform::Render::MappedTextureBase::Unmap(Scaleform::Render::MappedTextureBase *this, bool __formal)
{
  this->pTexture->pMap = 0i64;
  this->pTexture = 0i64;
  *(_QWORD *)&this->StartMipLevel = 0i64;
}

// File Line: 765
// RVA: 0x964DD0
// attributes: thunk
void __fastcall Scaleform::Render::ImageBase::CopyScanlineDefault(
        void *pd,
        const void *ps,
        size_t size,
        Scaleform::Render::Palette *__formal)
{
  memmove(pd, ps, size);
}

// File Line: 798
// RVA: 0x94B010
void __fastcall Scaleform::Render::Image::~Image(Scaleform::Render::Image *this)
{
  volatile signed __int32 *v2; // rbx

  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::Image::`vftable;
  v2 = (volatile signed __int32 *)_InterlockedExchange64((volatile __int64 *)&this->pTexture, 0i64);
  if ( v2 )
  {
    (*(void (__fastcall **)(volatile signed __int32 *))(*(_QWORD *)v2 + 64i64))(v2);
    if ( !_InterlockedDecrement(v2 + 2) )
      (**(void (__fastcall ***)(volatile signed __int32 *, __int64))v2)(v2, 1i64);
  }
  if ( this->pInverseMatrix )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
}

// File Line: 885
// RVA: 0x9696A0
void __fastcall Scaleform::Render::Image::CreateSubImage(
        Scaleform::Render::Image *this,
        Scaleform::Render::Rect<unsigned long> *rect,
        Scaleform::MemoryHeap *pheap)
{
  Scaleform::Render::SubImage *v5; // rax

  v5 = (Scaleform::Render::SubImage *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))pheap->vfptr->Alloc)(
                                        pheap,
                                        64i64);
  if ( v5 )
    Scaleform::Render::SubImage::SubImage(v5, this, rect);
}

// File Line: 892
// RVA: 0x9B1B60
void __fastcall Scaleform::Render::Image::SetMatrix(
        Scaleform::Render::Image *this,
        Scaleform::Render::Matrix2x4<float> *mat,
        Scaleform::MemoryHeap *heap)
{
  Scaleform::MemoryHeap *v3; // rax
  float *pInverseMatrix; // rcx

  v3 = heap;
  if ( !this->pInverseMatrix )
  {
    if ( !heap )
      v3 = Scaleform::Memory::pGlobalHeap->vfptr->GetAllocHeap(Scaleform::Memory::pGlobalHeap, this);
    this->pInverseMatrix = (Scaleform::Render::Matrix2x4<float> *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64, __int64))v3->vfptr->Alloc)(
                                                                    v3,
                                                                    32i64,
                                                                    16i64);
  }
  pInverseMatrix = (float *)this->pInverseMatrix;
  *pInverseMatrix = mat->M[0][0];
  pInverseMatrix[1] = mat->M[0][1];
  pInverseMatrix[2] = mat->M[0][2];
  pInverseMatrix[3] = mat->M[0][3];
  pInverseMatrix[4] = mat->M[1][0];
  pInverseMatrix[5] = mat->M[1][1];
  pInverseMatrix[6] = mat->M[1][2];
  pInverseMatrix[7] = mat->M[1][3];
  Scaleform::Render::Matrix2x4<float>::Invert(this->pInverseMatrix);
}

// File Line: 903
// RVA: 0x9B1C80
void __fastcall Scaleform::Render::Image::SetMatrixInverse(
        Scaleform::Render::Image *this,
        Scaleform::Render::Matrix2x4<float> *mat,
        Scaleform::MemoryHeap *heap)
{
  Scaleform::MemoryHeap *v3; // rax
  float *pInverseMatrix; // rcx

  v3 = heap;
  if ( !this->pInverseMatrix )
  {
    if ( !heap )
      v3 = Scaleform::Memory::pGlobalHeap->vfptr->GetAllocHeap(Scaleform::Memory::pGlobalHeap, this);
    this->pInverseMatrix = (Scaleform::Render::Matrix2x4<float> *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64, __int64))v3->vfptr->Alloc)(
                                                                    v3,
                                                                    32i64,
                                                                    16i64);
  }
  pInverseMatrix = (float *)this->pInverseMatrix;
  *pInverseMatrix = mat->M[0][0];
  pInverseMatrix[1] = mat->M[0][1];
  pInverseMatrix[2] = mat->M[0][2];
  pInverseMatrix[3] = mat->M[0][3];
  pInverseMatrix[4] = mat->M[1][0];
  pInverseMatrix[5] = mat->M[1][1];
  pInverseMatrix[6] = mat->M[1][2];
  pInverseMatrix[7] = mat->M[1][3];
}

// File Line: 914
// RVA: 0x988DB0
void __fastcall Scaleform::Render::Image::GetMatrix(
        Scaleform::Render::Image *this,
        Scaleform::Render::Matrix2x4<float> *mat)
{
  Scaleform::Render::Matrix2x4<float> *pInverseMatrix; // r8

  pInverseMatrix = this->pInverseMatrix;
  if ( pInverseMatrix )
  {
    *mat = *pInverseMatrix;
    Scaleform::Render::Matrix2x4<float>::Invert(mat);
  }
  else
  {
    *(_QWORD *)&mat->M[0][0] = 1065353216i64;
    *(_QWORD *)&mat->M[1][1] = 1065353216i64;
    *(_QWORD *)&mat->M[0][2] = 0i64;
    mat->M[1][0] = 0.0;
    mat->M[1][3] = 0.0;
  }
}

// File Line: 926
// RVA: 0x988E20
_BOOL8 __fastcall Scaleform::Render::Image::GetMatrixInverse(
        Scaleform::Render::Image *this,
        Scaleform::Render::Matrix2x4<float> *mat)
{
  Scaleform::Render::Matrix2x4<float> *pInverseMatrix; // r8

  pInverseMatrix = this->pInverseMatrix;
  if ( pInverseMatrix )
    *mat = *pInverseMatrix;
  return this->pInverseMatrix != 0i64;
}

// File Line: 933
// RVA: 0x98E340
void __fastcall Scaleform::Render::Image::GetUVGenMatrix(
        Scaleform::Render::Image *this,
        Scaleform::Render::Matrix2x4<float> *mat,
        Scaleform::Render::TextureManager *manager)
{
  void *v5; // rsi
  __m128 v6; // xmm6
  __m128 v7; // xmm7
  __m128 v8; // xmm5
  __m128 v9; // xmm0
  float v10; // xmm1_4
  int v11; // [rsp+20h] [rbp-78h] BYREF
  int v12; // [rsp+24h] [rbp-74h]
  __m128 v13; // [rsp+30h] [rbp-68h] BYREF
  __m128 v14; // [rsp+40h] [rbp-58h]
  __m128 v15; // [rsp+50h] [rbp-48h] BYREF
  __m128 v16; // [rsp+60h] [rbp-38h]

  v5 = this->vfptr[21].__vecDelDtor(this, manager);
  if ( v5 )
  {
    if ( this->vfptr[16].__vecDelDtor(this, &v15) )
    {
      (*(void (__fastcall **)(void *, __m128 *))(*(_QWORD *)v5 + 56i64))(v5, &v13);
      v6 = (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>::`2::v;
      v7 = (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<4294967295,4294967295,0,4294967295>::`2::v;
      v8 = v14;
      v9 = _mm_mul_ps(_mm_shuffle_ps(v14, v14, 0), v15);
      *(__m128 *)&mat->M[0][0] = _mm_and_ps(
                                   _mm_add_ps(
                                     _mm_add_ps(
                                       _mm_mul_ps(_mm_shuffle_ps(v13, v13, 85), v16),
                                       _mm_mul_ps(_mm_shuffle_ps(v13, v13, 0), v15)),
                                     _mm_and_ps(
                                       v13,
                                       (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>::`2::v)),
                                   (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<4294967295,4294967295,0,4294967295>::`2::v);
      *(__m128 *)&mat->M[1][0] = _mm_and_ps(
                                   _mm_add_ps(
                                     _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v8, v8, 85), v16), v9),
                                     _mm_and_ps(v8, v6)),
                                   v7);
    }
    else
    {
      (*(void (__fastcall **)(void *, Scaleform::Render::Matrix2x4<float> *))(*(_QWORD *)v5 + 56i64))(v5, mat);
    }
    this->vfptr[6].__vecDelDtor(this, (unsigned int)&v11);
    v10 = (float)((float)v12 * mat->M[0][1]) + (float)((float)v11 * mat->M[0][0]);
    mat->M[1][3] = (float)((float)((float)v12 * mat->M[1][1]) + (float)((float)v11 * mat->M[1][0])) + mat->M[1][3];
    mat->M[0][3] = v10 + mat->M[0][3];
  }
  else
  {
    *(_QWORD *)&mat->M[0][0] = 1065353216i64;
    *(_QWORD *)&mat->M[1][1] = 1065353216i64;
    *(_QWORD *)&mat->M[0][2] = 0i64;
    mat->M[1][0] = 0.0;
    mat->M[1][3] = 0.0;
  }
}

// File Line: 959
// RVA: 0x98E4C0
void __fastcall Scaleform::Render::Image::GetUVNormMatrix(
        Scaleform::Render::Image *this,
        Scaleform::Render::Matrix2x4<float> *mat,
        Scaleform::Render::TextureManager *manager)
{
  _DWORD *v5; // rax
  _DWORD *v6; // rsi
  float v7; // xmm5_4
  float v8; // xmm3_4
  float v9; // xmm2_4
  float v10; // xmm7_4
  float v11; // xmm8_4
  float v12; // xmm6_4
  float v13; // xmm4_4
  float v14; // xmm3_4
  float v15; // xmm2_4
  float v16; // xmm0_4
  float v17; // xmm3_4
  float v18; // xmm1_4
  float v19; // xmm4_4
  float v20; // xmm2_4
  float v21; // xmm0_4
  float v22; // xmm1_4
  float v23; // xmm1_4
  _DWORD *v24; // rax
  int v25; // [rsp+20h] [rbp-68h] BYREF
  int v26; // [rsp+24h] [rbp-64h]
  int v27; // [rsp+28h] [rbp-60h]
  int v28; // [rsp+2Ch] [rbp-5Ch]
  float v29; // [rsp+30h] [rbp-58h] BYREF
  float v30; // [rsp+34h] [rbp-54h]
  float v31; // [rsp+3Ch] [rbp-4Ch]
  float v32; // [rsp+40h] [rbp-48h]
  float v33; // [rsp+44h] [rbp-44h]
  float v34; // [rsp+4Ch] [rbp-3Ch]

  v5 = this->vfptr[21].__vecDelDtor(this, manager);
  v6 = v5;
  if ( v5 )
  {
    (*(void (__fastcall **)(_DWORD *, Scaleform::Render::Matrix2x4<float> *))(*(_QWORD *)v5 + 56i64))(v5, mat);
    this->vfptr[6].__vecDelDtor(this, (unsigned int)&v25);
    if ( v27 - v25 != v6[12] || v28 - v26 != v6[13] )
    {
      if ( this->vfptr[16].__vecDelDtor(this, &v29) )
      {
        v7 = mat->M[0][1];
        v8 = v32;
        v9 = v29;
        mat->M[1][2] = 0.0;
        mat->M[0][2] = 0.0;
        v10 = mat->M[0][0];
        v11 = mat->M[1][0];
        v12 = mat->M[1][1];
        v13 = v33;
        mat->M[0][0] = (float)(v8 * v7) + (float)(v9 * mat->M[0][0]);
        v14 = (float)(v8 * v12) + (float)(v9 * v11);
        v15 = v30;
        v16 = v30;
        mat->M[1][0] = v14;
        v17 = v34;
        v18 = (float)(v13 * v7) + (float)(v16 * v10);
        v19 = (float)(v13 * v12) + (float)(v15 * v11);
        v20 = v31 * v11;
        v21 = v31 * v10;
        mat->M[0][1] = v18;
        mat->M[1][1] = v19;
        v22 = (float)((float)(v17 * v7) + v21) + mat->M[0][3];
        mat->M[1][3] = (float)((float)(v17 * v12) + v20) + mat->M[1][3];
        mat->M[0][3] = v22;
      }
    }
    v23 = (float)((float)v26 * mat->M[0][1]) + (float)((float)v25 * mat->M[0][0]);
    mat->M[1][3] = (float)((float)((float)v25 * mat->M[1][0]) + (float)((float)v26 * mat->M[1][1])) + mat->M[1][3];
    mat->M[0][3] = v23 + mat->M[0][3];
  }
  else
  {
    *(_QWORD *)&mat->M[0][0] = 1065353216i64;
    *(_QWORD *)&mat->M[1][1] = 1065353216i64;
    *(_QWORD *)&mat->M[0][2] = 0i64;
    mat->M[1][0] = 0.0;
    mat->M[1][3] = 0.0;
  }
  v24 = this->vfptr[6].__vecDelDtor(this, &v25);
  Scaleform::Render::Matrix2x4<float>::PrependScaling(mat, (float)(v24[2] - *v24), (float)(v24[3] - v24[1]));
}

// File Line: 1000
// RVA: 0x997630
bool __fastcall Scaleform::Render::ImageSource::IsDecodeOnlyImageCompatible(
        Scaleform::Render::ImageSource *this,
        Scaleform::Render::ImageCreateArgs *args)
{
  Scaleform::Render::TextureManager *pManager; // rbx
  Scaleform::RefCountImplCoreVtbl *vfptr; // rbx
  unsigned int v5; // eax
  __int16 v6; // ax
  bool result; // al

  pManager = args->pManager;
  result = (!pManager
         || (vfptr = pManager->Scaleform::RefCountBase<Scaleform::Render::TextureManager,72>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,72>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr,
             v5 = ((__int64 (__fastcall *)(Scaleform::Render::ImageSource *))this->vfptr[4].__vecDelDtor)(this),
             v6 = (__int16)vfptr[3].__vecDelDtor(args->pManager, v5),
             (args->Use & (unsigned __int8)~(_BYTE)v6 & 0xC0) != 0)
         || (v6 & 0x100) == 0
         || args->pManager->pTextureCache.pObject)
        && (args->Use & 0xC0) == 0;
  return result;
}

// File Line: 1024
// RVA: 0x9660E0
Scaleform::Render::RawImage *__fastcall Scaleform::Render::ImageSource::CreateCompatibleImage(
        Scaleform::Render::ImageSource *this,
        Scaleform::Render::ImageCreateArgs *args)
{
  Scaleform::Render::ImageFormat Format; // r13d
  Scaleform::Render::ImageUpdateSync *psync; // r12
  Scaleform::Render::RawImage *v6; // rdi
  Scaleform::Render::TextureManager *pManager; // r12
  Scaleform::MemoryHeap *pHeap; // rbx
  unsigned int Use; // r15d
  Scaleform::Render::TextureManager *v10; // rcx
  __int16 v11; // ax
  Scaleform::RefCountImplCoreVtbl *vfptr; // rbx
  void *v13; // rax
  Scaleform::Render::Texture *ptexture; // rbx
  Scaleform::Render::TextureImage *v15; // r14
  Scaleform::Render::Size<unsigned long> *v16; // rax
  Scaleform::Render::RawImage *v17; // rax
  Scaleform::Render::Size<unsigned long> *v18; // rax
  Scaleform::Render::RawImage *result; // rax
  Scaleform::Render::RawImage *v20; // rbx
  char v21[8]; // [rsp+48h] [rbp-31h] BYREF
  Scaleform::Render::ImageData v22; // [rsp+50h] [rbp-29h] BYREF
  unsigned int mipLevelCount; // [rsp+E0h] [rbp+67h]
  void *v24; // [rsp+E8h] [rbp+6Fh] BYREF
  Scaleform::MemoryHeap *v25; // [rsp+F0h] [rbp+77h]
  char v26; // [rsp+F8h] [rbp+7Fh] BYREF

  Format = args->Format;
  if ( Format == Image_None )
    Format = ((unsigned int (__fastcall *)(Scaleform::Render::ImageSource *))this->vfptr[4].__vecDelDtor)(this);
  psync = args->pUpdateSync;
  v6 = 0i64;
  if ( !psync )
  {
    pManager = args->pManager;
    if ( pManager )
      psync = &pManager->Scaleform::Render::ImageUpdateSync;
    else
      psync = 0i64;
  }
  pHeap = Scaleform::Memory::pGlobalHeap;
  if ( args->pHeap )
    pHeap = args->pHeap;
  v24 = pHeap;
  v25 = pHeap;
  Use = args->Use;
  mipLevelCount = ((__int64 (__fastcall *)(Scaleform::Render::ImageSource *))this->vfptr[7].__vecDelDtor)(this);
  if ( mipLevelCount > 1 )
    Use &= ~2u;
  v10 = args->pManager;
  if ( v10
    && (v11 = (__int16)v10->Scaleform::RefCountBase<Scaleform::Render::TextureManager,72>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,72>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr[3].__vecDelDtor(
                         v10,
                         Format),
        (args->Use & (unsigned __int8)~(_BYTE)v11 & 0xC0) == 0)
    && (v11 & 0x100) != 0
    && (Use |= 0x100u,
        ((unsigned __int8 (__fastcall *)(Scaleform::Render::TextureManager *))args->pManager->vfptr[7].__vecDelDtor)(args->pManager)) )
  {
    vfptr = args->pManager->vfptr;
    v13 = this->vfptr[5].__vecDelDtor(this, &v26);
    ptexture = (Scaleform::Render::Texture *)((__int64 (__fastcall *)(Scaleform::Render::TextureManager *, _QWORD, _QWORD, void *, unsigned int, Scaleform::Render::ImageSource *, _QWORD))vfptr[1].__vecDelDtor)(
                                               args->pManager,
                                               (unsigned int)Format,
                                               mipLevelCount,
                                               v13,
                                               Use,
                                               this,
                                               0i64);
    if ( ptexture )
    {
      v15 = (Scaleform::Render::TextureImage *)(*(__int64 (__fastcall **)(void *, __int64))(*(_QWORD *)v24 + 80i64))(
                                                 v24,
                                                 56i64);
      v24 = v15;
      if ( v15 )
      {
        v16 = (Scaleform::Render::Size<unsigned long> *)this->vfptr[5].__vecDelDtor(this, v21);
        Scaleform::Render::TextureImage::TextureImage(v15, Format, v16, Use, ptexture, psync);
        v6 = v17;
      }
    }
    if ( ptexture )
    {
      if ( !_InterlockedDecrement(&ptexture->RefCount) )
        ptexture->vfptr->__vecDelDtor(ptexture, 1u);
    }
  }
  else
  {
    v18 = (Scaleform::Render::Size<unsigned long> *)this->vfptr[5].__vecDelDtor(this, &v24);
    result = Scaleform::Render::RawImage::Create(Format, mipLevelCount, v18, Use, pHeap, psync);
    v20 = result;
    if ( !result )
      return result;
    *(_QWORD *)&v22.Format = 0i64;
    *(_DWORD *)&v22.Flags = 0x10000;
    v22.pPlanes = &v22.Plane0;
    memset(&v22.pPalette, 0, 40);
    Scaleform::Render::ImageData::operator=(&v22, &result->Data);
    if ( ((unsigned __int8 (__fastcall *)(Scaleform::Render::ImageSource *, Scaleform::Render::ImageData *, _QWORD, _QWORD))this->vfptr[8].__vecDelDtor)(
           this,
           &v22,
           Scaleform::Render::ImageBase::CopyScanlineDefault,
           0i64) )
    {
      v6 = v20;
    }
    else
    {
      ((void (__fastcall *)(Scaleform::Render::RawImage *))v20->vfptr[2].__vecDelDtor)(v20);
    }
    if ( (v22.Flags & 2) != 0 )
    {
      v22.Flags &= ~2u;
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v22.pPlanes);
    }
    v22.pPlanes = &v22.Plane0;
    if ( v22.pPalette.pObject && !_InterlockedDecrement(&v22.pPalette.pObject->RefCount.Value) )
      ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  }
  return v6;
}

// File Line: 1096
// RVA: 0x94C200
void __fastcall Scaleform::Render::RawImage::~RawImage(Scaleform::Render::RawImage *this)
{
  char Flags; // al
  Scaleform::Render::Palette *pObject; // rdx

  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::RawImage::`vftable;
  Scaleform::Render::RawImage::freeData(this);
  Flags = this->Data.Flags;
  if ( (Flags & 2) != 0 )
  {
    this->Data.Flags = Flags & 0xFD;
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, this->Data.pPlanes);
  }
  this->Data.pPlanes = &this->Data.Plane0;
  pObject = this->Data.pPalette.pObject;
  if ( pObject && !_InterlockedDecrement(&pObject->RefCount.Value) )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  Scaleform::Render::Image::~Image(this);
}

// File Line: 1115
// RVA: 0x9E3560
void __fastcall Scaleform::Render::RawImage::freeData(Scaleform::Render::RawImage *this)
{
  unsigned int i; // ebx
  __int64 v3; // rdi

  for ( i = 0; i < this->Data.RawPlaneCount; ++i )
  {
    v3 = i;
    if ( this->Data.pPlanes[v3].pData )
    {
      ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      this->Data.pPlanes[v3].pData = 0i64;
    }
  }
}

// File Line: 1131
// RVA: 0x9659D0
Scaleform::Render::RawImage *__fastcall Scaleform::Render::RawImage::Create(
        Scaleform::Render::ImageFormat format,
        unsigned int mipLevelCount,
        Scaleform::Render::Size<unsigned long> *size,
        unsigned __int16 use,
        Scaleform::MemoryHeap *pheap,
        Scaleform::Render::ImageUpdateSync *pupdateSync)
{
  Scaleform::Render::ImageFormat v9; // r13d
  Scaleform::MemoryHeap *v10; // r12
  Scaleform::Render::RawImage *v11; // rax
  unsigned int v12; // ebp
  __int64 v13; // rax
  __int64 v14; // r14
  unsigned int v15; // eax
  unsigned int Width; // edi
  unsigned int Height; // esi
  unsigned __int64 MipLevelsSize; // r13
  __int64 v19; // rbx
  __int64 v21; // [rsp+20h] [rbp-48h]
  unsigned int v24; // [rsp+88h] [rbp+20h]

  v9 = format;
  v10 = pheap;
  if ( !pheap )
    v10 = Scaleform::Memory::pGlobalHeap;
  pheap = v10;
  if ( (use & 2) == 0 || mipLevelCount == 1 )
  {
    v11 = (Scaleform::Render::RawImage *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))v10->vfptr->Alloc)(
                                           v10,
                                           104i64);
    v12 = 0;
    if ( v11 )
    {
      Scaleform::Render::RawImage::RawImage(v11);
      v14 = v13;
    }
    else
    {
      v14 = 0i64;
    }
    if ( v14 )
    {
      Scaleform::Render::ImageData::Clear((Scaleform::Render::ImageData *)(v14 + 40));
      if ( Scaleform::Render::ImageData::allocPlanes((Scaleform::Render::ImageData *)(v14 + 40), v9, mipLevelCount, 0) )
      {
        *(_DWORD *)(v14 + 44) = use;
        *(_QWORD *)(v14 + 24) = pupdateSync;
        if ( !*(_WORD *)(v14 + 50) )
          return (Scaleform::Render::RawImage *)v14;
        v15 = (v9 & 0xFFF) - 200;
        v24 = v15;
        while ( 1 )
        {
          if ( v15 > 1 || v12 - 1 > 1 )
          {
            Width = size->Width;
            Height = size->Height;
          }
          else
          {
            Width = size->Width >> 1;
            Height = size->Height >> 1;
          }
          pheap = (Scaleform::MemoryHeap *)__PAIR64__(Height, Width);
          MipLevelsSize = Scaleform::Render::ImageData::GetMipLevelsSize(
                            v9,
                            (Scaleform::Render::Size<unsigned long> *)&pheap,
                            mipLevelCount,
                            v12);
          v21 = (__int64)v10->vfptr->Alloc(v10, MipLevelsSize, 0i64);
          if ( !v21 )
            break;
          v19 = *(_QWORD *)(v14 + 56) + 32i64 * v12;
          *(_DWORD *)v19 = Width;
          *(_DWORD *)(v19 + 4) = Height;
          *(_QWORD *)(v19 + 8) = Scaleform::Render::ImageData::GetFormatPitch(format, Width, v12);
          *(_QWORD *)(v19 + 16) = MipLevelsSize;
          *(_QWORD *)(v19 + 24) = v21;
          ++v12;
          v15 = v24;
          v9 = format;
          if ( v12 >= *(unsigned __int16 *)(v14 + 50) )
            return (Scaleform::Render::RawImage *)v14;
        }
      }
      (*(void (__fastcall **)(__int64))(*(_QWORD *)v14 + 16i64))(v14);
    }
  }
  return 0i64;
}

// File Line: 1204
// RVA: 0x999270
char __fastcall Scaleform::Render::RawImage::Map(
        Scaleform::Render::RawImage *this,
        Scaleform::Render::ImageData *pdata,
        unsigned int levelIndex,
        unsigned int levelCount)
{
  if ( !Scaleform::Render::ImageData::Initialize(pdata, &this->Data, levelIndex, levelCount) )
    return 0;
  this->Data.Flags |= 0x10u;
  return 1;
}

// File Line: 1215
// RVA: 0x9BB630
char __fastcall Scaleform::Render::RawImage::Unmap(Scaleform::Render::RawImage *this)
{
  this->Data.Flags &= ~0x10u;
  return 1;
}

// File Line: 1225
// RVA: 0x96B560
char __fastcall Scaleform::Render::RawImage::Decode(
        Scaleform::Render::RawImage *this,
        Scaleform::Render::ImageData *pdest,
        void (__fastcall *copyScanline)(char *, const char *, unsigned __int64, Scaleform::Render::Palette *, void *),
        void *arg)
{
  unsigned int v4; // r13d
  Scaleform::Render::ImageData *v5; // r15
  Scaleform::Render::ImageFormat Format; // edx
  int v8; // eax
  unsigned int v9; // r8d
  int LevelCount; // ecx
  unsigned int v11; // r12d
  unsigned int v12; // ecx
  __int64 v13; // rdi
  unsigned int RawPlaneCount; // ecx
  Scaleform::Render::ImagePlane *v15; // rcx
  unsigned __int64 DataSize; // rsi
  char *pData; // r14
  unsigned int Height; // eax
  unsigned __int64 Pitch; // rax
  unsigned int v20; // ecx
  Scaleform::Render::ImagePlane *v21; // rcx
  unsigned __int64 v22; // rax
  char *v23; // rcx
  unsigned int v24; // edi
  int v25; // edx
  __int64 v26; // r8
  int v27; // r10d
  char *v28; // rsi
  unsigned __int8 v29; // dl
  char *v30; // r14
  unsigned int v31; // r13d
  int v32; // r8d
  unsigned int v33; // ecx
  unsigned int v34; // eax
  Scaleform::Render::ImagePlane *v35; // rcx
  unsigned __int64 v36; // rdx
  unsigned __int64 v37; // rdi
  unsigned __int64 v38; // rax
  char *v39; // rax
  char *v40; // rax
  Scaleform::Render::ImagePlane *v41; // rcx
  unsigned __int64 v42; // rdx
  unsigned int v43; // ecx
  unsigned int v44; // eax
  __int64 v45; // rcx
  unsigned __int64 v46; // r12
  unsigned int v47; // eax
  char *v48; // rax
  char *v49; // rax
  __int64 v50; // rcx
  unsigned int v51; // eax
  unsigned __int64 v52; // rax
  unsigned int FormatBitsPerPixel; // eax
  unsigned int v54; // eax
  unsigned __int64 v55; // r13
  unsigned __int64 v56; // r15
  unsigned __int8 v57; // dl
  unsigned __int8 v58; // cl
  unsigned int v59; // r9d
  unsigned __int8 v60; // r8
  unsigned int v61; // eax
  unsigned int v62; // ecx
  char *v63; // rcx
  unsigned __int64 v64; // r14
  unsigned __int64 v65; // r13
  unsigned __int64 v66; // rax
  char *v67; // rsi
  unsigned int v68; // ecx
  char *v69; // rcx
  unsigned __int64 v70; // r12
  char *v71; // rdi
  unsigned int v72; // eax
  unsigned __int64 v73; // rax
  unsigned int v74; // eax
  unsigned __int64 v75; // r15
  unsigned int v77; // [rsp+30h] [rbp-69h]
  unsigned int Width; // [rsp+30h] [rbp-69h]
  Scaleform::Render::ImagePlane p; // [rsp+38h] [rbp-61h] BYREF
  unsigned int v80; // [rsp+58h] [rbp-41h]
  unsigned int v81; // [rsp+5Ch] [rbp-3Dh]
  Scaleform::Render::ImagePlane v82; // [rsp+60h] [rbp-39h] BYREF
  int v83; // [rsp+80h] [rbp-19h]
  int v84; // [rsp+84h] [rbp-15h]
  int v85; // [rsp+88h] [rbp-11h]
  unsigned __int64 v86; // [rsp+90h] [rbp-9h]
  unsigned int v87; // [rsp+98h] [rbp-1h]
  __int64 v88; // [rsp+A0h] [rbp+7h]
  int v89; // [rsp+100h] [rbp+67h]

  v4 = 0;
  v5 = pdest;
  Format = this->Data.Format;
  memset(&p, 0, sizeof(p));
  memset(&v82, 0, sizeof(v82));
  v89 = Format & 0xFFF;
  v8 = 1;
  if ( (Format & 0xFFF) != 0 )
  {
    if ( (Format & 0xFFF) == 200 )
    {
      v9 = 3;
    }
    else if ( (Format & 0xFFF) == 201 )
    {
      v9 = 4;
    }
    else
    {
      v9 = 1;
    }
  }
  else
  {
    v9 = 0;
  }
  v80 = v9;
  if ( (this->Data.Flags & 1) != 0 )
    LevelCount = (unsigned __int8)this->Data.LevelCount;
  else
    LevelCount = 1;
  v11 = LevelCount * this->Data.RawPlaneCount;
  if ( (v5->Flags & 1) != 0 )
    v8 = (unsigned __int8)v5->LevelCount;
  v12 = v8 * v5->RawPlaneCount;
  if ( (int)(Format & 0xFFEFFFFF) >= 4096 )
  {
    if ( v11 )
    {
      v13 = 0i64;
      do
      {
        RawPlaneCount = this->Data.RawPlaneCount;
        if ( v4 >= RawPlaneCount )
        {
          Scaleform::Render::ImagePlane::GetMipLevel(
            &this->Data.pPlanes[v4 % RawPlaneCount],
            this->Data.Format,
            v4 / RawPlaneCount,
            &p,
            v4 % RawPlaneCount);
          pData = p.pData;
          DataSize = p.DataSize;
        }
        else
        {
          v15 = &this->Data.pPlanes[v13];
          DataSize = v15->DataSize;
          pData = v15->pData;
          p.Width = v15->Width;
          Height = v15->Height;
          p.DataSize = DataSize;
          p.Height = Height;
          Pitch = v15->Pitch;
          p.pData = pData;
          p.Pitch = Pitch;
        }
        v20 = v5->RawPlaneCount;
        if ( v4 >= v20 )
        {
          Scaleform::Render::ImagePlane::GetMipLevel(&v5->pPlanes[v4 % v20], v5->Format, v4 / v20, &v82, v4 % v20);
          v23 = v82.pData;
        }
        else
        {
          v21 = &v5->pPlanes[v13];
          v82.Width = v21->Width;
          v82.Height = v21->Height;
          v82.Pitch = v21->Pitch;
          v22 = v21->DataSize;
          v23 = v21->pData;
          v82.pData = v23;
          v82.DataSize = v22;
        }
        memmove(v23, pData, DataSize);
        ++v4;
        ++v13;
      }
      while ( v4 < v11 );
    }
    return 1;
  }
  v24 = 0;
  v81 = 0;
  if ( v11 < v12 )
    v12 = v11;
  v87 = v12;
  if ( v12 )
  {
    v88 = 0i64;
    v25 = v12 % v9;
    v26 = 0i64;
    v27 = v25;
    v83 = v25;
    do
    {
      if ( ((this->Data.Flags & 1) != 0 || this->Data.LevelCount == 1) && ((v5->Flags & 1) != 0 || v5->LevelCount == 1) )
      {
        v62 = this->Data.RawPlaneCount;
        if ( v24 >= v62 )
        {
          Scaleform::Render::ImagePlane::GetMipLevel(
            &this->Data.pPlanes[v24 % v62],
            this->Data.Format,
            v24 / v62,
            &p,
            v24 % v62);
          v67 = p.pData;
          v65 = p.Pitch;
          v64 = p.Height;
          v26 = v88;
          Width = p.Width;
        }
        else
        {
          v63 = (char *)this->Data.pPlanes + v26;
          v64 = *((unsigned int *)v63 + 1);
          v65 = *((_QWORD *)v63 + 1);
          v66 = *((_QWORD *)v63 + 2);
          v67 = (char *)*((_QWORD *)v63 + 3);
          Width = *(_DWORD *)v63;
          p.Width = *(_DWORD *)v63;
          p.Height = v64;
          p.Pitch = v65;
          p.DataSize = v66;
          p.pData = v67;
        }
        v68 = v5->RawPlaneCount;
        if ( v24 >= v68 )
        {
          Scaleform::Render::ImagePlane::GetMipLevel(&v5->pPlanes[v24 % v68], v5->Format, v24 / v68, &v82, v24 % v68);
          v71 = v82.pData;
          v70 = v82.Pitch;
        }
        else
        {
          v69 = (char *)v5->pPlanes + v26;
          v70 = *((_QWORD *)v69 + 1);
          v71 = (char *)*((_QWORD *)v69 + 3);
          v82.Width = *(_DWORD *)v69;
          v72 = *((_DWORD *)v69 + 1);
          v82.Pitch = v70;
          v82.Height = v72;
          v73 = *((_QWORD *)v69 + 2);
          v82.pData = v71;
          v82.DataSize = v73;
        }
        if ( (unsigned int)(v89 - 50) <= 3 )
          v64 = (unsigned __int64)(unsigned int)(v64 + 3) >> 2;
        v74 = (Width * Scaleform::Render::ImageData::GetFormatBitsPerPixel(this->Data.Format, 0)) >> 3;
        if ( v64 )
        {
          v75 = v74;
          do
          {
            copyScanline(v71, v67, v75, this->Data.pPalette.pObject, arg);
            v67 += v65;
            v71 += v70;
            --v64;
          }
          while ( v64 );
          v5 = pdest;
        }
      }
      else
      {
        v28 = 0i64;
        v29 = v5->LevelCount;
        v30 = 0i64;
        if ( (unsigned int)this->Data.LevelCount < v29 )
          v29 = this->Data.LevelCount;
        v85 = 0;
        if ( !v29 )
          goto LABEL_81;
        v31 = v24;
        v77 = v24;
        v32 = v27 - v24;
        v84 = v27 - v24;
        do
        {
          v33 = this->Data.RawPlaneCount;
          if ( (this->Data.Flags & 1) != 0 )
          {
            v34 = v32 + v31;
            if ( v32 + v31 >= v33 )
            {
              Scaleform::Render::ImagePlane::GetMipLevel(
                &this->Data.pPlanes[v34 % v33],
                this->Data.Format,
                v34 / v33,
                &p,
                v34 % v33);
              v40 = p.pData;
              v37 = p.Height;
              v32 = v84;
              if ( v28 )
                v40 = v28;
              v86 = p.Pitch;
              v28 = v40;
            }
            else
            {
              v35 = &this->Data.pPlanes[v34];
              v36 = v35->Pitch;
              v37 = v35->Height;
              p.Width = v35->Width;
              v38 = v35->DataSize;
              p.Height = v37;
              p.DataSize = v38;
              v39 = v35->pData;
              v86 = v36;
              p.pData = v39;
              if ( v28 )
                v39 = v28;
              p.Pitch = v36;
              v28 = v39;
            }
          }
          else if ( v31 >= v33 )
          {
            Scaleform::Render::ImagePlane::GetMipLevel(
              &this->Data.pPlanes[v31 % v33],
              this->Data.Format,
              v31 / v33,
              &p,
              v31 % v33);
            v28 = p.pData;
            v37 = p.Height;
            v32 = v84;
            v86 = p.Pitch;
          }
          else
          {
            v41 = &this->Data.pPlanes[v31];
            v42 = v41->Pitch;
            v37 = v41->Height;
            v28 = v41->pData;
            p.Width = v41->Width;
            p.DataSize = v41->DataSize;
            p.Height = v37;
            v86 = v42;
            p.Pitch = v42;
            p.pData = v28;
          }
          v43 = v5->RawPlaneCount;
          if ( (v5->Flags & 1) != 0 )
          {
            v44 = v32 + v31;
            if ( v32 + v31 >= v43 )
            {
              Scaleform::Render::ImagePlane::GetMipLevel(
                &v5->pPlanes[v44 % v43],
                v5->Format,
                v44 / v43,
                &v82,
                v44 % v43);
              v49 = v82.pData;
              v46 = v82.Pitch;
              if ( v30 )
                v49 = v30;
              v30 = v49;
            }
            else
            {
              v45 = (__int64)&v5->pPlanes[v44];
              v46 = *(_QWORD *)(v45 + 8);
              v82.Width = *(_DWORD *)v45;
              v47 = *(_DWORD *)(v45 + 4);
              v82.Pitch = v46;
              v82.Height = v47;
              v82.DataSize = *(_QWORD *)(v45 + 16);
              v48 = *(char **)(v45 + 24);
              v82.pData = v48;
              if ( v30 )
                v48 = v30;
              v30 = v48;
            }
          }
          else if ( v31 >= v43 )
          {
            Scaleform::Render::ImagePlane::GetMipLevel(&v5->pPlanes[v31 % v43], v5->Format, v31 / v43, &v82, v31 % v43);
            v30 = v82.pData;
            v46 = v82.Pitch;
          }
          else
          {
            v50 = (__int64)&v5->pPlanes[v31];
            v46 = *(_QWORD *)(v50 + 8);
            v30 = *(char **)(v50 + 24);
            v82.Width = *(_DWORD *)v50;
            v51 = *(_DWORD *)(v50 + 4);
            v82.Pitch = v46;
            v82.Height = v51;
            v52 = *(_QWORD *)(v50 + 16);
            v82.pData = v30;
            v82.DataSize = v52;
          }
          if ( (unsigned int)(v89 - 50) <= 3 )
            v37 = (unsigned __int64)(unsigned int)(v37 + 3) >> 2;
          FormatBitsPerPixel = Scaleform::Render::ImageData::GetFormatBitsPerPixel(this->Data.Format, 0);
          v54 = (p.Width * FormatBitsPerPixel) >> 3;
          if ( v37 )
          {
            v55 = v86;
            v56 = v54;
            do
            {
              copyScanline(v30, v28, v56, this->Data.pPalette.pObject, arg);
              v28 += v55;
              v30 += v46;
              --v37;
            }
            while ( v37 );
            v5 = pdest;
            v31 = v77;
          }
          v31 += v80;
          v57 = v5->LevelCount;
          v58 = this->Data.LevelCount;
          v59 = v85 + 1;
          v60 = v57;
          ++v85;
          v77 = v31;
          if ( v58 < v57 )
            v60 = v58;
          v61 = v60;
          v32 = v84;
        }
        while ( v59 < v61 );
      }
      v24 = v81;
      v27 = v83;
LABEL_81:
      ++v24;
      v26 = v88 + 32;
      v81 = v24;
      v88 += 32i64;
    }
    while ( v24 < v87 );
  }
  return 1;
}   v58 = this->Data.LevelCount;
          v59 = v85 + 1;
          v60 = v57;
          ++

// File Line: 1332
// RVA: 0x98DB60
Scaleform::Render::Texture *__fastcall Scaleform::Render::RawImage::GetTexture(
        Scaleform::Render::RawImage *this,
        Scaleform::Render::TextureManager *pmanager)
{
  Scaleform::Render::TextureManagerLocks *pObject; // rax
  Scaleform::Render::TextureManager *v5; // rax
  Scaleform::Render::Texture *result; // rax
  Scaleform::Render::ImagePlane *pPlanes; // rax
  Scaleform::RefCountImplCoreVtbl *vfptr; // r10
  int Height; // ecx
  __int64 LevelCount; // r8
  __int64 Format; // rdx
  unsigned int Width; // [rsp+50h] [rbp+8h] BYREF
  int v13; // [rsp+54h] [rbp+Ch]

  if ( this->pTexture.Value )
  {
    pObject = this->pTexture.Value->pManagerLocks.pObject;
    v5 = pObject ? pObject->pManager : 0i64;
    if ( v5 == pmanager )
      return this->pTexture.Value;
  }
  if ( !pmanager )
    return 0i64;
  this->pTexture.Value = 0i64;
  pPlanes = this->Data.pPlanes;
  vfptr = pmanager->Scaleform::RefCountBase<Scaleform::Render::TextureManager,72>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,72>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr;
  Height = pPlanes->Height;
  LevelCount = (unsigned __int8)this->Data.LevelCount;
  Format = (unsigned int)this->Data.Format;
  Width = pPlanes->Width;
  LODWORD(pPlanes) = this->Data.Use;
  v13 = Height;
  result = (Scaleform::Render::Texture *)((__int64 (__fastcall *)(Scaleform::Render::TextureManager *, __int64, __int64, unsigned int *, unsigned int, Scaleform::Render::RawImage *, _QWORD))vfptr[1].__vecDelDtor)(
                                           pmanager,
                                           Format,
                                           LevelCount,
                                           &Width,
                                           (unsigned int)pPlanes & 0xFFFFFF3F,
                                           this,
                                           0i64);
  this->pTexture.Value = result;
  return result;
}

// File Line: 1386
// RVA: 0x988E70
char __fastcall Scaleform::Render::SubImage::GetMatrixInverse(
        Scaleform::Render::SubImage *this,
        Scaleform::Render::Matrix2x4<float> *mat)
{
  char result; // al
  bool v5; // cl
  float *pInverseMatrix; // rdx
  Scaleform::Render::Matrix2x4<float> *v7; // rax
  __m128 v8; // xmm5
  __m128 v9; // xmm4
  __m128 v10; // xmm7
  __m128 v11; // xmm0
  __m128 v12; // xmm2
  __m128 v13; // xmm5

  result = ((__int64 (__fastcall *)(Scaleform::Render::Image *))this->pImage.pObject->vfptr[16].__vecDelDtor)(this->pImage.pObject);
  v5 = result;
  if ( !result )
  {
    pInverseMatrix = (float *)this->pInverseMatrix;
    if ( !pInverseMatrix )
      return result;
    mat->M[0][0] = *pInverseMatrix;
    mat->M[0][1] = pInverseMatrix[1];
    mat->M[0][2] = pInverseMatrix[2];
    mat->M[0][3] = pInverseMatrix[3];
    mat->M[1][0] = pInverseMatrix[4];
    mat->M[1][1] = pInverseMatrix[5];
    mat->M[1][2] = pInverseMatrix[6];
    mat->M[1][3] = pInverseMatrix[7];
  }
  v7 = this->pInverseMatrix;
  if ( v7 )
  {
    if ( v5 )
    {
      v8 = *(__m128 *)&v7->M[1][0];
      v9 = *(__m128 *)&mat->M[0][0];
      v10 = (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<4294967295,4294967295,0,4294967295>::`2::v;
      v11 = _mm_shuffle_ps(v8, v8, 0);
      v12 = _mm_shuffle_ps(v8, v8, 85);
      v13 = _mm_and_ps(v8, (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>::`2::v);
      *(__m128 *)&mat->M[0][0] = _mm_and_ps(
                                   _mm_add_ps(
                                     _mm_add_ps(
                                       _mm_mul_ps(
                                         _mm_shuffle_ps(*(__m128 *)&v7->M[0][0], *(__m128 *)&v7->M[0][0], 85),
                                         *(__m128 *)&mat->M[1][0]),
                                       _mm_mul_ps(
                                         _mm_shuffle_ps(*(__m128 *)&v7->M[0][0], *(__m128 *)&v7->M[0][0], 0),
                                         *(__m128 *)&mat->M[0][0])),
                                     _mm_and_ps(
                                       *(__m128 *)&v7->M[0][0],
                                       (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>::`2::v)),
                                   (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<4294967295,4294967295,0,4294967295>::`2::v);
      *(__m128 *)&mat->M[1][0] = _mm_and_ps(
                                   _mm_add_ps(
                                     _mm_add_ps(_mm_mul_ps(v12, *(__m128 *)&mat->M[1][0]), _mm_mul_ps(v11, v9)),
                                     v13),
                                   v10);
    }
  }
  return 1;
}

// File Line: 1417
// RVA: 0x94B0E0
void __fastcall Scaleform::Render::ImageUpdateQueue::~ImageUpdateQueue(Scaleform::Render::ImageUpdateQueue *this)
{
  unsigned int v2; // edi
  __int64 v3; // rax
  unsigned __int64 v4; // rcx

  v2 = 0;
  if ( this->Queue.Data.Size )
  {
    v3 = 0i64;
    do
    {
      v4 = this->Queue.Data.Data[v3];
      if ( (v4 & 1) != 0 )
      {
        (*(void (__fastcall **)(unsigned __int64))(*(_QWORD *)(v4 & 0xFFFFFFFFFFFFFFFEui64) + 16i64))(v4 & 0xFFFFFFFFFFFFFFFEui64);
      }
      else if ( !_InterlockedDecrement((volatile signed __int32 *)(v4 + 8)) && v4 )
      {
        (**(void (__fastcall ***)(unsigned __int64, __int64))v4)(v4, 1i64);
      }
      v3 = ++v2;
    }
    while ( v2 < this->Queue.Data.Size );
  }
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, this->Queue.Data.Data);
}

// File Line: 1434
// RVA: 0x9A04D0
void __fastcall Scaleform::Render::ImageUpdateQueue::ProcessUpdates(
        Scaleform::Render::ImageUpdateQueue *this,
        Scaleform::Render::TextureManager *pmanager)
{
  unsigned int v2; // esi
  __int64 v5; // rax
  volatile signed __int32 *v6; // rbx
  unsigned __int64 v7; // rbx
  __int64 v8; // rax
  unsigned __int64 *v9; // rax
  int v10; // [rsp+30h] [rbp+8h] BYREF

  v2 = 0;
  if ( this->Queue.Data.Size )
  {
    v5 = 0i64;
    do
    {
      v6 = (volatile signed __int32 *)this->Queue.Data.Data[v5];
      if ( ((unsigned __int8)v6 & 1) != 0 )
      {
        v7 = (unsigned __int64)v6 & 0xFFFFFFFFFFFFFFFEui64;
        v8 = (*(__int64 (__fastcall **)(unsigned __int64, Scaleform::Render::TextureManager *))(*(_QWORD *)v7 + 168i64))(
               v7,
               pmanager);
        if ( v8 )
          (*(void (__fastcall **)(__int64))(*(_QWORD *)v8 + 136i64))(v8);
        (*(void (__fastcall **)(unsigned __int64))(*(_QWORD *)v7 + 16i64))(v7);
      }
      else
      {
        (*(void (__fastcall **)(volatile signed __int32 *, Scaleform::Render::TextureManager *))(*(_QWORD *)v6 + 8i64))(
          v6,
          pmanager);
        if ( !_InterlockedDecrement(v6 + 2) )
          (**(void (__fastcall ***)(volatile signed __int32 *, __int64))v6)(v6, 1i64);
      }
      v5 = ++v2;
    }
    while ( v2 < this->Queue.Data.Size );
  }
  if ( this->Queue.Data.Size && (this->Queue.Data.Policy.Capacity & 0xFFFFFFFFFFFFFFFEui64) != 0 )
  {
    if ( this->Queue.Data.Data )
    {
      v9 = (unsigned __int64 *)Scaleform::Memory::pGlobalHeap->vfptr->Realloc(
                                 Scaleform::Memory::pGlobalHeap,
                                 this->Queue.Data.Data,
                                 32i64);
    }
    else
    {
      v10 = 72;
      v9 = (unsigned __int64 *)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                                 Scaleform::Memory::pGlobalHeap,
                                 this,
                                 32i64,
                                 &v10);
    }
    this->Queue.Data.Data = v9;
    this->Queue.Data.Policy.Capacity = 4i64;
  }
  this->Queue.Data.Size = 0i64;
}

// File Line: 1456
// RVA: 0x953DF0
void __fastcall Scaleform::Render::ImageUpdateQueue::Add(
        Scaleform::Render::ImageUpdateQueue *this,
        unsigned __int64 pimage)
{
  unsigned __int64 Size; // rax
  unsigned __int64 v4; // rdi
  unsigned __int64 v5; // rbp
  unsigned __int64 v7; // r8
  unsigned __int64 *Data; // rcx
  unsigned __int64 *v9; // rcx

  Size = this->Queue.Data.Size;
  v4 = Size + 1;
  v5 = pimage | 1;
  if ( Size + 1 >= Size )
  {
    if ( v4 <= this->Queue.Data.Policy.Capacity )
      goto LABEL_7;
    v7 = v4 + (v4 >> 2);
  }
  else
  {
    if ( v4 >= this->Queue.Data.Policy.Capacity >> 1 )
      goto LABEL_7;
    v7 = Size + 1;
  }
  Scaleform::ArrayDataBase<unsigned __int64,Scaleform::AllocatorLH<unsigned __int64,72>,Scaleform::ArrayConstPolicy<4,4,0>>::Reserve(
    &this->Queue.Data,
    this,
    v7);
LABEL_7:
  Data = this->Queue.Data.Data;
  this->Queue.Data.Size = v4;
  v9 = &Data[v4 - 1];
  if ( v9 )
    *v9 = v5;
  (*(void (__fastcall **)(unsigned __int64))(*(_QWORD *)pimage + 8i64))(pimage);
}

// File Line: 1463
// RVA: 0x953E80
void __fastcall Scaleform::Render::ImageUpdateQueue::Add(
        Scaleform::Render::ImageUpdateQueue *this,
        Scaleform::Render::ImageUpdate *pupdate)
{
  unsigned __int64 Size; // rax
  unsigned __int64 v5; // rdi
  unsigned __int64 v6; // r8
  unsigned __int64 *Data; // rcx
  unsigned __int64 *v8; // rcx

  Size = this->Queue.Data.Size;
  v5 = Size + 1;
  if ( Size + 1 >= Size )
  {
    if ( v5 <= this->Queue.Data.Policy.Capacity )
      goto LABEL_7;
    v6 = v5 + (v5 >> 2);
  }
  else
  {
    if ( v5 >= this->Queue.Data.Policy.Capacity >> 1 )
      goto LABEL_7;
    v6 = Size + 1;
  }
  Scaleform::ArrayDataBase<unsigned __int64,Scaleform::AllocatorLH<unsigned __int64,72>,Scaleform::ArrayConstPolicy<4,4,0>>::Reserve(
    &this->Queue.Data,
    this,
    v6);
LABEL_7:
  Data = this->Queue.Data.Data;
  this->Queue.Data.Size = v5;
  v8 = &Data[v5 - 1];
  if ( v8 )
    *v8 = (unsigned __int64)pupdate;
  _InterlockedExchangeAdd(&pupdate->RefCount, 1u);
}

// File Line: 1476
// RVA: 0x946320
void __fastcall Scaleform::Render::TextureManager::TextureManager(
        Scaleform::Render::TextureManager *this,
        void *renderThreadId,
        Scaleform::Render::ThreadCommandQueue *commandQueue,
        Scaleform::Render::TextureCache *textureCache)
{
  Scaleform::Render::TextureManagerLocks *v5; // rdi
  Scaleform::List<Scaleform::Render::Texture,Scaleform::Render::Texture> *p_Textures; // rax
  unsigned __int64 *p_Size; // rcx
  Scaleform::Render::Texture *v8; // rcx
  Scaleform::List<Scaleform::Render::Texture,Scaleform::Render::Texture> *p_TextureInitQueue; // rcx
  Scaleform::Render::TextureManagerLocks *v10; // rax
  Scaleform::Render::TextureManagerLocks *v11; // rax
  Scaleform::Render::TextureManagerLocks *pObject; // rcx
  Scaleform::ArrayLH<Scaleform::Render::TextureFormat *,2,Scaleform::ArrayDefaultPolicy> *p_TextureFormats; // [rsp+58h] [rbp+10h] BYREF
  void *p_ServiceCommandInstance; // [rsp+60h] [rbp+18h]
  Scaleform::Render::ImageUpdateQueue *p_ImageUpdates; // [rsp+68h] [rbp+20h]

  this->Scaleform::RefCountBase<Scaleform::Render::TextureManager,72>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,72>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->Scaleform::RefCountBase<Scaleform::Render::TextureManager,72>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,72>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->Scaleform::RefCountBase<Scaleform::Render::TextureManager,72>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,72>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,72>::`vftable;
  this->Scaleform::RefCountBase<Scaleform::Render::TextureManager,72>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,72>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::Render::TextureManager,72>::`vftable;
  this->Scaleform::Render::ImageUpdateSync::vfptr = (Scaleform::Render::ImageUpdateSyncVtbl *)&Scaleform::Render::ImageUpdateSync::`vftable;
  this->Scaleform::RefCountBase<Scaleform::Render::TextureManager,72>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,72>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::TextureManager::`vftable{for `Scaleform::RefCountBase<Scaleform::Render::TextureManager,72>};
  this->Scaleform::Render::ImageUpdateSync::vfptr = (Scaleform::Render::ImageUpdateSyncVtbl *)&Scaleform::Render::TextureManager::`vftable{for `Scaleform::Render::ImageUpdateSync};
  p_ServiceCommandInstance = &this->ServiceCommandInstance;
  this->ServiceCommandInstance.vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->ServiceCommandInstance.RefCount = 1;
  this->ServiceCommandInstance.vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->ServiceCommandInstance.vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable;
  this->ServiceCommandInstance.vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::Render::ThreadCommand,2>::`vftable;
  this->ServiceCommandInstance.vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::ThreadCommand::`vftable;
  this->ServiceCommandInstance.vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::TextureManager::ServiceCommand::`vftable;
  this->ServiceCommandInstance.pManager = this;
  this->RenderThreadId = renderThreadId;
  this->pRTCommandQueue = commandQueue;
  if ( textureCache )
    _InterlockedExchangeAdd(&textureCache->RefCount, 1u);
  this->pTextureCache.pObject = textureCache;
  v5 = 0i64;
  this->pLocks.pObject = 0i64;
  p_ImageUpdates = &this->ImageUpdates;
  this->ImageUpdates.Queue.Data.Data = 0i64;
  this->ImageUpdates.Queue.Data.Size = 0i64;
  this->ImageUpdates.Queue.Data.Policy.Capacity = 0i64;
  p_TextureFormats = &this->TextureFormats;
  p_ServiceCommandInstance = &this->TextureFormats;
  this->TextureFormats.Data.Data = 0i64;
  this->TextureFormats.Data.Size = 0i64;
  this->TextureFormats.Data.Policy.Capacity = 0i64;
  p_Textures = &this->Textures;
  p_Size = &this->TextureFormats.Data.Size;
  if ( this == (Scaleform::Render::TextureManager *)-128i64 )
    p_Size = 0i64;
  p_Textures->Root.pPrev = (Scaleform::Render::Texture *)p_Size;
  this->Textures.Root.pNext = (Scaleform::Render::Texture *)p_Size;
  v8 = (Scaleform::Render::Texture *)&this->Textures;
  if ( this == (Scaleform::Render::TextureManager *)-144i64 )
    v8 = 0i64;
  this->TextureInitQueue.Root.pPrev = v8;
  this->TextureInitQueue.Root.pNext = v8;
  p_TextureInitQueue = &this->TextureInitQueue;
  if ( this == (Scaleform::Render::TextureManager *)-160i64 )
    p_TextureInitQueue = 0i64;
  this->DepthStencilInitQueue.Root.pPrev = (Scaleform::Render::DepthStencilSurface *)p_TextureInitQueue;
  this->DepthStencilInitQueue.Root.pNext = (Scaleform::Render::DepthStencilSurface *)p_TextureInitQueue;
  LODWORD(p_TextureFormats) = 72;
  v10 = (Scaleform::Render::TextureManagerLocks *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::Render::TextureManager *, __int64, Scaleform::ArrayLH<Scaleform::Render::TextureFormat *,2,Scaleform::ArrayDefaultPolicy> **, __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
                                                    Scaleform::Memory::pGlobalHeap,
                                                    this,
                                                    112i64,
                                                    &p_TextureFormats,
                                                    -2i64);
  p_ServiceCommandInstance = v10;
  if ( v10 )
  {
    Scaleform::Render::TextureManagerLocks::TextureManagerLocks(v10, this);
    v5 = v11;
  }
  pObject = this->pLocks.pObject;
  if ( pObject && !_InterlockedDecrement(&pObject->RefCount) )
    pObject->vfptr->__vecDelDtor(pObject, 1u);
  this->pLocks.pObject = v5;
}

// File Line: 1484
// RVA: 0x94D440
void __fastcall Scaleform::Render::TextureManager::~TextureManager(Scaleform::Render::TextureManager *this)
{
  unsigned int v2; // ebx
  __int64 v3; // rcx
  Scaleform::Render::TextureFormat *v4; // rcx
  Scaleform::ArrayLH<Scaleform::Render::TextureFormat *,2,Scaleform::ArrayDefaultPolicy> *p_TextureFormats; // rbx
  Scaleform::Render::TextureManagerLocks *pObject; // rcx
  Scaleform::Render::TextureCache *v7; // rcx

  this->Scaleform::RefCountBase<Scaleform::Render::TextureManager,72>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,72>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::TextureManager::`vftable{for `Scaleform::RefCountBase<Scaleform::Render::TextureManager,72>};
  this->Scaleform::Render::ImageUpdateSync::vfptr = (Scaleform::Render::ImageUpdateSyncVtbl *)&Scaleform::Render::TextureManager::`vftable{for `Scaleform::Render::ImageUpdateSync};
  v2 = 0;
  if ( this->TextureFormats.Data.Size )
  {
    v3 = 0i64;
    do
    {
      v4 = this->TextureFormats.Data.Data[v3];
      if ( v4 )
        v4->vfptr->__vecDelDtor(v4, 1u);
      v3 = ++v2;
    }
    while ( v2 < this->TextureFormats.Data.Size );
  }
  p_TextureFormats = &this->TextureFormats;
  if ( this->TextureFormats.Data.Size && (this->TextureFormats.Data.Policy.Capacity & 0xFFFFFFFFFFFFFFFEui64) != 0 )
  {
    if ( p_TextureFormats->Data.Data )
    {
      ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      p_TextureFormats->Data.Data = 0i64;
    }
    this->TextureFormats.Data.Policy.Capacity = 0i64;
  }
  this->TextureFormats.Data.Size = 0i64;
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, p_TextureFormats->Data.Data);
  Scaleform::Render::ImageUpdateQueue::~ImageUpdateQueue(&this->ImageUpdates);
  pObject = this->pLocks.pObject;
  if ( pObject && !_InterlockedDecrement(&pObject->RefCount) )
    pObject->vfptr->__vecDelDtor(pObject, 1u);
  v7 = this->pTextureCache.pObject;
  if ( v7 && !_InterlockedDecrement(&v7->RefCount) )
    v7->vfptr->__vecDelDtor(v7, 1u);
  this->ServiceCommandInstance.vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->Scaleform::Render::ImageUpdateSync::vfptr = (Scaleform::Render::ImageUpdateSyncVtbl *)&Scaleform::Render::ImageUpdateSync::`vftable;
  this->Scaleform::RefCountBase<Scaleform::Render::TextureManager,72>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,72>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
}

// File Line: 1492
// RVA: 0x9BE570
void __fastcall Scaleform::Render::TextureManager::UpdateImage(
        Scaleform::Render::TextureManager *this,
        Scaleform::Render::Image *pimage)
{
  Scaleform::Mutex *v4; // rbx

  v4 = (Scaleform::Mutex *)&this->pRTCommandQueue[8];
  Scaleform::Mutex::DoLock(v4);
  Scaleform::Render::ImageUpdateQueue::Add(
    (Scaleform::Render::ImageUpdateQueue *)&this->pTextureCache,
    (unsigned __int64)pimage);
  Scaleform::Mutex::Unlock(v4);
}

// File Line: 1498
// RVA: 0x9BE5D0
void __fastcall Scaleform::Render::TextureManager::UpdateImage(
        Scaleform::Render::TextureManager *this,
        Scaleform::Render::ImageUpdate *pupdate)
{
  Scaleform::Mutex *v4; // rbx

  v4 = (Scaleform::Mutex *)&this->pRTCommandQueue[8];
  Scaleform::Mutex::DoLock(v4);
  Scaleform::Render::ImageUpdateQueue::Add((Scaleform::Render::ImageUpdateQueue *)&this->pTextureCache, pupdate);
  Scaleform::Mutex::Unlock(v4);
}

// File Line: 1504
// RVA: 0x9A0300
void __fastcall Scaleform::Render::TextureManager::ProcessQueues(Scaleform::Render::TextureManager *this)
{
  Scaleform::Mutex *p_TextureMutex; // rbx

  p_TextureMutex = &this->pLocks.pObject->TextureMutex;
  Scaleform::Mutex::DoLock(p_TextureMutex);
  ((void (__fastcall *)(Scaleform::Render::TextureManager *))this->Scaleform::RefCountBase<Scaleform::Render::TextureManager,72>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,72>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr[16].__vecDelDtor)(this);
  ((void (__fastcall *)(Scaleform::Render::TextureManager *))this->Scaleform::RefCountBase<Scaleform::Render::TextureManager,72>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,72>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr[17].__vecDelDtor)(this);
  Scaleform::Render::ImageUpdateQueue::ProcessUpdates(&this->ImageUpdates, this);
  Scaleform::Mutex::Unlock(p_TextureMutex);
}

// File Line: 1512
// RVA: 0x95A800
void __fastcall Scaleform::Render::TextureManager::BeginFrame(Scaleform::Render::TextureManager *this)
{
  Scaleform::Render::TextureCache *pObject; // rcx

  ((void (__fastcall *)(Scaleform::Render::TextureManager *))this->Scaleform::RefCountBase<Scaleform::Render::TextureManager,72>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,72>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr[8].__vecDelDtor)(this);
  pObject = this->pTextureCache.pObject;
  if ( pObject )
    ((void (__fastcall *)(Scaleform::Render::TextureCache *))pObject->vfptr[1].__vecDelDtor)(pObject);
}

// File Line: 1519
// RVA: 0x970A20
void __fastcall Scaleform::Render::TextureManager::EndFrame(Scaleform::Render::TextureManager *this)
{
  Scaleform::Render::TextureCache *pObject; // rcx

  pObject = this->pTextureCache.pObject;
  if ( pObject )
    ((void (__fastcall *)(Scaleform::Render::TextureCache *))pObject->vfptr[2].__vecDelDtor)(pObject);
}

// File Line: 1525
// RVA: 0x9EC260
Scaleform::Render::TextureFormat *__fastcall Scaleform::Render::TextureManager::precreateTexture(
        Scaleform::Render::TextureManager *this,
        unsigned int format,
        __int16 use,
        Scaleform::Render::ImageBase *pimage)
{
  void *v9; // rsi

  if ( pimage )
  {
    if ( (((unsigned __int16)format ^ ((unsigned __int16 (__fastcall *)(Scaleform::Render::ImageBase *))pimage->vfptr[4].__vecDelDtor)(pimage)) & 0xFFF) != 0
      || !((unsigned int (__fastcall *)(Scaleform::Render::ImageBase *))pimage->vfptr[3].__vecDelDtor)(pimage)
      && (use & 0x100) == 0 )
    {
      return 0i64;
    }
  }
  else if ( (use & 0x4F0) == 0 )
  {
    return 0i64;
  }
  v9 = this->Scaleform::RefCountBase<Scaleform::Render::TextureManager,72>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,72>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr[18].__vecDelDtor(
         this,
         format);
  if ( !v9
    || (format & 0xFFF) - 50 <= 0xF && (use & 0x4E2) != 0
    || (use & 0xC0) != 0
    && !this->Scaleform::RefCountBase<Scaleform::Render::TextureManager,72>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,72>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr[19].__vecDelDtor(
          this,
          v9) )
  {
    return 0i64;
  }
  return (Scaleform::Render::TextureFormat *)v9;
}

// File Line: 1570
// RVA: 0x9EC0B0
Scaleform::Render::Texture *__fastcall Scaleform::Render::TextureManager::postCreateTexture(
        Scaleform::Render::TextureManager *this,
        Scaleform::Render::Texture *ptexture,
        __int16 use)
{
  Scaleform::Mutex *p_TextureMutex; // rbx
  Scaleform::Render::Texture *v8; // rsi
  Scaleform::Render::ImageBase *pImage; // rcx

  if ( !ptexture )
    return 0i64;
  if ( !((unsigned __int8 (__fastcall *)(Scaleform::Render::Texture *))ptexture->vfptr[2].__vecDelDtor)(ptexture) )
  {
    if ( !_InterlockedDecrement(&ptexture->RefCount) )
      ptexture->vfptr->__vecDelDtor(ptexture, 1i64);
    return 0i64;
  }
  p_TextureMutex = &this->pLocks.pObject->TextureMutex;
  Scaleform::Mutex::DoLock(p_TextureMutex);
  if ( ((unsigned __int8 (__fastcall *)(Scaleform::Render::TextureManager *))this->Scaleform::RefCountBase<Scaleform::Render::TextureManager,72>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,72>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr[7].__vecDelDtor)(this) )
  {
    ((void (__fastcall *)(Scaleform::Render::TextureManager *))this->Scaleform::RefCountBase<Scaleform::Render::TextureManager,72>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,72>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr[16].__vecDelDtor)(this);
    ((void (__fastcall *)(Scaleform::Render::TextureManager *))this->Scaleform::RefCountBase<Scaleform::Render::TextureManager,72>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,72>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr[17].__vecDelDtor)(this);
    if ( ((unsigned __int8 (__fastcall *)(Scaleform::Render::Texture *))ptexture->vfptr[1].__vecDelDtor)(ptexture) )
    {
      ptexture->pPrev = this->Textures.Root.pPrev;
      ptexture->pNext = (Scaleform::Render::Texture *)&this->TextureFormats.Data.Size;
      this->Textures.Root.pPrev->pNext = ptexture;
      this->Textures.Root.pPrev = ptexture;
    }
  }
  else
  {
    ptexture->pPrev = this->TextureInitQueue.Root.pPrev;
    ptexture->pNext = (Scaleform::Render::Texture *)&this->Textures;
    this->TextureInitQueue.Root.pPrev->pNext = ptexture;
    this->TextureInitQueue.Root.pPrev = ptexture;
    Scaleform::Mutex::Unlock(&this->pLocks.pObject->TextureMutex);
    this->pRTCommandQueue->vfptr->PushThreadCommand(this->pRTCommandQueue, &this->ServiceCommandInstance);
    Scaleform::Mutex::DoLock(&this->pLocks.pObject->TextureMutex);
    while ( ptexture->State == State_PreCapture )
      Scaleform::WaitCondition::Wait(
        &this->pLocks.pObject->TextureInitWC,
        &this->pLocks.pObject->TextureMutex,
        0xFFFFFFFF);
  }
  v8 = 0i64;
  if ( (use & 0x100) != 0 )
  {
    pImage = ptexture->pImage;
    if ( pImage
      && ((unsigned int (__fastcall *)(Scaleform::Render::ImageBase *))pImage->vfptr[3].__vecDelDtor)(pImage) == 2 )
    {
      Scaleform::Render::RawImage::freeData((Scaleform::Render::RawImage *)ptexture->pImage);
    }
    ptexture->pImage = 0i64;
  }
  if ( ptexture->State == State_Valid )
  {
    ptexture->pImage = 0i64;
    if ( !_InterlockedDecrement(&ptexture->RefCount) )
      ptexture->vfptr->__vecDelDtor(ptexture, 1i64);
  }
  else
  {
    v8 = ptexture;
  }
  Scaleform::Mutex::Unlock(p_TextureMutex);
  return v8;
}

// File Line: 1628
// RVA: 0x9EBFA0
Scaleform::Render::DepthStencilSurface *__fastcall Scaleform::Render::TextureManager::postCreateDepthStencilSurface(
        Scaleform::Render::TextureManager *this,
        Scaleform::Render::DepthStencilSurface *pdss)
{
  Scaleform::Mutex *p_TextureMutex; // rbx

  if ( !pdss )
    return 0i64;
  p_TextureMutex = &this->pLocks.pObject->TextureMutex;
  Scaleform::Mutex::DoLock(p_TextureMutex);
  if ( ((unsigned __int8 (__fastcall *)(Scaleform::Render::TextureManager *))this->Scaleform::RefCountBase<Scaleform::Render::TextureManager,72>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,72>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr[7].__vecDelDtor)(this) )
  {
    ((void (__fastcall *)(Scaleform::Render::TextureManager *))this->Scaleform::RefCountBase<Scaleform::Render::TextureManager,72>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,72>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr[16].__vecDelDtor)(this);
    ((void (__fastcall *)(Scaleform::Render::TextureManager *))this->Scaleform::RefCountBase<Scaleform::Render::TextureManager,72>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,72>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr[17].__vecDelDtor)(this);
    ((void (__fastcall *)(Scaleform::Render::DepthStencilSurface *))pdss->vfptr[3].__vecDelDtor)(pdss);
  }
  else
  {
    pdss->pPrev = this->DepthStencilInitQueue.Root.pPrev;
    pdss->pNext = (Scaleform::Render::DepthStencilSurface *)&this->TextureInitQueue;
    this->DepthStencilInitQueue.Root.pPrev->pNext = pdss;
    this->DepthStencilInitQueue.Root.pPrev = pdss;
    if ( this->pRTCommandQueue )
    {
      Scaleform::Mutex::Unlock(&this->pLocks.pObject->TextureMutex);
      this->pRTCommandQueue->vfptr->PushThreadCommand(this->pRTCommandQueue, &this->ServiceCommandInstance);
      Scaleform::Mutex::DoLock(&this->pLocks.pObject->TextureMutex);
    }
    while ( pdss->State == State_PreCapture )
      Scaleform::WaitCondition::Wait(
        &this->pLocks.pObject->TextureInitWC,
        &this->pLocks.pObject->TextureMutex,
        0xFFFFFFFF);
  }
  Scaleform::Mutex::Unlock(p_TextureMutex);
  return pdss;
}

// File Line: 1656
// RVA: 0x9E78B0
Scaleform::Render::TextureFormat *__fastcall Scaleform::Render::TextureManager::getTextureFormat(
        Scaleform::Render::TextureManager *this,
        Scaleform::Render::ImageFormat format)
{
  unsigned int v2; // ebx
  __int64 v5; // r8
  Scaleform::Render::TextureFormat *v6; // rcx

  v2 = 0;
  if ( !this->TextureFormats.Data.Size )
    return 0i64;
  v5 = 0i64;
  while ( 1 )
  {
    v6 = this->TextureFormats.Data.Data[v5];
    if ( v6 )
    {
      if ( v6->vfptr->GetImageFormat(v6) == format )
        break;
    }
    v5 = ++v2;
    if ( v2 >= this->TextureFormats.Data.Size )
      return 0i64;
  }
  return this->TextureFormats.Data.Data[v2];
}

// File Line: 1666
// RVA: 0x9E96E0
Scaleform::Render::MappedTextureBase *__fastcall Scaleform::Render::TextureManager::mapTexture(
        Scaleform::Render::TextureManager *this,
        Scaleform::Render::Texture *ptexture,
        unsigned int mipLevel,
        unsigned int levelCount)
{
  __int64 v8; // rdi
  __int64 v9; // rbx

  v8 = ((__int64 (__fastcall *)(Scaleform::Render::TextureManager *))this->Scaleform::RefCountBase<Scaleform::Render::TextureManager,72>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,72>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr[23].__vecDelDtor)(this);
  _InterlockedCompareExchange((volatile signed __int32 *)(v8 + 20), -1, 0);
  if ( *(_DWORD *)(v8 + 20) == -1 )
  {
    v9 = v8;
  }
  else
  {
    v9 = ((__int64 (__fastcall *)(Scaleform::Render::TextureManager *))this->Scaleform::RefCountBase<Scaleform::Render::TextureManager,72>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,72>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr[24].__vecDelDtor)(this);
    if ( !v9 )
      return 0i64;
  }
  if ( (*(unsigned __int8 (__fastcall **)(__int64, Scaleform::Render::Texture *, _QWORD, _QWORD))(*(_QWORD *)v9 + 8i64))(
         v9,
         ptexture,
         mipLevel,
         levelCount) )
  {
    return (Scaleform::Render::MappedTextureBase *)v9;
  }
  if ( v9 != v8 )
    (**(void (__fastcall ***)(__int64, __int64))v9)(v9, 1i64);
  return 0i64;
}

// File Line: 1686
// RVA: 0x9F8880
void __fastcall Scaleform::Render::TextureManager::unmapTexture(
        Scaleform::Render::TextureManager *this,
        Scaleform::Render::Texture *ptexture,
        bool applyUpdate)
{
  Scaleform::Render::MappedTextureBase *pMap; // rdi

  pMap = ptexture->pMap;
  pMap->vfptr->Unmap(pMap, applyUpdate);
  if ( pMap != (Scaleform::Render::MappedTextureBase *)((__int64 (__fastcall *)(Scaleform::Render::TextureManager *))this->Scaleform::RefCountBase<Scaleform::Render::TextureManager,72>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,72>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr[23].__vecDelDtor)(this) )
    pMap->vfptr->__vecDelDtor(pMap, 1u);
}

// File Line: 1696
// RVA: 0x9874E0
Scaleform::Render::ImageSwizzler *__fastcall Scaleform::Render::TextureManager::GetImageSwizzler(
        Scaleform::Render::TextureManager *this)
{
  if ( (_S6_9 & 1) == 0 )
  {
    _S6_9 |= 1u;
    swizzler.vfptr = (Scaleform::Render::ImageSwizzlerVtbl *)&Scaleform::Render::ImageSwizzler::`vftable;
    atexit(Scaleform::Render::TextureManager::GetImageSwizzler_::_2_::_dynamic_atexit_destructor_for__swizzler__);
  }
  return &swizzler;
}

// File Line: 1704
// RVA: 0x9943A0
char __fastcall Scaleform::Render::Texture::Initialize(Scaleform::Render::Texture *this)
{
  Scaleform::Render::TextureManagerLocks *pObject; // r8
  Scaleform::RefCountImplCoreVtbl *vfptr; // r8

  pObject = this->pManagerLocks.pObject;
  if ( pObject )
    pObject = (Scaleform::Render::TextureManagerLocks *)pObject->pManager;
  vfptr = pObject->TextureMutex.vfptr;
  if ( this->State == State_Dead && vfptr )
    (*((void (__fastcall **)(Scaleform::RefCountImplCoreVtbl *, Scaleform::Render::Texture *))vfptr->__vecDelDtor + 3))(
      vfptr,
      this);
  return 1;
}

// File Line: 1712
// RVA: 0x998CF0
void __fastcall Scaleform::Render::Texture::LoseManager(Scaleform::Render::Texture *this)
{
  Scaleform::Lock *p_ImageLock; // rbx
  Scaleform::Render::Texture *pNext; // rdx
  Scaleform::Render::ImageBase *pImage; // rcx

  p_ImageLock = &this->pManagerLocks.pObject->ImageLock;
  EnterCriticalSection(&p_ImageLock->cs);
  this->pPrev->pNext = this->pNext;
  pNext = this->pNext;
  pNext->pPrev = this->pPrev;
  this->pNext = (Scaleform::Render::Texture *)-1i64;
  this->pPrev = 0i64;
  this->pNext = 0i64;
  LOBYTE(pNext) = 1;
  this->vfptr[11].__vecDelDtor(this, (unsigned int)pNext);
  this->State = 4;
  this->pFormat = 0i64;
  pImage = this->pImage;
  if ( pImage )
  {
    this->pImage = 0i64;
    pImage->vfptr[24].__vecDelDtor(pImage, 0);
  }
  LeaveCriticalSection(&p_ImageLock->cs);
}

// File Line: 1737
// RVA: 0x998DA0
void __fastcall Scaleform::Render::Texture::LoseTextureData(Scaleform::Render::Texture *this)
{
  Scaleform::Render::ImageBase *pImage; // rcx
  Scaleform::Lock *p_ImageLock; // rbx
  Scaleform::Render::ImageBase *v4; // rcx

  pImage = this->pImage;
  if ( pImage
    && ((unsigned int (__fastcall *)(Scaleform::Render::ImageBase *))pImage->vfptr[3].__vecDelDtor)(pImage) == 6 )
  {
    Scaleform::Render::DrawableImage::unmapTextureRT((Scaleform::Render::DrawableImage *)this->pImage);
  }
  p_ImageLock = &this->pManagerLocks.pObject->ImageLock;
  EnterCriticalSection(&p_ImageLock->cs);
  this->vfptr[11].__vecDelDtor(this, 0);
  this->State = State_Dead|State_Valid;
  v4 = this->pImage;
  if ( v4 )
    v4->vfptr[24].__vecDelDtor(v4, 1u);
  LeaveCriticalSection(&p_ImageLock->cs);
}

// File Line: 1763
// RVA: 0x9A7E80
void __fastcall Scaleform::Render::Texture::ReleaseHWTextures(Scaleform::Render::Texture *this, bool __formal)
{
  Scaleform::Render::TextureManagerLocks *pObject; // rcx
  Scaleform::RefCountImplCoreVtbl *vfptr; // rcx

  pObject = this->pManagerLocks.pObject;
  if ( pObject )
    pObject = (Scaleform::Render::TextureManagerLocks *)pObject->pManager;
  vfptr = pObject->TextureMutex.vfptr;
  if ( vfptr )
    (*((void (__fastcall **)(Scaleform::RefCountImplCoreVtbl *, Scaleform::Render::Texture *))vfptr->__vecDelDtor + 6))(
      vfptr,
      this);
}

// File Line: 1772
// RVA: 0x95A060
void __fastcall Scaleform::Render::Texture::ApplyTexture(
        Scaleform::Render::Texture *this,
        __int64 stage,
        Scaleform::Render::ImageFillMode *fillMode)
{
  Scaleform::Render::TextureManagerLocks *pObject; // rax
  Scaleform::Render::TextureManager *pManager; // rcx
  Scaleform::Render::TextureCache *v6; // rcx

  if ( this->State == (State_Dead|State_Valid) )
    ((void (__fastcall *)(Scaleform::Render::Texture *, __int64, Scaleform::Render::ImageFillMode *))this->vfptr[1].__vecDelDtor)(
      this,
      stage,
      fillMode);
  pObject = this->pManagerLocks.pObject;
  if ( pObject )
    pManager = pObject->pManager;
  else
    pManager = 0i64;
  v6 = pManager->pTextureCache.pObject;
  if ( v6 )
    ((void (__fastcall *)(Scaleform::Render::TextureCache *, Scaleform::Render::Texture *, Scaleform::Render::ImageFillMode *))v6->vfptr[5].__vecDelDtor)(
      v6,
      this,
      fillMode);
}

// File Line: 1786
// RVA: 0x9992A0
bool __fastcall Scaleform::Render::Texture::Map(
        Scaleform::Render::Texture *this,
        Scaleform::Render::ImageData *pdata,
        __int64 mipLevel,
        unsigned int levelCount)
{
  unsigned int v4; // ebp
  Scaleform::Render::TextureManagerLocks *pObject; // rax
  Scaleform::Render::TextureManager *pManager; // rcx
  __int64 v9; // rax
  Scaleform::Render::MappedTextureBase *pMap; // rax
  Scaleform::Render::ImagePlane *pPlanes; // r14
  int RawPlaneCount; // r15d
  Scaleform::Render::ImageFormat v13; // ebx

  v4 = levelCount;
  if ( !levelCount )
    v4 = (unsigned __int8)this->MipLevels - (_DWORD)mipLevel;
  pObject = this->pManagerLocks.pObject;
  if ( pObject )
    pManager = pObject->pManager;
  else
    pManager = 0i64;
  v9 = ((__int64 (__fastcall *)(Scaleform::Render::TextureManager *, Scaleform::Render::Texture *, __int64, _QWORD))pManager->Scaleform::RefCountBase<Scaleform::Render::TextureManager,72>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,72>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr[21].__vecDelDtor)(
         pManager,
         this,
         mipLevel,
         v4);
  if ( v9 )
  {
    pMap = this->pMap;
    pPlanes = pMap->Data.pPlanes;
    RawPlaneCount = pMap->Data.RawPlaneCount;
    v13 = ((unsigned int (__fastcall *)(Scaleform::Render::Texture *))this->vfptr[5].__vecDelDtor)(this);
    Scaleform::Render::ImageData::Clear(pdata);
    pdata->Flags |= 1u;
    pdata->Format = v13;
    pdata->LevelCount = v4;
    pdata->pPlanes = pPlanes;
    pdata->RawPlaneCount = RawPlaneCount;
    if ( pPlanes && RawPlaneCount == 1 )
    {
      pdata->Plane0.Width = pPlanes->Width;
      pdata->Plane0.Height = pPlanes->Height;
      pdata->Plane0.Pitch = pPlanes->Pitch;
      pdata->Plane0.DataSize = pPlanes->DataSize;
      pdata->Plane0.pData = pPlanes->pData;
    }
    pdata->Use = this->Use;
    LOBYTE(v9) = 1;
  }
  return v9;
}

// File Line: 1806
// RVA: 0x9BB640
char __fastcall Scaleform::Render::Texture::Unmap(Scaleform::Render::Texture *this, __int64 a2, __int64 a3)
{
  Scaleform::Render::TextureManagerLocks *pObject; // rax
  Scaleform::Render::TextureManager *pManager; // r9

  if ( !this->pMap )
    return 0;
  pObject = this->pManagerLocks.pObject;
  if ( pObject )
    pManager = pObject->pManager;
  else
    pManager = 0i64;
  LOBYTE(a3) = 1;
  ((void (__fastcall *)(Scaleform::Render::TextureManager *, Scaleform::Render::Texture *, __int64))pManager->Scaleform::RefCountBase<Scaleform::Render::TextureManager,72>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,72>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr[22].__vecDelDtor)(
    pManager,
    this,
    a3);
  return 1;
}

// File Line: 1856
// RVA: 0x9BC210
__int64 __fastcall Scaleform::Render::Texture::Update(Scaleform::Render::Texture *this)
{
  Scaleform::Render::Texture *v1; // r13
  unsigned int v2; // esi
  Scaleform::Render::TextureManagerLocks *pObject; // rcx
  char TextureFlags; // r12
  unsigned __int8 v5; // r15
  bool v6; // r12
  Scaleform::Render::ImageData *v7; // r14
  __int64 v8; // rdi
  __int64 v9; // rbx
  _RTL_CRITICAL_SECTION *p_cs; // rsi
  Scaleform::Render::ImageBase *pImage; // rcx
  __int64 v12; // rax
  Scaleform::Render::ImageData *p_Data; // rax
  Scaleform::Render::RawImage *v14; // rax
  void (__fastcall *v15)(void *, const void *, size_t, Scaleform::Render::Palette *); // rax
  unsigned __int8 v16; // r14
  Scaleform::Render::Size<unsigned long> *v17; // rax
  Scaleform::Render::RawImage *v18; // rax
  Scaleform::Render::ResizeImageType ImageFormatRescaleType; // eax
  Scaleform::Render::ImageData *v20; // r15
  unsigned __int64 v21; // r8
  __int64 v22; // r9
  Scaleform::Render::Size<unsigned long> *v23; // rax
  Scaleform::Render::RawImage *v24; // r14
  void (__fastcall *v25)(char *, const char *, unsigned __int64, Scaleform::Render::Palette *, void *); // rax
  unsigned int v26; // r14d
  unsigned int i; // eax
  unsigned int RawPlaneCount; // ecx
  __int64 v29; // rax
  unsigned int Width; // ecx
  unsigned int Height; // edx
  __int64 Pitch; // r8
  __int64 DataSize; // r9
  char *pData; // r10
  unsigned int v35; // ecx
  __int64 v36; // rax
  unsigned int v37; // ebx
  unsigned int v38; // esi
  unsigned __int64 v39; // r12
  char *v40; // rcx
  unsigned int v41; // edx
  Scaleform::Render::MappedTextureBase *pMap; // r8
  int v43; // eax
  unsigned int v44; // eax
  unsigned int v45; // ecx
  __int64 v46; // r14
  unsigned int v47; // edi
  int v48; // eax
  __int64 v49; // r15
  char *v50; // r14
  char *v51; // rdi
  unsigned int FormatBitsPerPixel; // eax
  unsigned __int64 v53; // r15
  char *v54; // r12
  unsigned __int64 v55; // r13
  __int64 v56; // rsi
  __int64 v57; // rdi
  __int64 v58; // rbx
  int fmt; // [rsp+40h] [rbp-C0h]
  Scaleform::Render::ImageData *src; // [rsp+48h] [rbp-B8h]
  Scaleform::Render::TextureManager *pManager; // [rsp+50h] [rbp-B0h]
  Scaleform::Render::ImageFormat format; // [rsp+58h] [rbp-A8h] BYREF
  unsigned int v64; // [rsp+5Ch] [rbp-A4h]
  Scaleform::Render::ResizeImageType resizeType; // [rsp+60h] [rbp-A0h] BYREF
  Scaleform::Render::ImagePlane splane; // [rsp+68h] [rbp-98h] BYREF
  unsigned int v67; // [rsp+88h] [rbp-78h]
  unsigned __int64 v68; // [rsp+90h] [rbp-70h]
  __int64 v69; // [rsp+98h] [rbp-68h]
  Scaleform::Render::ImagePlane dplane; // [rsp+A0h] [rbp-60h] BYREF
  Scaleform::Render::RawImage *v71; // [rsp+C0h] [rbp-40h]
  Scaleform::Render::ImagePlane p; // [rsp+C8h] [rbp-38h] BYREF
  int v73; // [rsp+E8h] [rbp-18h]
  __int64 v74; // [rsp+F0h] [rbp-10h]
  char *v75; // [rsp+F8h] [rbp-8h]
  __int64 v76; // [rsp+100h] [rbp+0h]
  Scaleform::Render::RawImage *v77; // [rsp+108h] [rbp+8h]
  Scaleform::Render::ImageData v78; // [rsp+110h] [rbp+10h] BYREF
  Scaleform::Render::ImageData v79; // [rsp+150h] [rbp+50h] BYREF
  unsigned __int64 v80; // [rsp+190h] [rbp+90h] BYREF
  __int64 v81; // [rsp+198h] [rbp+98h]
  __int64 v82; // [rsp+1A0h] [rbp+A0h]
  char *v83; // [rsp+1A8h] [rbp+A8h]
  __int64 v84; // [rsp+1B0h] [rbp+B0h]
  unsigned __int64 v85; // [rsp+1B8h] [rbp+B8h]
  unsigned int v86; // [rsp+1C0h] [rbp+C0h]
  Scaleform::Render::Palette *v87; // [rsp+1C8h] [rbp+C8h]
  _RTL_CRITICAL_SECTION *v88; // [rsp+1D0h] [rbp+D0h]
  void (__fastcall *v89)(char *, const char *, unsigned __int64, Scaleform::Render::Palette *, void *); // [rsp+1D8h] [rbp+D8h]
  Scaleform::Render::ImagePlane v90; // [rsp+1E0h] [rbp+E0h] BYREF
  char v91[8]; // [rsp+200h] [rbp+100h] BYREF
  char v92[8]; // [rsp+208h] [rbp+108h] BYREF
  __int64 v93; // [rsp+210h] [rbp+110h]
  char v95; // [rsp+278h] [rbp+178h] BYREF
  unsigned int v96; // [rsp+280h] [rbp+180h]
  unsigned int mipLevelCount; // [rsp+288h] [rbp+188h]

  v93 = -2i64;
  v1 = this;
  v2 = ((__int64 (__fastcall *)(Scaleform::Render::Texture *))this->vfptr[5].__vecDelDtor)(this);
  fmt = v2;
  pObject = v1->pManagerLocks.pObject;
  if ( pObject )
    pManager = pObject->pManager;
  else
    pManager = 0i64;
  TextureFlags = v1->TextureFlags;
  v5 = TextureFlags & 1;
  v6 = (TextureFlags & 2) != 0;
  v95 = 0;
  v7 = 0i64;
  *(_QWORD *)&v78.Format = 0i64;
  *(_DWORD *)&v78.Flags = 0x10000;
  v78.pPlanes = &v78.Plane0;
  memset(&v78.pPalette, 0, 40);
  *(_QWORD *)&v79.Format = 0i64;
  *(_DWORD *)&v79.Flags = 0x10000;
  v79.pPlanes = &v79.Plane0;
  memset(&v79.pPalette, 0, 40);
  v8 = 0i64;
  v77 = 0i64;
  v9 = 0i64;
  v71 = 0i64;
  if ( (v1->Use & 2) != 0 )
    mipLevelCount = 1;
  else
    mipLevelCount = (unsigned __int8)v1->MipLevels;
  format = (Scaleform::Render::ImageFormat)v1->vfptr[5].__vecDelDtor(v1, 0);
  resizeType = ResizeNone;
  ((void (__fastcall *)(Scaleform::Render::Texture *, _QWORD, bool, _QWORD, Scaleform::Render::ResizeImageType *, Scaleform::Render::ImageFormat *, char *))v1->vfptr[20].__vecDelDtor)(
    v1,
    v5,
    v6,
    v2,
    &resizeType,
    &format,
    &v95);
  p_cs = &v1->pManagerLocks.pObject->ImageLock.cs;
  v88 = p_cs;
  EnterCriticalSection(p_cs);
  pImage = v1->pImage;
  if ( !pImage || (v1->TextureFlags & 4) != 0 )
    goto LABEL_99;
  if ( ((unsigned int (__fastcall *)(Scaleform::Render::ImageBase *))pImage->vfptr[3].__vecDelDtor)(pImage) != 2 )
  {
    if ( v5 )
      goto LABEL_17;
    goto LABEL_13;
  }
  if ( !v5 )
  {
LABEL_13:
    if ( !v95
      && pManager->Scaleform::RefCountBase<Scaleform::Render::TextureManager,72>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,72>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr[19].__vecDelDtor(
           pManager,
           (unsigned int)v1->pFormat)
      && pManager->Scaleform::RefCountBase<Scaleform::Render::TextureManager,72>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,72>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr[20].__vecDelDtor(
           pManager,
           (unsigned int)v1) )
    {
      p_Data = &v1->pMap->Data;
LABEL_19:
      src = p_Data;
      if ( v95 )
        v15 = Scaleform::Render::ImageBase::CopyScanlineDefault;
      else
        v15 = (void (__fastcall *)(void *, const void *, size_t, Scaleform::Render::Palette *))v1->pFormat->vfptr->GetScanlineCopyFn(v1->pFormat);
      if ( !((unsigned __int8 (__fastcall *)(Scaleform::Render::ImageBase *, Scaleform::Render::ImageData *, _QWORD, _QWORD))v1->pImage->vfptr[8].__vecDelDtor)(
              v1->pImage,
              src,
              v15,
              0i64) )
      {
        if ( src == &v1->pMap->Data )
        {
          ((void (__fastcall *)(Scaleform::Render::TextureManager *, Scaleform::Render::Texture *, _QWORD))pManager->Scaleform::RefCountBase<Scaleform::Render::TextureManager,72>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,72>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr[22].__vecDelDtor)(
            pManager,
            v1,
            0i64);
          v16 = 1;
          goto LABEL_100;
        }
        goto LABEL_98;
      }
      goto LABEL_25;
    }
LABEL_17:
    v14 = Scaleform::Render::RawImage::Create(format, mipLevelCount, &v1->ImgSize, 0, 0i64, 0i64);
    v8 = (__int64)v14;
    v77 = v14;
    if ( !v14 )
      goto LABEL_99;
    Scaleform::Render::ImageData::operator=(&v78, &v14->Data);
    v78.Format = fmt | 0x100000;
    p_Data = &v78;
    goto LABEL_19;
  }
  v12 = ((__int64 (__fastcall *)(Scaleform::Render::ImageBase *))v1->pImage->vfptr[9].__vecDelDtor)(v1->pImage);
  Scaleform::Render::ImageData::operator=(&v78, (Scaleform::Render::ImageData *)(v12 + 40));
  src = &v78;
LABEL_25:
  if ( v5 )
  {
    if ( !v95
      && pManager->Scaleform::RefCountBase<Scaleform::Render::TextureManager,72>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,72>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr[19].__vecDelDtor(
           pManager,
           (unsigned int)v1->pFormat)
      && pManager->Scaleform::RefCountBase<Scaleform::Render::TextureManager,72>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,72>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr[20].__vecDelDtor(
           pManager,
           (unsigned int)v1) )
    {
      v7 = &v1->pMap->Data;
    }
    else
    {
      v17 = (Scaleform::Render::Size<unsigned long> *)((__int64 (__fastcall *)(Scaleform::Render::Texture *, char *, _QWORD))v1->vfptr[6].__vecDelDtor)(
                                                        v1,
                                                        v92,
                                                        0i64);
      v18 = Scaleform::Render::RawImage::Create(format, mipLevelCount, v17, 0, 0i64, 0i64);
      v9 = (__int64)v18;
      v71 = v18;
      if ( !v18 )
        goto LABEL_99;
      Scaleform::Render::ImageData::operator=(&v79, &v18->Data);
      v7 = &v79;
    }
    ImageFormatRescaleType = resizeType;
    if ( resizeType == ResizeNone )
    {
      ImageFormatRescaleType = (unsigned int)Scaleform::Render::GetImageFormatRescaleType(fmt);
      resizeType = ImageFormatRescaleType;
    }
    Scaleform::Render::RescaleImageData(v7, src, ImageFormatRescaleType);
    v20 = v7;
    src = v7;
  }
  else
  {
    v20 = src;
  }
  v73 = fmt & 0xFFF;
  if ( (fmt & 0xFFF) != 0 )
  {
    if ( (fmt & 0xFFF) == 200 )
    {
      v96 = 3;
    }
    else if ( (fmt & 0xFFF) == 201 )
    {
      v96 = 4;
    }
    else
    {
      v96 = 1;
    }
  }
  else
  {
    v96 = 0;
  }
  if ( !v95
    && pManager->Scaleform::RefCountBase<Scaleform::Render::TextureManager,72>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,72>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr[19].__vecDelDtor(
         pManager,
         (unsigned int)v1->pFormat) )
  {
    goto LABEL_60;
  }
  if ( !pManager->Scaleform::RefCountBase<Scaleform::Render::TextureManager,72>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,72>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr[19].__vecDelDtor(
          pManager,
          (unsigned int)v1->pFormat) )
  {
    v26 = 0;
    for ( i = v96; v26 < v96; i = v96 )
    {
      memset(&p, 0, sizeof(p));
      v80 = 0i64;
      v81 = 0i64;
      v82 = 0i64;
      v83 = 0i64;
      v84 = 0i64;
      v85 = 0i64;
      RawPlaneCount = v20->RawPlaneCount;
      if ( v26 >= RawPlaneCount )
      {
        Scaleform::Render::ImagePlane::GetMipLevel(
          &v20->pPlanes[v26 % RawPlaneCount],
          v20->Format,
          v26 / RawPlaneCount,
          &p,
          v26 % RawPlaneCount);
        pData = p.pData;
        DataSize = p.DataSize;
        Pitch = p.Pitch;
        Height = p.Height;
        Width = p.Width;
      }
      else
      {
        v29 = (__int64)&v20->pPlanes[v26];
        Width = *(_DWORD *)v29;
        p.Width = *(_DWORD *)v29;
        Height = *(_DWORD *)(v29 + 4);
        p.Height = Height;
        Pitch = *(_QWORD *)(v29 + 8);
        p.Pitch = Pitch;
        DataSize = *(_QWORD *)(v29 + 16);
        p.DataSize = DataSize;
        pData = *(char **)(v29 + 24);
        p.pData = pData;
      }
      v80 = __PAIR64__(Height, Width);
      v81 = Pitch;
      v82 = DataSize;
      v83 = pData;
      v84 = 0i64;
      v85 = __PAIR64__(Height, Width);
      v86 = v26;
      ((void (__fastcall *)(Scaleform::Render::Texture *, unsigned __int64 *, __int64))v1->vfptr[18].__vecDelDtor)(
        v1,
        &v80,
        1i64);
      ++v26;
    }
    goto LABEL_61;
  }
  if ( pManager->Scaleform::RefCountBase<Scaleform::Render::TextureManager,72>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,72>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr[20].__vecDelDtor(
         pManager,
         (unsigned int)v1) )
  {
    v7 = &v1->pMap->Data;
LABEL_53:
    v25 = v1->pFormat->vfptr->GetScanlineCopyFn(v1->pFormat);
    Scaleform::Render::ConvertImageData(v7, v20, v25, 0i64);
LABEL_60:
    i = v96;
LABEL_61:
    if ( v6 )
    {
      v22 = 0i64;
      mipLevelCount = 0;
      if ( i )
      {
        do
        {
          memset(&splane, 0, sizeof(splane));
          memset(&dplane, 0, sizeof(dplane));
          v35 = v20->RawPlaneCount;
          if ( (unsigned int)v22 >= v35 )
          {
            Scaleform::Render::ImagePlane::GetMipLevel(
              &v20->pPlanes[(unsigned int)v22 % v35],
              v20->Format,
              (unsigned int)v22 / v35,
              &splane,
              (unsigned int)v22 % v35);
            v40 = splane.pData;
            v74 = splane.DataSize;
            v39 = splane.Pitch;
            v38 = splane.Height;
            v37 = splane.Width;
            LODWORD(v22) = mipLevelCount;
          }
          else
          {
            v36 = (__int64)&v20->pPlanes[(unsigned int)v22];
            v37 = *(_DWORD *)v36;
            splane.Width = *(_DWORD *)v36;
            v38 = *(_DWORD *)(v36 + 4);
            splane.Height = v38;
            v39 = *(_QWORD *)(v36 + 8);
            splane.Pitch = v39;
            v21 = *(_QWORD *)(v36 + 16);
            v74 = v21;
            splane.DataSize = v21;
            v40 = *(char **)(v36 + 24);
            splane.pData = v40;
          }
          v68 = v39;
          v75 = v40;
          v41 = 1;
          v67 = 1;
          if ( v1->MipLevels > 1u )
          {
            do
            {
              pMap = v1->pMap;
              if ( (pMap->Data.Format & 0xFFF) != 0 )
              {
                if ( (pMap->Data.Format & 0xFFF) == 200 )
                {
                  v43 = 3;
                }
                else if ( (pMap->Data.Format & 0xFFF) == 201 )
                {
                  v43 = 4;
                }
                else
                {
                  v43 = 1;
                }
              }
              else
              {
                v43 = 0;
              }
              v44 = v22 + v41 * v43;
              v45 = pMap->Data.RawPlaneCount;
              if ( v44 >= v45 )
              {
                Scaleform::Render::ImagePlane::GetMipLevel(
                  &pMap->Data.pPlanes[v44 % v45],
                  pMap->Data.Format,
                  v44 / v45,
                  &dplane,
                  v44 % v45);
                v50 = dplane.pData;
                v69 = dplane.DataSize;
                v49 = dplane.Pitch;
                v48 = dplane.Height;
                v47 = dplane.Width;
                LODWORD(v22) = mipLevelCount;
              }
              else
              {
                v46 = (__int64)&pMap->Data.pPlanes[v44];
                v47 = *(_DWORD *)v46;
                dplane.Width = *(_DWORD *)v46;
                v48 = *(_DWORD *)(v46 + 4);
                dplane.Height = v48;
                v49 = *(_QWORD *)(v46 + 8);
                dplane.Pitch = v49;
                v69 = *(_QWORD *)(v46 + 16);
                dplane.DataSize = v69;
                v50 = *(char **)(v46 + 24);
                dplane.pData = v50;
              }
              v64 = v48;
              v76 = v49;
              if ( v95 )
              {
                v90.Pitch = v39;
                v90.DataSize = v74;
                v51 = v75;
                v90.pData = v75;
                v37 >>= 1;
                if ( !v37 )
                  v37 = 1;
                LODWORD(v69) = v37;
                v90.Width = v37;
                v38 >>= 1;
                if ( !v38 )
                  v38 = 1;
                v64 = v38;
                v90.Height = v38;
                Scaleform::Render::GenerateMipLevel(&v90, &splane, (Scaleform::Render::ImageFormat)fmt, v22);
                v87 = src->pPalette.pObject;
                v89 = v1->pFormat->vfptr->GetScanlineCopyFn(v1->pFormat);
                FormatBitsPerPixel = Scaleform::Render::ImageData::GetFormatBitsPerPixel(
                                       (Scaleform::Render::ImageFormat)fmt,
                                       mipLevelCount);
                if ( (unsigned int)(v73 - 50) > 3 )
                  v53 = v38;
                else
                  v53 = (unsigned __int64)(v38 + 3) >> 2;
                v54 = v51;
                if ( v53 )
                {
                  v55 = (FormatBitsPerPixel * (unsigned __int64)v37) >> 3;
                  v56 = v76;
                  v57 = v68;
                  v58 = (__int64)v87;
                  do
                  {
                    v89(v50, v54, v55, (Scaleform::Render::Palette *)v58, 0i64);
                    v54 += v57;
                    v50 += v56;
                    --v53;
                  }
                  while ( v53 );
                  v38 = v64;
                  v1 = this;
                  v37 = v69;
                }
                v39 = v68;
              }
              else
              {
                Scaleform::Render::GenerateMipLevel(&dplane, &splane, (Scaleform::Render::ImageFormat)fmt, v22);
                v37 = v47;
                v38 = v64;
                v39 = v49;
                v68 = v49;
                splane.Pitch = v49;
                v74 = v69;
                splane.DataSize = v69;
                v75 = v50;
                splane.pData = v50;
              }
              splane.Height = v38;
              splane.Width = v37;
              v41 = v67 + 1;
              v67 = v41;
              LODWORD(v22) = mipLevelCount;
            }
            while ( v41 < (unsigned __int8)v1->MipLevels );
            v20 = src;
          }
          v22 = (unsigned int)(v22 + 1);
          mipLevelCount = v22;
        }
        while ( (unsigned int)v22 < v96 );
        v9 = (__int64)v71;
        v8 = (__int64)v77;
        p_cs = v88;
      }
    }
    if ( v20 == &v1->pMap->Data )
    {
      LOBYTE(v21) = 1;
      ((void (__fastcall *)(Scaleform::Render::TextureManager *, Scaleform::Render::Texture *, unsigned __int64, __int64))pManager->Scaleform::RefCountBase<Scaleform::Render::TextureManager,72>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,72>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr[22].__vecDelDtor)(
        pManager,
        v1,
        v21,
        v22);
    }
    else
    {
      ((void (__fastcall *)(Scaleform::Render::Texture *, Scaleform::Render::ImageData *, unsigned __int64, __int64))v1->vfptr[21].__vecDelDtor)(
        v1,
        v20,
        v21,
        v22);
    }
LABEL_98:
    v16 = 1;
    goto LABEL_100;
  }
  if ( v7 )
    goto LABEL_53;
  v23 = (Scaleform::Render::Size<unsigned long> *)((__int64 (__fastcall *)(Scaleform::Render::Texture *, char *, _QWORD))v1->vfptr[6].__vecDelDtor)(
                                                    v1,
                                                    v91,
                                                    0i64);
  v24 = Scaleform::Render::RawImage::Create(format, mipLevelCount, v23, 0, 0i64, 0i64);
  if ( v9 )
    (*(void (__fastcall **)(__int64))(*(_QWORD *)v9 + 16i64))(v9);
  v9 = (__int64)v24;
  v71 = v24;
  if ( v24 )
  {
    Scaleform::Render::ImageData::operator=(&v79, &v24->Data);
    v7 = &v79;
    goto LABEL_53;
  }
LABEL_99:
  v16 = 0;
LABEL_100:
  LeaveCriticalSection(p_cs);
  if ( v9 )
    (*(void (__fastcall **)(__int64))(*(_QWORD *)v9 + 16i64))(v9);
  if ( v8 )
    (*(void (__fastcall **)(__int64))(*(_QWORD *)v8 + 16i64))(v8);
  if ( (v79.Flags & 2) != 0 )
  {
    v79.Flags &= ~2u;
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v79.pPlanes);
  }
  v79.pPlanes = &v79.Plane0;
  if ( v79.pPalette.pObject && !_InterlockedDecrement(&v79.pPalette.pObject->RefCount.Value) )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  if ( (v78.Flags & 2) != 0 )
  {
    v78.Flags &= ~2u;
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v78.pPlanes);
  }
  v78.pPlanes = &v78.Plane0;
  if ( v78.pPalette.pObject && !_InterlockedDecrement(&v78.pPalette.pObject->RefCount.Value) )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  return v16;
}>RefCount.Value) )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  if ( (v78.Flags & 2) != 0 )
  {
    v78.Flags &= ~2u;
    Scale

// File Line: 2038
// RVA: 0x980980
unsigned __int64 __fastcall Scaleform::Render::Texture::GetBytes(Scaleform::Render::Texture *this, int *memRegion)
{
  unsigned int Width; // ebx
  __int64 Height; // rdi
  Scaleform::Render::ImageFormat v4; // r9d
  int v5; // ecx
  unsigned int v6; // eax
  unsigned int v7; // ecx
  unsigned int v9; // eax
  unsigned int v10; // ecx

  if ( memRegion )
    *memRegion = 1;
  Width = this->ImgSize.Width;
  Height = this->ImgSize.Height;
  v4 = ((unsigned int (*)(void))this->vfptr[4].__vecDelDtor)();
  v5 = v4 & 0xFFF;
  if ( v5 == 50 )
  {
    v6 = (Width + 3) >> 2;
    v7 = (unsigned int)(Height + 3) >> 2;
    if ( !v7 )
      v7 = 1;
    if ( !v6 )
      v6 = 1;
    return 8 * v7 * v6;
  }
  else if ( (unsigned int)(v5 - 51) <= 2 || (unsigned int)(v5 - 64) <= 1 )
  {
    v9 = (Width + 3) >> 2;
    v10 = (unsigned int)(Height + 3) >> 2;
    if ( !v10 )
      v10 = 1;
    if ( !v9 )
      v9 = 1;
    return 16 * v10 * v9;
  }
  else
  {
    return Height * Scaleform::Render::ImageData::GetFormatPitch(v4, Width, 0);
  }
}

