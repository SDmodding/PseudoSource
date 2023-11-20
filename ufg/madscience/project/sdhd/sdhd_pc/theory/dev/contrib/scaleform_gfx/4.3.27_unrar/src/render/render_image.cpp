// File Line: 43
// RVA: 0x992100
signed __int64 __fastcall Scaleform::Render::ImageSize_MipLevelCount(Scaleform::Render::Size<unsigned long> sz)
{
  _DWORD *v1; // r8
  signed __int64 result; // rax
  unsigned int v3; // edx
  unsigned int v4; // ecx
  unsigned int v5; // edx

  v1 = (_DWORD *)sz;
  result = 1i64;
  if ( **(_DWORD **)&sz > 1u )
  {
    do
    {
      v3 = v1[1];
      if ( v3 <= 1 )
        break;
      v4 = *v1 >> 1;
      if ( v4 < 1 )
        v4 = 1;
      v5 = v3 >> 1;
      *v1 = v4;
      if ( v5 < 1 )
        v5 = 1;
      result = (unsigned int)(result + 1);
      v1[1] = v5;
    }
    while ( v4 > 1 );
  }
  return result;
}

// File Line: 59
// RVA: 0x989700
void __fastcall Scaleform::Render::ImagePlane::GetMipLevel(Scaleform::Render::ImagePlane *this, Scaleform::Render::ImageFormat format, unsigned int level, Scaleform::Render::ImagePlane *p, unsigned int plane)
{
  unsigned int v5; // ebx
  Scaleform::Render::ImagePlane *v6; // r12
  Scaleform::Render::ImagePlane *v7; // r14
  unsigned int v8; // edi
  Scaleform::Render::ImageFormat v9; // er15
  char *v10; // rax
  unsigned __int64 v11; // rcx
  __int32 v12; // ebp
  char *v13; // r12
  unsigned int v14; // ecx
  unsigned int v15; // eax
  unsigned int v16; // ecx
  unsigned __int64 v17; // rsi
  unsigned int v18; // ecx
  unsigned int v19; // eax
  unsigned __int64 v20; // rax
  bool v21; // zf
  __int64 v22; // [rsp+20h] [rbp-48h]
  Scaleform::Render::ImagePlane *v23; // [rsp+70h] [rbp+8h]
  unsigned int v24; // [rsp+80h] [rbp+18h]
  Scaleform::Render::ImagePlane *v25; // [rsp+88h] [rbp+20h]

  v25 = p;
  v23 = this;
  v5 = this->Width;
  v6 = this;
  v7 = p;
  p->Width = this->Width;
  v8 = this->Height;
  v24 = level;
  p->Height = v8;
  v9 = format;
  p->Pitch = this->Pitch;
  p->DataSize = this->DataSize;
  v10 = this->pData;
  v11 = 0i64;
  v22 = 0i64;
  p->pData = v10;
  if ( level )
  {
    v12 = format & 0xFFF;
    v13 = v10;
    while ( v12 != 50 )
    {
      if ( (unsigned int)(v12 - 51) <= 2 || (unsigned int)(v12 - 64) <= 1 )
      {
        v18 = (v8 + 3) >> 2;
        v19 = (v5 + 3) >> 2;
        if ( v18 < 1 )
          v18 = 1;
        if ( v19 < 1 )
          v19 = 1;
        v16 = 16 * v19 * v18;
        goto LABEL_17;
      }
      v17 = v8 * Scaleform::Render::ImageData::GetFormatPitch(v9, v5, plane);
LABEL_18:
      v5 >>= 1;
      v13 += v17;
      if ( v5 < 1 )
        v5 = 1;
      v8 >>= 1;
      if ( v8 < 1 )
        v8 = 1;
      v20 = Scaleform::Render::ImageData::GetFormatPitch(v9, v5, plane);
      v11 = v17 + v22;
      v21 = v24-- == 1;
      v22 += v17;
      if ( v21 )
      {
        v7 = v25;
        v25->pData = v13;
        v6 = v23;
        v25->Width = v5;
        v25->Height = v8;
        v25->Pitch = v20;
        goto LABEL_24;
      }
    }
    v14 = (v8 + 3) >> 2;
    v15 = (v5 + 3) >> 2;
    if ( v14 < 1 )
      v14 = 1;
    if ( v15 < 1 )
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
Scaleform::Render::Palette *__fastcall Scaleform::Render::Palette::Create(unsigned int colorCount, bool hasAlpha, Scaleform::MemoryHeap *pheap)
{
  Scaleform::MemoryHeap *v3; // r10
  unsigned int v4; // edi
  bool v5; // si
  Scaleform::Render::Palette *result; // rax
  Scaleform::Render::Palette *v7; // rbx

  v3 = pheap;
  v4 = colorCount;
  if ( !pheap )
    v3 = Scaleform::Memory::pGlobalHeap;
  v5 = hasAlpha;
  result = (Scaleform::Render::Palette *)v3->vfptr->Alloc(v3, 4i64 * (colorCount - 1) + 12, 0i64);
  v7 = result;
  if ( result )
  {
    result->RefCount.Value = 1;
    result->ColorCount = v4;
    result->HasAlphaFlag = v5;
    memset(result->Colors, 0, 4i64 * v4);
    result = v7;
  }
  return result;
}

// File Line: 103
// RVA: 0x9CD490
char __fastcall Scaleform::Render::ImageData::allocPlanes(Scaleform::Render::ImageData *this, Scaleform::Render::ImageFormat format, unsigned int mipLevelCount, bool separateMipmaps)
{
  Scaleform::Render::ImageData *v4; // rbx
  bool v5; // bp
  char v6; // r14
  Scaleform::Render::ImageFormat v7; // er15
  signed int v8; // eax
  unsigned int v9; // edi
  unsigned int v10; // edi
  Scaleform::MemoryHeap *v11; // rcx
  Scaleform::Render::ImagePlane *v12; // rax

  v4 = this;
  v5 = separateMipmaps;
  v6 = mipLevelCount;
  v7 = format;
  if ( format & 0xFFF )
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
    if ( v4->Flags & 4 )
      v11 = Scaleform::Memory::pGlobalHeap->vfptr->GetAllocHeap(Scaleform::Memory::pGlobalHeap, v4);
    v12 = (Scaleform::Render::ImagePlane *)v11->vfptr->Alloc(v11, 32i64 * v10, 0i64);
    v4->pPlanes = v12;
    if ( !v12 )
    {
      v4->RawPlaneCount = 1;
      v4->pPlanes = &v4->Plane0;
      return 0;
    }
    memset(v12, 0, 32i64 * v10);
    v4->Flags |= 2u;
  }
  v4->Format = v7;
  v4->RawPlaneCount = v10;
  v4->LevelCount = v6;
  if ( v5 )
    v4->Flags |= 1u;
  return 1;
}

// File Line: 136
// RVA: 0x9E3770
void __fastcall Scaleform::Render::ImageData::freePlanes(Scaleform::Render::ImageData *this)
{
  char v1; // al
  Scaleform::Render::ImageData *v2; // rbx
  Scaleform::Render::ImagePlane *v3; // rdx

  v1 = this->Flags;
  v2 = this;
  if ( v1 & 2 )
  {
    v3 = this->pPlanes;
    this->Flags = v1 & 0xFD;
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v3);
    v2->pPlanes = &v2->Plane0;
  }
  else
  {
    this->pPlanes = &this->Plane0;
  }
}

// File Line: 147
// RVA: 0x94E050
Scaleform::Render::ImageData *__fastcall Scaleform::Render::ImageData::operator=(Scaleform::Render::ImageData *this, Scaleform::Render::ImageData *rhs)
{
  char v2; // al
  Scaleform::Render::ImageData *v3; // rdi
  Scaleform::Render::ImageData *v4; // rbx
  Scaleform::Render::ImagePlane *v5; // rdx
  Scaleform::Render::ImagePlane *v6; // rsi
  volatile signed __int32 *v7; // rcx
  volatile signed __int32 *v8; // rdx
  unsigned __int16 v9; // si
  Scaleform::Render::ImagePlane *v10; // rax
  __int64 v11; // r11
  unsigned int v12; // edx
  unsigned int v13; // er8
  char *v14; // r10
  unsigned __int64 v15; // r9
  unsigned __int64 v16; // rcx
  Scaleform::Render::ImagePlane *v17; // rax

  v2 = this->Flags;
  v3 = rhs;
  v4 = this;
  if ( v2 & 2 )
  {
    v5 = this->pPlanes;
    this->Flags = v2 & 0xFD;
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v5);
  }
  v6 = &v4->Plane0;
  v4->pPlanes = &v4->Plane0;
  v4->Format = v3->Format;
  v4->Use = v3->Use;
  v4->Flags = v3->Flags;
  v4->LevelCount = v3->LevelCount;
  v4->RawPlaneCount = v3->RawPlaneCount;
  v7 = &v3->pPalette.pObject->RefCount.Value;
  if ( v7 )
    _InterlockedExchangeAdd(v7, 1u);
  v8 = &v4->pPalette.pObject->RefCount.Value;
  if ( v8 && !_InterlockedDecrement(v8) )
    ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
  v4->pPalette.pObject = v3->pPalette.pObject;
  v6->Width = v3->Plane0.Width;
  v4->Plane0.Height = v3->Plane0.Height;
  v4->Plane0.Pitch = v3->Plane0.Pitch;
  v4->Plane0.DataSize = v3->Plane0.DataSize;
  v4->Plane0.pData = v3->Plane0.pData;
  if ( !(v3->Flags & 2) )
  {
    v4->pPlanes = v6;
    return v4;
  }
  v4->Flags &= 0xFDu;
  Scaleform::Render::ImageData::allocPlanes(v4, v4->Format, (unsigned __int8)v4->LevelCount, v4->Flags & 1);
  v9 = 0;
  if ( v3->RawPlaneCount <= 0u )
    return v4;
  do
  {
    v10 = v3->pPlanes;
    v11 = v9++;
    v11 *= 32i64;
    v12 = *(unsigned int *)((char *)&v10->Width + v11);
    v13 = *(unsigned int *)((char *)&v10->Height + v11);
    v14 = *(char **)((char *)&v10->pData + v11);
    v15 = *(unsigned __int64 *)((char *)&v10->DataSize + v11);
    v16 = *(unsigned __int64 *)((char *)&v10->Pitch + v11);
    v17 = v4->pPlanes;
    *(unsigned int *)((char *)&v17->Width + v11) = v12;
    *(unsigned int *)((char *)&v17->Height + v11) = v13;
    *(unsigned __int64 *)((char *)&v17->Pitch + v11) = v16;
    *(unsigned __int64 *)((char *)&v17->DataSize + v11) = v15;
    *(char **)((char *)&v17->pData + v11) = v14;
  }
  while ( v9 < v3->RawPlaneCount );
  return v4;
}

// File Line: 178
// RVA: 0x95F780
void __fastcall Scaleform::Render::ImageData::Clear(Scaleform::Render::ImageData *this)
{
  char v1; // al
  Scaleform::Render::ImageData *v2; // rbx
  Scaleform::Render::ImagePlane *v3; // rdx
  volatile signed __int32 *v4; // rdx

  v1 = this->Flags;
  v2 = this;
  if ( v1 & 2 )
  {
    v3 = this->pPlanes;
    this->Flags = v1 & 0xFD;
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v3);
  }
  v2->Flags &= 0xFBu;
  *(_QWORD *)&v2->Format = 0i64;
  v2->LevelCount = 0;
  v2->pPlanes = &v2->Plane0;
  v2->RawPlaneCount = 1;
  v4 = &v2->pPalette.pObject->RefCount.Value;
  if ( v4 && !_InterlockedDecrement(v4) )
    ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
  v2->pPalette.pObject = 0i64;
  *(_QWORD *)&v2->Plane0.Width = 0i64;
  v2->Plane0.Pitch = 0i64;
  v2->Plane0.DataSize = 0i64;
  v2->Plane0.pData = 0i64;
}

// File Line: 195
// RVA: 0x9940D0
bool __fastcall Scaleform::Render::ImageData::Initialize(Scaleform::Render::ImageData *this, Scaleform::Render::ImageData *source, unsigned int levelIndex, unsigned int levelCount)
{
  unsigned int v4; // esi
  unsigned int v5; // ebp
  Scaleform::Render::ImageData *v6; // rdi
  Scaleform::Render::ImageData *v7; // r14
  Scaleform::Render::ImageFormat v8; // ebx
  bool result; // al
  unsigned int plane; // ebx
  Scaleform::Render::ImageFormat v11; // er10
  signed int v12; // edx
  signed int v13; // ebx
  bool separateMipmaps; // al

  v4 = levelCount;
  v5 = levelIndex;
  v6 = source;
  v7 = this;
  if ( !levelCount )
    v4 = (unsigned __int8)source->LevelCount - levelIndex;
  if ( !levelIndex || source->Flags & 1 )
  {
    v11 = source->Format;
    v12 = 1;
    if ( v11 & 0xFFF )
    {
      if ( (v11 & 0xFFF) == 200 )
      {
        v13 = 3;
      }
      else if ( (v11 & 0xFFF) == 201 )
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
    separateMipmaps = v6->Flags & 1;
    if ( separateMipmaps )
      v12 = v4;
    Scaleform::Render::ImageData::Initialize(this, v11, v4, &v6->pPlanes[levelIndex * v13], v13 * v12, separateMipmaps);
  }
  else
  {
    v8 = source->Format;
    Scaleform::Render::ImageData::Clear(this);
    result = Scaleform::Render::ImageData::allocPlanes(v7, v8, v4, 0);
    if ( !result )
      return result;
    plane = 0;
    if ( v6->RawPlaneCount > 0u )
    {
      do
      {
        Scaleform::Render::ImagePlane::GetMipLevel(&v6->pPlanes[plane], v6->Format, v5, &v7->pPlanes[plane], plane);
        ++plane;
      }
      while ( plane < v6->RawPlaneCount );
    }
  }
  return 1;
}

// File Line: 239
// RVA: 0x98AB10
void __fastcall Scaleform::Render::ImageData::GetPlane(Scaleform::Render::ImageData *this, unsigned int index, Scaleform::Render::ImagePlane *pplane)
{
  Scaleform::Render::ImageData *v3; // r10
  unsigned int v4; // ecx
  signed __int64 v5; // rdx

  v3 = this;
  v4 = this->RawPlaneCount;
  if ( index >= v4 )
  {
    Scaleform::Render::ImagePlane::GetMipLevel(&v3->pPlanes[index % v4], v3->Format, index / v4, pplane, index % v4);
  }
  else
  {
    v5 = (signed __int64)&v3->pPlanes[index];
    pplane->Width = *(_DWORD *)v5;
    pplane->Height = *(_DWORD *)(v5 + 4);
    pplane->Pitch = *(_QWORD *)(v5 + 8);
    pplane->DataSize = *(_QWORD *)(v5 + 16);
    pplane->pData = *(char **)(v5 + 24);
  }
}

// File Line: 269
// RVA: 0x9B2A70
void __fastcall Scaleform::Render::ImageData::SetPixelInScanline(Scaleform::Render::ImageData *this, char *pline, unsigned int x, unsigned int color)
{
  signed __int32 v4; // er10
  int v5; // er10
  int v6; // er10
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
        *(_WORD *)&pline[v8] = color;
        pline[v8 + 3] = HIBYTE(color);
        pline[v8 + 2] = BYTE2(color);
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
Scaleform::Render::Color *__fastcall Scaleform::Render::ImageData::GetPixelInScanline(Scaleform::Render::ImageData *this, Scaleform::Render::Color *result, const char *pline, unsigned int x)
{
  signed __int32 v4; // er10
  int v5; // er10
  int v6; // er10
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
        result->Channels.Red = pline[v9 + 2];
        result->Channels.Green = pline[v9 + 1];
        result->Channels.Blue = pline[v9];
        result->Channels.Alpha = pline[v9 + 3];
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
signed __int64 __fastcall Scaleform::Render::ImageData::GetFormatPlaneCount(Scaleform::Render::ImageFormat fmt)
{
  __int32 v1; // ecx
  int v2; // ecx

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
signed __int64 __fastcall Scaleform::Render::ImageData::GetFormatBitsPerPixel(Scaleform::Render::ImageFormat fmt, unsigned int plane)
{
  signed __int64 result; // rax

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
unsigned __int64 __fastcall Scaleform::Render::ImageData::GetFormatPitch(Scaleform::Render::ImageFormat fmt, unsigned int width, unsigned int plane)
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
      result = 3 * (width + 1) & 0xFFFFFFFC;
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
Scaleform::Render::Size<unsigned long> *__fastcall Scaleform::Render::ImageData::GetFormatPlaneSize(Scaleform::Render::Size<unsigned long> *result, Scaleform::Render::ImageFormat fmt, Scaleform::Render::Size<unsigned long> *sz, unsigned int plane)
{
  Scaleform::Render::Size<unsigned long> *v4; // rax

  if ( (fmt & 0xFFFu) - 200 > 1 || plane - 1 > 1 )
  {
    result->Width = sz->Width;
    result->Height = sz->Height;
    v4 = result;
  }
  else
  {
    result->Width = sz->Width >> 1;
    result->Height = sz->Height >> 1;
    v4 = result;
  }
  return v4;
}

// File Line: 702
// RVA: 0x989880
unsigned __int64 __fastcall Scaleform::Render::ImageData::GetMipLevelSize(Scaleform::Render::ImageFormat format, Scaleform::Render::Size<unsigned long> *sz, unsigned int plane)
{
  __int32 v3; // er9
  unsigned int v4; // eax
  unsigned int v5; // ecx
  unsigned __int64 result; // rax
  unsigned int v7; // eax
  unsigned int v8; // ecx

  v3 = format & 0xFFF;
  if ( v3 == 50 )
  {
    v4 = (sz->Height + 3) >> 2;
    v5 = (sz->Width + 3) >> 2;
    if ( v4 < 1 )
      v4 = 1;
    if ( v5 < 1 )
      v5 = 1;
    result = 8 * v5 * v4;
  }
  else if ( (unsigned int)(v3 - 51) <= 2 || (unsigned int)(v3 - 64) <= 1 )
  {
    v7 = (sz->Height + 3) >> 2;
    v8 = (sz->Width + 3) >> 2;
    if ( v7 < 1 )
      v7 = 1;
    if ( v8 < 1 )
      v8 = 1;
    result = 16 * v8 * v7;
  }
  else
  {
    result = sz->Height * Scaleform::Render::ImageData::GetFormatPitch(format, sz->Width, plane);
  }
  return result;
}

// File Line: 718
// RVA: 0x989920
__int64 __fastcall Scaleform::Render::ImageData::GetMipLevelsSize(Scaleform::Render::ImageFormat format, Scaleform::Render::Size<unsigned long> *sz, unsigned int levels, unsigned int plane)
{
  unsigned int v4; // edi
  unsigned int v5; // esi
  __int64 v6; // rbp
  unsigned int v7; // er12
  unsigned int v8; // er15
  Scaleform::Render::ImageFormat v9; // er14
  __int32 v10; // ebx
  unsigned int v11; // ecx
  unsigned int v12; // eax
  unsigned int v13; // ecx
  unsigned __int64 v14; // rdx
  unsigned int v15; // ecx
  unsigned int v16; // eax

  v4 = sz->Width;
  v5 = sz->Height;
  v6 = 0i64;
  v7 = plane;
  v8 = levels;
  v9 = format;
  if ( levels )
  {
    v10 = format & 0xFFF;
    while ( v10 != 50 )
    {
      if ( (unsigned int)(v10 - 51) <= 2 || (unsigned int)(v10 - 64) <= 1 )
      {
        v15 = (v5 + 3) >> 2;
        v16 = (v4 + 3) >> 2;
        if ( v15 < 1 )
          v15 = 1;
        if ( v16 < 1 )
          v16 = 1;
        v13 = 16 * v16 * v15;
        goto LABEL_17;
      }
      v14 = v5 * Scaleform::Render::ImageData::GetFormatPitch(v9, v4, v7);
LABEL_18:
      v4 >>= 1;
      v6 += v14;
      if ( v4 < 1 )
        v4 = 1;
      v5 >>= 1;
      if ( v5 < 1 )
        v5 = 1;
      if ( !--v8 )
        return v6;
    }
    v11 = (v5 + 3) >> 2;
    v12 = (v4 + 3) >> 2;
    if ( v11 < 1 )
      v11 = 1;
    if ( v12 < 1 )
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
void __fastcall Scaleform::Render::ImageSwizzler::CacheScanline(Scaleform::Render::ImageSwizzler *this, Scaleform::Render::ImageSwizzlerContext *ctx, unsigned int y)
{
  ctx->pCurrentScanline = &ctx->pImage->pPlanes->pData[y * ctx->pImage->pPlanes->Pitch];
}

// File Line: 738
// RVA: 0x9B2B90
void __fastcall Scaleform::Render::ImageSwizzler::SetPixelInScanline(Scaleform::Render::ImageSwizzler *this, Scaleform::Render::ImageSwizzlerContext *ctx, __int64 x, __int64 c)
{
  this->vfptr->SetPixelInScanline(this, ctx, x, *(unsigned int *)c);
}

// File Line: 743
// RVA: 0x9B2B80
void __fastcall Scaleform::Render::ImageSwizzler::SetPixelInScanline(Scaleform::Render::ImageSwizzler *this, Scaleform::Render::ImageSwizzlerContext *ctx, unsigned int x, unsigned int c)
{
  Scaleform::Render::ImageData::SetPixelInScanline(ctx->pImage, ctx->pCurrentScanline, x, c);
}

// File Line: 748
// RVA: 0x98A9F0
Scaleform::Render::Color *__fastcall Scaleform::Render::ImageSwizzler::GetPixelInScanline(Scaleform::Render::ImageSwizzler *this, Scaleform::Render::Color *result, Scaleform::Render::ImageSwizzlerContext *ctx, unsigned int x)
{
  Scaleform::Render::Color *v4; // rbx

  v4 = result;
  Scaleform::Render::ImageData::GetPixelInScanline(ctx->pImage, result, ctx->pCurrentScanline, x);
  return v4;
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
void __fastcall Scaleform::Render::ImageBase::CopyScanlineDefault(char *pd, const char *ps, unsigned __int64 size, Scaleform::Render::Palette *__formal)
{
  memmove(pd, ps, size);
}

// File Line: 798
// RVA: 0x94B010
void __fastcall Scaleform::Render::Image::~Image(Scaleform::Render::Image *this)
{
  Scaleform::Render::Image *v1; // rdi

  v1 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::Image::`vftable';
  _RBX = 0i64;
  __asm { xchg    rbx, [rcx+10h]; Exchange Register/Memory with Register }
  if ( _RBX )
  {
    (*(void (__fastcall **)(volatile signed __int32 *))(*(_QWORD *)_RBX + 64i64))(_RBX);
    if ( !_InterlockedDecrement(_RBX + 2) )
      (**(void (__fastcall ***)(volatile signed __int32 *, signed __int64))_RBX)(_RBX, 1i64);
  }
  if ( v1->pInverseMatrix )
    ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  v1->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable';
}

// File Line: 885
// RVA: 0x9696A0
void __fastcall Scaleform::Render::Image::CreateSubImage(Scaleform::Render::Image *this, Scaleform::Render::Rect<unsigned long> *rect, Scaleform::MemoryHeap *pheap)
{
  Scaleform::Render::Rect<unsigned long> *v3; // rbx
  Scaleform::Render::Image *v4; // rdi
  Scaleform::Render::SubImage *v5; // rax

  v3 = rect;
  v4 = this;
  v5 = (Scaleform::Render::SubImage *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))pheap->vfptr->Alloc)(
                                        pheap,
                                        64i64);
  if ( v5 )
    Scaleform::Render::SubImage::SubImage(v5, v4, v3);
}

// File Line: 892
// RVA: 0x9B1B60
void __fastcall Scaleform::Render::Image::SetMatrix(Scaleform::Render::Image *this, Scaleform::Render::Matrix2x4<float> *mat, Scaleform::MemoryHeap *heap)
{
  Scaleform::MemoryHeap *v3; // rax
  Scaleform::Render::Matrix2x4<float> *v4; // rdi
  Scaleform::Render::Image *v5; // rbx
  Scaleform::Render::Matrix2x4<float> *v6; // rcx

  v3 = heap;
  v4 = mat;
  v5 = this;
  if ( !this->pInverseMatrix )
  {
    if ( !heap )
      v3 = Scaleform::Memory::pGlobalHeap->vfptr->GetAllocHeap(Scaleform::Memory::pGlobalHeap, this);
    v5->pInverseMatrix = (Scaleform::Render::Matrix2x4<float> *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64, signed __int64))v3->vfptr->Alloc)(
                                                                  v3,
                                                                  32i64,
                                                                  16i64);
  }
  v6 = v5->pInverseMatrix;
  v6->M[0][0] = v4->M[0][0];
  v6->M[0][1] = v4->M[0][1];
  v6->M[0][2] = v4->M[0][2];
  v6->M[0][3] = v4->M[0][3];
  v6->M[1][0] = v4->M[1][0];
  v6->M[1][1] = v4->M[1][1];
  v6->M[1][2] = v4->M[1][2];
  v6->M[1][3] = v4->M[1][3];
  Scaleform::Render::Matrix2x4<float>::Invert(v5->pInverseMatrix);
}

// File Line: 903
// RVA: 0x9B1C80
void __fastcall Scaleform::Render::Image::SetMatrixInverse(Scaleform::Render::Image *this, Scaleform::Render::Matrix2x4<float> *mat, Scaleform::MemoryHeap *heap)
{
  Scaleform::MemoryHeap *v3; // rax
  Scaleform::Render::Matrix2x4<float> *v4; // rbx
  Scaleform::Render::Image *v5; // rdi
  Scaleform::Render::Matrix2x4<float> *v6; // rcx

  v3 = heap;
  v4 = mat;
  v5 = this;
  if ( !this->pInverseMatrix )
  {
    if ( !heap )
      v3 = Scaleform::Memory::pGlobalHeap->vfptr->GetAllocHeap(Scaleform::Memory::pGlobalHeap, this);
    v5->pInverseMatrix = (Scaleform::Render::Matrix2x4<float> *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64, signed __int64))v3->vfptr->Alloc)(
                                                                  v3,
                                                                  32i64,
                                                                  16i64);
  }
  v6 = v5->pInverseMatrix;
  v6->M[0][0] = v4->M[0][0];
  v6->M[0][1] = v4->M[0][1];
  v6->M[0][2] = v4->M[0][2];
  v6->M[0][3] = v4->M[0][3];
  v6->M[1][0] = v4->M[1][0];
  v6->M[1][1] = v4->M[1][1];
  v6->M[1][2] = v4->M[1][2];
  v6->M[1][3] = v4->M[1][3];
}

// File Line: 914
// RVA: 0x988DB0
void __fastcall Scaleform::Render::Image::GetMatrix(Scaleform::Render::Image *this, Scaleform::Render::Matrix2x4<float> *mat)
{
  Scaleform::Render::Matrix2x4<float> *v2; // r8

  v2 = this->pInverseMatrix;
  if ( v2 )
  {
    *(_OWORD *)&mat->M[0][0] = *(_OWORD *)&v2->M[0][0];
    *(_OWORD *)&mat->M[1][0] = *(_OWORD *)&v2->M[1][0];
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
_BOOL8 __fastcall Scaleform::Render::Image::GetMatrixInverse(Scaleform::Render::Image *this, Scaleform::Render::Matrix2x4<float> *mat)
{
  Scaleform::Render::Matrix2x4<float> *v2; // r8

  v2 = this->pInverseMatrix;
  if ( v2 )
  {
    *(_OWORD *)&mat->M[0][0] = *(_OWORD *)&v2->M[0][0];
    *(_OWORD *)&mat->M[1][0] = *(_OWORD *)&v2->M[1][0];
  }
  return this->pInverseMatrix != 0i64;
}

// File Line: 933
// RVA: 0x98E340
void __fastcall Scaleform::Render::Image::GetUVGenMatrix(Scaleform::Render::Image *this, Scaleform::Render::Matrix2x4<float> *mat, Scaleform::Render::TextureManager *manager)
{
  __m128 *v3; // rbx
  Scaleform::Render::Image *v4; // rdi
  void *v5; // rsi
  __m128 v6; // xmm6
  __m128 v7; // xmm7
  __m128 v8; // xmm5
  __m128 v9; // xmm0
  float v10; // xmm1_4
  int v11; // [rsp+20h] [rbp-78h]
  int v12; // [rsp+24h] [rbp-74h]
  __m128 v13; // [rsp+30h] [rbp-68h]
  __m128 v14; // [rsp+40h] [rbp-58h]
  __m128 v15; // [rsp+50h] [rbp-48h]
  __m128 v16; // [rsp+60h] [rbp-38h]

  v3 = (__m128 *)mat;
  v4 = this;
  v5 = this->vfptr[21].__vecDelDtor((Scaleform::RefCountImplCore *)this, (unsigned int)manager);
  if ( v5 )
  {
    if ( v4->vfptr[16].__vecDelDtor((Scaleform::RefCountImplCore *)&v4->vfptr, (unsigned int)&v15) )
    {
      (*(void (__fastcall **)(void *, __m128 *))(*(_QWORD *)v5 + 56i64))(v5, &v13);
      v6 = (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>'::`2'::v;
      v7 = (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<4294967295,4294967295,0,4294967295>'::`2'::v;
      v8 = v14;
      v9 = _mm_mul_ps(_mm_shuffle_ps(v14, v14, 0), v15);
      *v3 = _mm_and_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v13, v13, 85), v16), _mm_mul_ps(_mm_shuffle_ps(v13, v13, 0), v15)),
                _mm_and_ps(v13, (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>'::`2'::v)),
              (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<4294967295,4294967295,0,4294967295>'::`2'::v);
      v3[1] = _mm_and_ps(
                _mm_add_ps(_mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v8, v8, 85), v16), v9), _mm_and_ps(v8, v6)),
                v7);
    }
    else
    {
      (*(void (__fastcall **)(void *, __m128 *))(*(_QWORD *)v5 + 56i64))(v5, v3);
    }
    v4->vfptr[6].__vecDelDtor((Scaleform::RefCountImplCore *)&v4->vfptr, (unsigned int)&v11);
    v10 = (float)((float)v12 * *((float *)v3->m128_u64 + 1)) + (float)((float)v11 * *(float *)v3->m128_u64);
    v3[1].m128_f32[3] = (float)((float)((float)v12 * v3[1].m128_f32[1]) + (float)((float)v11 * v3[1].m128_f32[0]))
                      + v3[1].m128_f32[3];
    *((float *)&v3->m128_u64[1] + 1) = v10 + *((float *)&v3->m128_u64[1] + 1);
  }
  else
  {
    v3->m128_u64[0] = 1065353216i64;
    *(unsigned __int64 *)((char *)v3[1].m128_u64 + 4) = 1065353216i64;
    v3->m128_u64[1] = 0i64;
    v3[1].m128_i32[0] = 0;
    v3[1].m128_i32[3] = 0;
  }
}

// File Line: 959
// RVA: 0x98E4C0
void __fastcall Scaleform::Render::Image::GetUVNormMatrix(Scaleform::Render::Image *this, Scaleform::Render::Matrix2x4<float> *mat, Scaleform::Render::TextureManager *manager)
{
  Scaleform::Render::Matrix2x4<float> *v3; // rbx
  Scaleform::Render::Image *v4; // rdi
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
  int v25; // [rsp+20h] [rbp-68h]
  int v26; // [rsp+24h] [rbp-64h]
  int v27; // [rsp+28h] [rbp-60h]
  int v28; // [rsp+2Ch] [rbp-5Ch]
  float v29; // [rsp+30h] [rbp-58h]
  float v30; // [rsp+34h] [rbp-54h]
  float v31; // [rsp+3Ch] [rbp-4Ch]
  float v32; // [rsp+40h] [rbp-48h]
  float v33; // [rsp+44h] [rbp-44h]
  float v34; // [rsp+4Ch] [rbp-3Ch]

  v3 = mat;
  v4 = this;
  v5 = (_DWORD *)this->vfptr[21].__vecDelDtor((Scaleform::RefCountImplCore *)this, (unsigned int)manager);
  v6 = v5;
  if ( v5 )
  {
    (*(void (__fastcall **)(_DWORD *, Scaleform::Render::Matrix2x4<float> *))(*(_QWORD *)v5 + 56i64))(v5, v3);
    v4->vfptr[6].__vecDelDtor((Scaleform::RefCountImplCore *)&v4->vfptr, (unsigned int)&v25);
    if ( v27 - v25 != v6[12] || v28 - v26 != v6[13] )
    {
      if ( v4->vfptr[16].__vecDelDtor((Scaleform::RefCountImplCore *)&v4->vfptr, (unsigned int)&v29) )
      {
        v7 = v3->M[0][1];
        v8 = v32;
        v9 = v29;
        v3->M[1][2] = 0.0;
        v3->M[0][2] = 0.0;
        v10 = v3->M[0][0];
        v11 = v3->M[1][0];
        v12 = v3->M[1][1];
        v13 = v33;
        v3->M[0][0] = (float)(v8 * v7) + (float)(v9 * v3->M[0][0]);
        v14 = (float)(v8 * v12) + (float)(v9 * v11);
        v15 = v30;
        v16 = v30;
        v3->M[1][0] = v14;
        v17 = v34;
        v18 = (float)(v13 * v7) + (float)(v16 * v10);
        v19 = (float)(v13 * v12) + (float)(v15 * v11);
        v20 = v31 * v11;
        v21 = v31 * v10;
        v3->M[0][1] = v18;
        v3->M[1][1] = v19;
        v22 = (float)((float)(v17 * v7) + v21) + v3->M[0][3];
        v3->M[1][3] = (float)((float)(v17 * v12) + v20) + v3->M[1][3];
        v3->M[0][3] = v22;
      }
    }
    v23 = (float)((float)v26 * v3->M[0][1]) + (float)((float)v25 * v3->M[0][0]);
    v3->M[1][3] = (float)((float)((float)v25 * v3->M[1][0]) + (float)((float)v26 * v3->M[1][1])) + v3->M[1][3];
    v3->M[0][3] = v23 + v3->M[0][3];
  }
  else
  {
    *(_QWORD *)&v3->M[0][0] = 1065353216i64;
    *(_QWORD *)&v3->M[1][1] = 1065353216i64;
    *(_QWORD *)&v3->M[0][2] = 0i64;
    v3->M[1][0] = 0.0;
    v3->M[1][3] = 0.0;
  }
  v24 = (_DWORD *)v4->vfptr[6].__vecDelDtor((Scaleform::RefCountImplCore *)&v4->vfptr, (unsigned int)&v25);
  Scaleform::Render::Matrix2x4<float>::PrependScaling(v3, (float)(v24[2] - *v24), (float)(v24[3] - v24[1]));
}

// File Line: 1000
// RVA: 0x997630
bool __fastcall Scaleform::Render::ImageSource::IsDecodeOnlyImageCompatible(Scaleform::Render::ImageSource *this, Scaleform::Render::ImageCreateArgs *args)
{
  Scaleform::Render::TextureManager *v2; // rbx
  Scaleform::Render::ImageCreateArgs *v3; // rdi
  Scaleform::RefCountImplCoreVtbl *v4; // rbx
  unsigned int v5; // eax
  int v6; // eax
  bool result; // al

  v2 = args->pManager;
  v3 = args;
  if ( !v2
    || (v4 = v2->vfptr,
        v5 = ((__int64 (*)(void))this->vfptr[4].__vecDelDtor)(),
        v6 = (__int64)v4[3].__vecDelDtor((Scaleform::RefCountImplCore *)&v3->pManager->vfptr, v5),
        v3->Use & (unsigned __int8)~(_BYTE)v6 & 0xC0)
    || !_bittest(&v6, 8u)
    || v3->pManager->pTextureCache.pObject )
  {
    result = (v3->Use & 0xC0) == 0;
  }
  else
  {
    result = 0;
  }
  return result;
}

// File Line: 1024
// RVA: 0x9660E0
Scaleform::Render::RawImage *__fastcall Scaleform::Render::ImageSource::CreateCompatibleImage(Scaleform::Render::ImageSource *this, Scaleform::Render::ImageCreateArgs *args)
{
  Scaleform::Render::ImageCreateArgs *v2; // r14
  Scaleform::Render::ImageSource *v3; // rsi
  Scaleform::Render::ImageFormat v4; // er13
  Scaleform::Render::ImageUpdateSync *psync; // r12
  Scaleform::Render::RawImage *v6; // rdi
  Scaleform::Render::TextureManager *v7; // r12
  Scaleform::MemoryHeap *v8; // rbx
  unsigned int v9; // er15
  Scaleform::Render::TextureManager *v10; // rcx
  int v11; // eax
  Scaleform::RefCountImplCoreVtbl *v12; // rbx
  __int64 v13; // rax
  unsigned int ptexture; // ST20_4
  Scaleform::Render::Texture *v15; // rbx
  Scaleform::Render::TextureImage *v16; // r14
  Scaleform::Render::Size<unsigned long> *v17; // rax
  Scaleform::Render::RawImage *v18; // rax
  Scaleform::Render::Size<unsigned long> *v19; // rax
  Scaleform::Render::RawImage *result; // rax
  Scaleform::Render::RawImage *v21; // rbx
  char v22; // [rsp+48h] [rbp-31h]
  Scaleform::Render::ImageData v23; // [rsp+50h] [rbp-29h]
  unsigned int mipLevelCount; // [rsp+E0h] [rbp+67h]
  void *v25; // [rsp+E8h] [rbp+6Fh]
  Scaleform::MemoryHeap *v26; // [rsp+F0h] [rbp+77h]
  char v27; // [rsp+F8h] [rbp+7Fh]

  v2 = args;
  v3 = this;
  v4 = args->Format;
  if ( v4 == Image_None )
    v4 = ((unsigned int (*)(void))this->vfptr[4].__vecDelDtor)();
  psync = v2->pUpdateSync;
  v6 = 0i64;
  if ( !psync )
  {
    v7 = v2->pManager;
    if ( v7 )
      psync = (Scaleform::Render::ImageUpdateSync *)&v7->vfptr;
    else
      psync = 0i64;
  }
  v8 = Scaleform::Memory::pGlobalHeap;
  if ( v2->pHeap )
    v8 = v2->pHeap;
  v25 = v8;
  v26 = v8;
  v9 = v2->Use;
  mipLevelCount = ((__int64 (__fastcall *)(Scaleform::Render::ImageSource *))v3->vfptr[7].__vecDelDtor)(v3);
  if ( mipLevelCount > 1 )
    v9 &= 0xFFFFFFFD;
  v10 = v2->pManager;
  if ( v10
    && (v11 = (__int64)v10->vfptr[3].__vecDelDtor((Scaleform::RefCountImplCore *)&v10->vfptr, v4),
        !(v2->Use & (unsigned __int8)~(_BYTE)v11 & 0xC0))
    && _bittest(&v11, 8u)
    && (v9 |= 0x100u, ((unsigned __int8 (*)(void))v2->pManager->vfptr[7].__vecDelDtor)()) )
  {
    v12 = v2->pManager->vfptr;
    v13 = (__int64)v3->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)&v3->vfptr, (unsigned int)&v27);
    ptexture = v9;
    v15 = (Scaleform::Render::Texture *)((__int64 (__fastcall *)(Scaleform::Render::TextureManager *, _QWORD, _QWORD, __int64, unsigned int, Scaleform::Render::ImageSource *, _QWORD))v12[1].__vecDelDtor)(
                                          v2->pManager,
                                          (unsigned int)v4,
                                          mipLevelCount,
                                          v13,
                                          ptexture,
                                          v3,
                                          0i64);
    if ( v15 )
    {
      v16 = (Scaleform::Render::TextureImage *)(*(__int64 (__fastcall **)(void *, signed __int64))(*(_QWORD *)v25 + 80i64))(
                                                 v25,
                                                 56i64);
      v25 = v16;
      if ( v16 )
      {
        v17 = (Scaleform::Render::Size<unsigned long> *)v3->vfptr[5].__vecDelDtor(
                                                          (Scaleform::RefCountImplCore *)&v3->vfptr,
                                                          (unsigned int)&v22);
        Scaleform::Render::TextureImage::TextureImage(v16, v4, v17, v9, v15, psync);
        v6 = v18;
      }
    }
    if ( v15 )
    {
      if ( !_InterlockedDecrement(&v15->RefCount) )
        v15->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v15->vfptr, 1u);
    }
  }
  else
  {
    v19 = (Scaleform::Render::Size<unsigned long> *)v3->vfptr[5].__vecDelDtor(
                                                      (Scaleform::RefCountImplCore *)&v3->vfptr,
                                                      (unsigned int)&v25);
    result = Scaleform::Render::RawImage::Create(v4, mipLevelCount, v19, v9, v8, psync);
    v21 = result;
    if ( !result )
      return result;
    *(_QWORD *)&v23.Format = 0i64;
    *(_DWORD *)&v23.Flags = 0x10000;
    v23.pPlanes = &v23.Plane0;
    v23.pPalette.pObject = 0i64;
    *(_QWORD *)&v23.Plane0.Width = 0i64;
    v23.Plane0.Pitch = 0i64;
    v23.Plane0.DataSize = 0i64;
    v23.Plane0.pData = 0i64;
    Scaleform::Render::ImageData::operator=(&v23, &result->Data);
    if ( ((unsigned __int8 (__fastcall *)(Scaleform::Render::ImageSource *, Scaleform::Render::ImageData *, _QWORD, _QWORD))v3->vfptr[8].__vecDelDtor)(
           v3,
           &v23,
           Scaleform::Render::ImageBase::CopyScanlineDefault,
           0i64) )
    {
      v6 = v21;
    }
    else
    {
      ((void (__fastcall *)(Scaleform::Render::RawImage *))v21->vfptr[2].__vecDelDtor)(v21);
    }
    if ( v23.Flags & 2 )
    {
      v23.Flags &= 0xFDu;
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v23.pPlanes);
    }
    v23.pPlanes = &v23.Plane0;
    if ( v23.pPalette.pObject && !_InterlockedDecrement(&v23.pPalette.pObject->RefCount.Value) )
      ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
  }
  return v6;
}

// File Line: 1096
// RVA: 0x94C200
void __fastcall Scaleform::Render::RawImage::~RawImage(Scaleform::Render::RawImage *this)
{
  Scaleform::Render::RawImage *v1; // rdi
  char v2; // al
  volatile signed __int32 *v3; // rdx

  v1 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::RawImage::`vftable';
  Scaleform::Render::RawImage::freeData(this);
  v2 = v1->Data.Flags;
  if ( v2 & 2 )
  {
    v1->Data.Flags = v2 & 0xFD;
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v1->Data.pPlanes);
  }
  v1->Data.pPlanes = &v1->Data.Plane0;
  v3 = &v1->Data.pPalette.pObject->RefCount.Value;
  if ( v3 && !_InterlockedDecrement(v3) )
    ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  Scaleform::Render::Image::~Image((Scaleform::Render::Image *)&v1->vfptr);
}

// File Line: 1115
// RVA: 0x9E3560
void __fastcall Scaleform::Render::RawImage::freeData(Scaleform::Render::RawImage *this)
{
  Scaleform::Render::RawImage *v1; // rsi
  unsigned int v2; // ebx
  signed __int64 v3; // rdi

  v1 = this;
  v2 = 0;
  if ( this->Data.RawPlaneCount > 0u )
  {
    do
    {
      v3 = v2;
      if ( v1->Data.pPlanes[v3].pData )
      {
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
        v1->Data.pPlanes[v3].pData = 0i64;
      }
      ++v2;
    }
    while ( v2 < v1->Data.RawPlaneCount );
  }
}

// File Line: 1131
// RVA: 0x9659D0
Scaleform::Render::RawImage *__fastcall Scaleform::Render::RawImage::Create(Scaleform::Render::ImageFormat format, unsigned int mipLevelCount, Scaleform::Render::Size<unsigned long> *size, unsigned int use, Scaleform::MemoryHeap *pheap, Scaleform::Render::ImageUpdateSync *pupdateSync)
{
  unsigned __int16 v6; // di
  Scaleform::Render::Size<unsigned long> *v7; // r15
  unsigned int v8; // esi
  Scaleform::Render::ImageFormat v9; // er13
  Scaleform::MemoryHeap *v10; // r12
  Scaleform::Render::RawImage *v11; // rax
  unsigned int v12; // ebp
  __int64 v13; // rax
  __int64 v14; // r14
  unsigned int v15; // eax
  unsigned int v16; // edi
  unsigned int v17; // esi
  unsigned __int64 v18; // r13
  signed __int64 v19; // rbx
  __int64 v21; // [rsp+20h] [rbp-48h]
  Scaleform::Render::ImageFormat fmt; // [rsp+70h] [rbp+8h]
  unsigned int levels; // [rsp+78h] [rbp+10h]
  int v24; // [rsp+88h] [rbp+20h]

  levels = mipLevelCount;
  fmt = format;
  v6 = use;
  v7 = size;
  v8 = mipLevelCount;
  v9 = format;
  v10 = pheap;
  if ( !pheap )
    v10 = Scaleform::Memory::pGlobalHeap;
  pheap = v10;
  if ( !(use & 2) || mipLevelCount == 1 )
  {
    v11 = (Scaleform::Render::RawImage *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))v10->vfptr->Alloc)(
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
      if ( Scaleform::Render::ImageData::allocPlanes((Scaleform::Render::ImageData *)(v14 + 40), v9, v8, 0) )
      {
        *(_DWORD *)(v14 + 44) = v6;
        *(_QWORD *)(v14 + 24) = pupdateSync;
        if ( *(_WORD *)(v14 + 50) <= 0u )
          return (Scaleform::Render::RawImage *)v14;
        v15 = (v9 & 0xFFF) - 200;
        v24 = (v9 & 0xFFF) - 200;
        while ( 1 )
        {
          if ( v15 > 1 || v12 - 1 > 1 )
          {
            v16 = v7->Width;
            v17 = v7->Height;
          }
          else
          {
            v16 = v7->Width >> 1;
            v17 = v7->Height >> 1;
          }
          pheap = (Scaleform::MemoryHeap *)__PAIR__(v17, v16);
          v18 = Scaleform::Render::ImageData::GetMipLevelsSize(
                  v9,
                  (Scaleform::Render::Size<unsigned long> *)&pheap,
                  levels,
                  v12);
          v21 = (__int64)v10->vfptr->Alloc(v10, v18, 0i64);
          if ( !v21 )
            break;
          v19 = *(_QWORD *)(v14 + 56) + 32i64 * v12;
          *(_DWORD *)v19 = v16;
          *(_DWORD *)(v19 + 4) = v17;
          *(_QWORD *)(v19 + 8) = Scaleform::Render::ImageData::GetFormatPitch(fmt, v16, v12);
          *(_QWORD *)(v19 + 16) = v18;
          *(_QWORD *)(v19 + 24) = v21;
          ++v12;
          v15 = v24;
          v9 = fmt;
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
char __fastcall Scaleform::Render::RawImage::Map(Scaleform::Render::RawImage *this, Scaleform::Render::ImageData *pdata, unsigned int levelIndex, unsigned int levelCount)
{
  Scaleform::Render::RawImage *v4; // rbx

  v4 = this;
  if ( !Scaleform::Render::ImageData::Initialize(pdata, &this->Data, levelIndex, levelCount) )
    return 0;
  v4->Data.Flags |= 0x10u;
  return 1;
}

// File Line: 1215
// RVA: 0x9BB630
char __fastcall Scaleform::Render::RawImage::Unmap(Scaleform::Render::RawImage *this)
{
  this->Data.Flags &= 0xEFu;
  return 1;
}

// File Line: 1225
// RVA: 0x96B560
char __fastcall Scaleform::Render::RawImage::Decode(Scaleform::Render::RawImage *this, Scaleform::Render::ImageData *pdest, void (__fastcall *copyScanline)(char *, const char *, unsigned __int64, Scaleform::Render::Palette *, void *), void *arg)
{
  unsigned int v4; // er13
  Scaleform::Render::ImageData *v5; // r15
  Scaleform::Render::ImageFormat v6; // edx
  __int16 v7; // r9
  Scaleform::Render::RawImage *v8; // rbx
  signed int v9; // eax
  unsigned int v10; // er8
  signed int v11; // ecx
  unsigned int v12; // er12
  unsigned int v13; // ecx
  __int64 v14; // rdi
  unsigned int v15; // ecx
  Scaleform::Render::ImagePlane *v16; // rcx
  unsigned __int64 v17; // rsi
  char *v18; // r14
  unsigned int v19; // eax
  unsigned __int64 v20; // rax
  unsigned int v21; // ecx
  Scaleform::Render::ImagePlane *v22; // rcx
  unsigned __int64 v23; // rax
  char *v24; // rcx
  unsigned int v25; // edi
  int v26; // edx
  __int64 v27; // r8
  int v28; // er10
  char *v29; // rsi
  char v30; // dl
  char *v31; // r14
  unsigned int v32; // er13
  int v33; // er8
  unsigned int v34; // ecx
  unsigned int v35; // eax
  signed __int64 v36; // rcx
  unsigned __int64 v37; // rdx
  unsigned __int64 v38; // rdi
  unsigned __int64 v39; // rax
  char *v40; // rax
  char *v41; // rax
  signed __int64 v42; // rcx
  unsigned __int64 v43; // rdx
  unsigned int v44; // ecx
  unsigned int v45; // eax
  signed __int64 v46; // rcx
  unsigned __int64 v47; // r12
  unsigned int v48; // eax
  char *v49; // rax
  char *v50; // rax
  signed __int64 v51; // rcx
  unsigned int v52; // eax
  unsigned __int64 v53; // rax
  unsigned int v54; // eax
  unsigned int v55; // eax
  unsigned __int64 v56; // r13
  unsigned __int64 v57; // r15
  unsigned __int8 v58; // dl
  unsigned __int8 v59; // cl
  unsigned int v60; // er9
  unsigned __int8 v61; // r8
  unsigned int v62; // eax
  unsigned int v63; // ecx
  char *v64; // rcx
  unsigned __int64 v65; // r14
  unsigned __int64 v66; // r13
  unsigned __int64 v67; // rax
  char *v68; // rsi
  unsigned int v69; // ecx
  char *v70; // rcx
  unsigned __int64 v71; // r12
  char *v72; // rdi
  unsigned int v73; // eax
  unsigned __int64 v74; // rax
  unsigned int v75; // eax
  unsigned __int64 v76; // r15
  unsigned int v78; // [rsp+30h] [rbp-69h]
  unsigned int v79; // [rsp+30h] [rbp-69h]
  Scaleform::Render::ImagePlane p; // [rsp+38h] [rbp-61h]
  unsigned int v81; // [rsp+58h] [rbp-41h]
  unsigned int v82; // [rsp+5Ch] [rbp-3Dh]
  Scaleform::Render::ImagePlane v83; // [rsp+60h] [rbp-39h]
  int v84; // [rsp+80h] [rbp-19h]
  int v85; // [rsp+84h] [rbp-15h]
  int v86; // [rsp+88h] [rbp-11h]
  unsigned __int64 v87; // [rsp+90h] [rbp-9h]
  unsigned int v88; // [rsp+98h] [rbp-1h]
  __int64 v89; // [rsp+A0h] [rbp+7h]
  int v90; // [rsp+100h] [rbp+67h]
  Scaleform::Render::ImageData *v91; // [rsp+108h] [rbp+6Fh]
  void (__fastcall *v92)(char *, const char *, unsigned __int64, Scaleform::Render::Palette *, void *); // [rsp+110h] [rbp+77h]
  void *v93; // [rsp+118h] [rbp+7Fh]

  v93 = arg;
  v92 = copyScanline;
  v91 = pdest;
  v4 = 0;
  v5 = pdest;
  v6 = this->Data.Format;
  v7 = this->Data.Format;
  v8 = this;
  *(_QWORD *)&p.Width = 0i64;
  p.Pitch = 0i64;
  p.DataSize = 0i64;
  p.pData = 0i64;
  *(_QWORD *)&v83.Width = 0i64;
  v83.Pitch = 0i64;
  v90 = v7 & 0xFFF;
  v83.DataSize = 0i64;
  v83.pData = 0i64;
  v9 = 1;
  if ( v7 & 0xFFF )
  {
    if ( (v7 & 0xFFF) == 200 )
    {
      v10 = 3;
    }
    else if ( (v7 & 0xFFF) == 201 )
    {
      v10 = 4;
    }
    else
    {
      v10 = 1;
    }
  }
  else
  {
    v10 = 0;
  }
  v81 = v10;
  if ( this->Data.Flags & 1 )
    v11 = (unsigned __int8)this->Data.LevelCount;
  else
    v11 = 1;
  v12 = v11 * v8->Data.RawPlaneCount;
  if ( v5->Flags & 1 )
    v9 = (unsigned __int8)v5->LevelCount;
  v13 = v9 * v5->RawPlaneCount;
  if ( (signed int)(v6 & 0xFFEFFFFF) >= 4096 )
  {
    if ( v12 )
    {
      v14 = 0i64;
      do
      {
        v15 = v8->Data.RawPlaneCount;
        if ( v4 >= v15 )
        {
          Scaleform::Render::ImagePlane::GetMipLevel(
            &v8->Data.pPlanes[v4 % v15],
            v8->Data.Format,
            v4 / v15,
            &p,
            v4 % v15);
          v18 = p.pData;
          v17 = p.DataSize;
        }
        else
        {
          v16 = &v8->Data.pPlanes[v14];
          v17 = v16->DataSize;
          v18 = v16->pData;
          p.Width = v16->Width;
          v19 = v16->Height;
          p.DataSize = v17;
          p.Height = v19;
          v20 = v16->Pitch;
          p.pData = v18;
          p.Pitch = v20;
        }
        v21 = v5->RawPlaneCount;
        if ( v4 >= v21 )
        {
          Scaleform::Render::ImagePlane::GetMipLevel(&v5->pPlanes[v4 % v21], v5->Format, v4 / v21, &v83, v4 % v21);
          v24 = v83.pData;
        }
        else
        {
          v22 = &v5->pPlanes[v14];
          v83.Width = v22->Width;
          v83.Height = v22->Height;
          v83.Pitch = v22->Pitch;
          v23 = v22->DataSize;
          v24 = v22->pData;
          v83.pData = v24;
          v83.DataSize = v23;
        }
        memmove(v24, v18, v17);
        ++v4;
        ++v14;
      }
      while ( v4 < v12 );
    }
    return 1;
  }
  v25 = 0;
  v82 = 0;
  if ( v12 < v13 )
    v13 = v12;
  v88 = v13;
  if ( v13 )
  {
    v89 = 0i64;
    v26 = v13 % v10;
    v27 = 0i64;
    v28 = v26;
    v84 = v26;
    do
    {
      if ( (v8->Data.Flags & 1 || v8->Data.LevelCount == 1) && (v5->Flags & 1 || v5->LevelCount == 1) )
      {
        v63 = v8->Data.RawPlaneCount;
        if ( v25 >= v63 )
        {
          Scaleform::Render::ImagePlane::GetMipLevel(
            &v8->Data.pPlanes[v25 % v63],
            v8->Data.Format,
            v25 / v63,
            &p,
            v25 % v63);
          v68 = p.pData;
          v66 = p.Pitch;
          v65 = p.Height;
          v27 = v89;
          v79 = p.Width;
        }
        else
        {
          v64 = (char *)v8->Data.pPlanes + v27;
          v65 = *((unsigned int *)v64 + 1);
          v66 = *((_QWORD *)v64 + 1);
          v67 = *((_QWORD *)v64 + 2);
          v68 = (char *)*((_QWORD *)v64 + 3);
          v79 = *(_DWORD *)v64;
          p.Width = *(_DWORD *)v64;
          p.Height = v65;
          p.Pitch = v66;
          p.DataSize = v67;
          p.pData = v68;
        }
        v69 = v5->RawPlaneCount;
        if ( v25 >= v69 )
        {
          Scaleform::Render::ImagePlane::GetMipLevel(&v5->pPlanes[v25 % v69], v5->Format, v25 / v69, &v83, v25 % v69);
          v72 = v83.pData;
          v71 = v83.Pitch;
        }
        else
        {
          v70 = (char *)v5->pPlanes + v27;
          v71 = *((_QWORD *)v70 + 1);
          v72 = (char *)*((_QWORD *)v70 + 3);
          v83.Width = *(_DWORD *)v70;
          v73 = *((_DWORD *)v70 + 1);
          v83.Pitch = v71;
          v83.Height = v73;
          v74 = *((_QWORD *)v70 + 2);
          v83.pData = v72;
          v83.DataSize = v74;
        }
        if ( (unsigned int)(v90 - 50) <= 3 )
          v65 = (unsigned __int64)(unsigned int)(v65 + 3) >> 2;
        v75 = v79 * Scaleform::Render::ImageData::GetFormatBitsPerPixel(v8->Data.Format, 0) >> 3;
        if ( v65 )
        {
          v76 = v75;
          do
          {
            v92(v72, v68, v76, v8->Data.pPalette.pObject, v93);
            v68 += v66;
            v72 += v71;
            --v65;
          }
          while ( v65 );
          v5 = v91;
        }
      }
      else
      {
        v29 = 0i64;
        v30 = v5->LevelCount;
        v31 = 0i64;
        if ( (unsigned __int8)v8->Data.LevelCount < v5->LevelCount )
          v30 = v8->Data.LevelCount;
        v86 = 0;
        if ( !v30 )
          goto LABEL_81;
        v32 = v25;
        v78 = v25;
        v33 = v28 - v25;
        v85 = v28 - v25;
        do
        {
          v34 = v8->Data.RawPlaneCount;
          if ( v8->Data.Flags & 1 )
          {
            v35 = v33 + v32;
            if ( v33 + v32 >= v34 )
            {
              Scaleform::Render::ImagePlane::GetMipLevel(
                &v8->Data.pPlanes[v35 % v34],
                v8->Data.Format,
                v35 / v34,
                &p,
                v35 % v34);
              v41 = p.pData;
              v38 = p.Height;
              v33 = v85;
              if ( v29 )
                v41 = v29;
              v87 = p.Pitch;
              v29 = v41;
            }
            else
            {
              v36 = (signed __int64)&v8->Data.pPlanes[v35];
              v37 = *(_QWORD *)(v36 + 8);
              v38 = *(unsigned int *)(v36 + 4);
              p.Width = *(_DWORD *)v36;
              v39 = *(_QWORD *)(v36 + 16);
              p.Height = v38;
              p.DataSize = v39;
              v40 = *(char **)(v36 + 24);
              v87 = v37;
              p.pData = v40;
              if ( v29 )
                v40 = v29;
              p.Pitch = v37;
              v29 = v40;
            }
          }
          else if ( v32 >= v34 )
          {
            Scaleform::Render::ImagePlane::GetMipLevel(
              &v8->Data.pPlanes[v32 % v34],
              v8->Data.Format,
              v32 / v34,
              &p,
              v32 % v34);
            v29 = p.pData;
            v38 = p.Height;
            v33 = v85;
            v87 = p.Pitch;
          }
          else
          {
            v42 = (signed __int64)&v8->Data.pPlanes[v32];
            v43 = *(_QWORD *)(v42 + 8);
            v38 = *(unsigned int *)(v42 + 4);
            v29 = *(char **)(v42 + 24);
            p.Width = *(_DWORD *)v42;
            p.DataSize = *(_QWORD *)(v42 + 16);
            p.Height = v38;
            v87 = v43;
            p.Pitch = v43;
            p.pData = v29;
          }
          v44 = v5->RawPlaneCount;
          if ( v5->Flags & 1 )
          {
            v45 = v33 + v32;
            if ( v33 + v32 >= v44 )
            {
              Scaleform::Render::ImagePlane::GetMipLevel(
                &v5->pPlanes[v45 % v44],
                v5->Format,
                v45 / v44,
                &v83,
                v45 % v44);
              v50 = v83.pData;
              v47 = v83.Pitch;
              if ( v31 )
                v50 = v31;
              v31 = v50;
            }
            else
            {
              v46 = (signed __int64)&v5->pPlanes[v45];
              v47 = *(_QWORD *)(v46 + 8);
              v83.Width = *(_DWORD *)v46;
              v48 = *(_DWORD *)(v46 + 4);
              v83.Pitch = v47;
              v83.Height = v48;
              v83.DataSize = *(_QWORD *)(v46 + 16);
              v49 = *(char **)(v46 + 24);
              v83.pData = *(char **)(v46 + 24);
              if ( v31 )
                v49 = v31;
              v31 = v49;
            }
          }
          else if ( v32 >= v44 )
          {
            Scaleform::Render::ImagePlane::GetMipLevel(&v5->pPlanes[v32 % v44], v5->Format, v32 / v44, &v83, v32 % v44);
            v31 = v83.pData;
            v47 = v83.Pitch;
          }
          else
          {
            v51 = (signed __int64)&v5->pPlanes[v32];
            v47 = *(_QWORD *)(v51 + 8);
            v31 = *(char **)(v51 + 24);
            v83.Width = *(_DWORD *)v51;
            v52 = *(_DWORD *)(v51 + 4);
            v83.Pitch = v47;
            v83.Height = v52;
            v53 = *(_QWORD *)(v51 + 16);
            v83.pData = v31;
            v83.DataSize = v53;
          }
          if ( (unsigned int)(v90 - 50) <= 3 )
            v38 = (unsigned __int64)(unsigned int)(v38 + 3) >> 2;
          v54 = Scaleform::Render::ImageData::GetFormatBitsPerPixel(v8->Data.Format, 0);
          v55 = p.Width * v54 >> 3;
          if ( v38 )
          {
            v56 = v87;
            v57 = v55;
            do
            {
              v92(v31, v29, v57, v8->Data.pPalette.pObject, v93);
              v29 += v56;
              v31 += v47;
              --v38;
            }
            while ( v38 );
            v5 = v91;
            v32 = v78;
          }
          v32 += v81;
          v58 = v5->LevelCount;
          v59 = v8->Data.LevelCount;
          v60 = v86 + 1;
          v61 = v5->LevelCount;
          ++v86;
          v78 = v32;
          if ( v59 < v58 )
            v61 = v59;
          v62 = v61;
          v33 = v85;
        }
        while ( v60 < v62 );
      }
      v25 = v82;
      v28 = v84;
LABEL_81:
      ++v25;
      v27 = v89 + 32;
      v82 = v25;
      v89 += 32i64;
    }
    while ( v25 < v88 );
  }
  return 1;
}

// File Line: 1332
// RVA: 0x98DB60
Scaleform::Render::Texture *__fastcall Scaleform::Render::RawImage::GetTexture(Scaleform::Render::RawImage *this, Scaleform::Render::TextureManager *pmanager)
{
  Scaleform::Render::TextureManager *v2; // r11
  Scaleform::Render::RawImage *v3; // rbx
  Scaleform::Render::TextureManagerLocks *v4; // rax
  Scaleform::Render::TextureManager *v5; // rax
  Scaleform::Render::Texture *result; // rax
  Scaleform::Render::ImagePlane *v7; // rax
  Scaleform::RefCountImplCoreVtbl *v8; // r10
  int v9; // ecx
  __int64 v10; // r8
  __int64 v11; // rdx
  unsigned int v12; // [rsp+50h] [rbp+8h]
  int v13; // [rsp+54h] [rbp+Ch]

  v2 = pmanager;
  v3 = this;
  if ( this->pTexture.Value )
  {
    v4 = this->pTexture.Value->pManagerLocks.pObject;
    v5 = v4 ? v4->pManager : 0i64;
    if ( v5 == pmanager )
      return this->pTexture.Value;
  }
  if ( !pmanager )
    return 0i64;
  this->pTexture.Value = 0i64;
  v7 = this->Data.pPlanes;
  v8 = pmanager->vfptr;
  v9 = v7->Height;
  v10 = (unsigned __int8)v3->Data.LevelCount;
  v11 = (unsigned int)v3->Data.Format;
  v12 = v7->Width;
  LODWORD(v7) = v3->Data.Use;
  v13 = v9;
  result = (Scaleform::Render::Texture *)((__int64 (__fastcall *)(Scaleform::Render::TextureManager *, __int64, __int64, unsigned int *, unsigned int, Scaleform::Render::RawImage *, _QWORD))v8[1].__vecDelDtor)(
                                           v2,
                                           v11,
                                           v10,
                                           &v12,
                                           (unsigned int)v7 & 0xFFFFFF3F,
                                           v3,
                                           0i64);
  v3->pTexture.Value = result;
  return result;
}

// File Line: 1386
// RVA: 0x988E70
char __fastcall Scaleform::Render::SubImage::GetMatrixInverse(Scaleform::Render::SubImage *this, Scaleform::Render::Matrix2x4<float> *mat)
{
  Scaleform::Render::SubImage *v2; // rdi
  __m128 *v3; // rbx
  char result; // al
  bool v5; // cl
  Scaleform::Render::Matrix2x4<float> *v6; // rdx
  __m128 *v7; // rax
  __m128 v8; // xmm5
  __m128 v9; // xmm4
  __m128 v10; // xmm7
  __m128 v11; // xmm0
  __m128 v12; // xmm2
  __m128 v13; // xmm5

  v2 = this;
  v3 = (__m128 *)mat;
  result = ((__int64 (*)(void))this->pImage.pObject->vfptr[16].__vecDelDtor)();
  v5 = result;
  if ( !result )
  {
    v6 = v2->pInverseMatrix;
    if ( !v6 )
      return result;
    *(float *)v3->m128_u64 = v6->M[0][0];
    HIDWORD(v3->m128_u64[0]) = LODWORD(v6->M[0][1]);
    *(float *)&v3->m128_u64[1] = v6->M[0][2];
    HIDWORD(v3->m128_u64[1]) = LODWORD(v6->M[0][3]);
    v3[1].m128_i32[0] = LODWORD(v6->M[1][0]);
    v3[1].m128_i32[1] = LODWORD(v6->M[1][1]);
    v3[1].m128_i32[2] = LODWORD(v6->M[1][2]);
    v3[1].m128_i32[3] = LODWORD(v6->M[1][3]);
  }
  v7 = (__m128 *)v2->pInverseMatrix;
  if ( v7 )
  {
    if ( v5 )
    {
      v8 = v7[1];
      v9 = *v3;
      v10 = (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<4294967295,4294967295,0,4294967295>'::`2'::v;
      v11 = _mm_shuffle_ps(v8, v8, 0);
      v12 = _mm_shuffle_ps(v8, v8, 85);
      v13 = _mm_and_ps(v8, (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>'::`2'::v);
      *v3 = _mm_and_ps(
              _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(_mm_shuffle_ps(*v7, *v7, 85), v3[1]),
                  _mm_mul_ps(_mm_shuffle_ps(*v7, *v7, 0), *v3)),
                _mm_and_ps(*v7, (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>'::`2'::v)),
              (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<4294967295,4294967295,0,4294967295>'::`2'::v);
      v3[1] = _mm_and_ps(_mm_add_ps(_mm_add_ps(_mm_mul_ps(v12, v3[1]), _mm_mul_ps(v11, v9)), v13), v10);
    }
  }
  return 1;
}

// File Line: 1417
// RVA: 0x94B0E0
void __fastcall Scaleform::Render::ImageUpdateQueue::~ImageUpdateQueue(Scaleform::Render::ImageUpdateQueue *this)
{
  Scaleform::Render::ImageUpdateQueue *v1; // rbx
  unsigned int v2; // edi
  __int64 v3; // rax
  unsigned __int64 v4; // rcx

  v1 = this;
  v2 = 0;
  if ( this->Queue.Data.Size )
  {
    v3 = 0i64;
    do
    {
      v4 = v1->Queue.Data.Data[v3];
      if ( v4 & 1 )
      {
        (*(void (__cdecl **)(unsigned __int64))(*(_QWORD *)(v4 & 0xFFFFFFFFFFFFFFFEui64) + 16i64))(v4 & 0xFFFFFFFFFFFFFFFEui64);
      }
      else if ( !_InterlockedDecrement((volatile signed __int32 *)(v4 + 8)) && v4 )
      {
        (**(void (__fastcall ***)(unsigned __int64, signed __int64))v4)(v4, 1i64);
      }
      v3 = ++v2;
    }
    while ( v2 < v1->Queue.Data.Size );
  }
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v1->Queue.Data.Data);
}

// File Line: 1434
// RVA: 0x9A04D0
void __fastcall Scaleform::Render::ImageUpdateQueue::ProcessUpdates(Scaleform::Render::ImageUpdateQueue *this, Scaleform::Render::TextureManager *pmanager)
{
  unsigned int v2; // esi
  Scaleform::Render::TextureManager *v3; // rbp
  Scaleform::Render::ImageUpdateQueue *v4; // rdi
  __int64 v5; // rax
  volatile signed __int32 *v6; // rbx
  unsigned __int64 v7; // rbx
  __int64 v8; // rax
  unsigned __int64 *v9; // rax
  int v10; // [rsp+30h] [rbp+8h]

  v2 = 0;
  v3 = pmanager;
  v4 = this;
  if ( this->Queue.Data.Size )
  {
    v5 = 0i64;
    do
    {
      v6 = (volatile signed __int32 *)v4->Queue.Data.Data[v5];
      if ( (unsigned __int8)v6 & 1 )
      {
        v7 = (unsigned __int64)v6 & 0xFFFFFFFFFFFFFFFEui64;
        v8 = (*(__int64 (__fastcall **)(unsigned __int64, Scaleform::Render::TextureManager *))(*(_QWORD *)v7 + 168i64))(
               v7,
               v3);
        if ( v8 )
          (*(void (__fastcall **)(__int64))(*(_QWORD *)v8 + 136i64))(v8);
        (*(void (__fastcall **)(unsigned __int64))(*(_QWORD *)v7 + 16i64))(v7);
      }
      else
      {
        (*(void (__fastcall **)(volatile signed __int32 *, Scaleform::Render::TextureManager *))(*(_QWORD *)v6 + 8i64))(
          v6,
          v3);
        if ( !_InterlockedDecrement(v6 + 2) )
          (**(void (__fastcall ***)(volatile signed __int32 *, signed __int64))v6)(v6, 1i64);
      }
      v5 = ++v2;
    }
    while ( v2 < v4->Queue.Data.Size );
  }
  if ( v4->Queue.Data.Size && v4->Queue.Data.Policy.Capacity & 0xFFFFFFFFFFFFFFFEui64 )
  {
    if ( v4->Queue.Data.Data )
    {
      v9 = (unsigned __int64 *)Scaleform::Memory::pGlobalHeap->vfptr->Realloc(
                                 Scaleform::Memory::pGlobalHeap,
                                 v4->Queue.Data.Data,
                                 32ui64);
    }
    else
    {
      v10 = 72;
      v9 = (unsigned __int64 *)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                                 Scaleform::Memory::pGlobalHeap,
                                 v4,
                                 32ui64,
                                 (Scaleform::AllocInfo *)&v10);
    }
    v4->Queue.Data.Data = v9;
    v4->Queue.Data.Policy.Capacity = 4i64;
  }
  v4->Queue.Data.Size = 0i64;
}

// File Line: 1456
// RVA: 0x953DF0
void __fastcall Scaleform::Render::ImageUpdateQueue::Add(Scaleform::Render::ImageUpdateQueue *this, Scaleform::Render::Image *pimage)
{
  unsigned __int64 v2; // rax
  Scaleform::Render::Image *v3; // rsi
  unsigned __int64 v4; // rdi
  unsigned __int64 v5; // rbp
  Scaleform::Render::ImageUpdateQueue *v6; // rbx
  unsigned __int64 v7; // r8
  unsigned __int64 *v8; // rcx
  unsigned __int64 *v9; // rcx

  v2 = this->Queue.Data.Size;
  v3 = pimage;
  v4 = v2 + 1;
  v5 = (unsigned __int64)pimage | 1;
  v6 = this;
  if ( v2 + 1 >= v2 )
  {
    if ( v4 <= this->Queue.Data.Policy.Capacity )
      goto LABEL_7;
    v7 = v4 + (v4 >> 2);
  }
  else
  {
    if ( v4 >= this->Queue.Data.Policy.Capacity >> 1 )
      goto LABEL_7;
    v7 = v2 + 1;
  }
  Scaleform::ArrayDataBase<unsigned __int64,Scaleform::AllocatorLH<unsigned __int64,72>,Scaleform::ArrayConstPolicy<4,4,0>>::Reserve(
    (Scaleform::ArrayDataBase<unsigned __int64,Scaleform::AllocatorLH<unsigned __int64,72>,Scaleform::ArrayConstPolicy<4,4,0> > *)&this->Queue.Data.Data,
    this,
    v7);
LABEL_7:
  v8 = v6->Queue.Data.Data;
  v6->Queue.Data.Size = v4;
  v9 = &v8[v4 - 1];
  if ( v9 )
    *v9 = v5;
  ((void (__fastcall *)(Scaleform::Render::Image *))v3->vfptr[1].__vecDelDtor)(v3);
}

// File Line: 1463
// RVA: 0x953E80
void __fastcall Scaleform::Render::ImageUpdateQueue::Add(Scaleform::Render::ImageUpdateQueue *this, Scaleform::Render::ImageUpdate *pupdate)
{
  unsigned __int64 v2; // rax
  Scaleform::Render::ImageUpdate *v3; // rsi
  Scaleform::Render::ImageUpdateQueue *v4; // rbx
  unsigned __int64 v5; // rdi
  unsigned __int64 v6; // r8
  unsigned __int64 *v7; // rcx
  Scaleform::Render::ImageUpdate **v8; // rcx

  v2 = this->Queue.Data.Size;
  v3 = pupdate;
  v4 = this;
  v5 = v2 + 1;
  if ( v2 + 1 >= v2 )
  {
    if ( v5 <= this->Queue.Data.Policy.Capacity )
      goto LABEL_7;
    v6 = v5 + (v5 >> 2);
  }
  else
  {
    if ( v5 >= this->Queue.Data.Policy.Capacity >> 1 )
      goto LABEL_7;
    v6 = v2 + 1;
  }
  Scaleform::ArrayDataBase<unsigned __int64,Scaleform::AllocatorLH<unsigned __int64,72>,Scaleform::ArrayConstPolicy<4,4,0>>::Reserve(
    (Scaleform::ArrayDataBase<unsigned __int64,Scaleform::AllocatorLH<unsigned __int64,72>,Scaleform::ArrayConstPolicy<4,4,0> > *)&this->Queue.Data.Data,
    this,
    v6);
LABEL_7:
  v7 = v4->Queue.Data.Data;
  v4->Queue.Data.Size = v5;
  v8 = (Scaleform::Render::ImageUpdate **)&v7[v5 - 1];
  if ( v8 )
    *v8 = v3;
  _InterlockedExchangeAdd(&v3->RefCount, 1u);
}

// File Line: 1476
// RVA: 0x946320
void __fastcall Scaleform::Render::TextureManager::TextureManager(Scaleform::Render::TextureManager *this, void *renderThreadId, Scaleform::Render::ThreadCommandQueue *commandQueue, Scaleform::Render::TextureCache *textureCache)
{
  Scaleform::Render::TextureManager *v4; // rbx
  Scaleform::ArrayLH<Scaleform::Render::TextureFormat *,2,Scaleform::ArrayDefaultPolicy> *v5; // rax
  Scaleform::Render::TextureManagerLocks *v6; // rdi
  Scaleform::Render::ImageUpdateQueue *v7; // rax
  Scaleform::ArrayLH<Scaleform::Render::TextureFormat *,2,Scaleform::ArrayDefaultPolicy> *v8; // rax
  Scaleform::List<Scaleform::Render::Texture,Scaleform::Render::Texture> *v9; // rax
  unsigned __int64 *v10; // rcx
  signed __int64 v11; // rcx
  signed __int64 v12; // rcx
  Scaleform::Render::TextureManagerLocks *v13; // rax
  Scaleform::Render::TextureManagerLocks *v14; // rax
  Scaleform::Render::TextureManagerLocks *v15; // rcx
  Scaleform::ArrayLH<Scaleform::Render::TextureFormat *,2,Scaleform::ArrayDefaultPolicy> *v16; // [rsp+58h] [rbp+10h]
  Scaleform::ArrayLH<Scaleform::Render::TextureFormat *,2,Scaleform::ArrayDefaultPolicy> *v17; // [rsp+60h] [rbp+18h]
  Scaleform::Render::ImageUpdateQueue *v18; // [rsp+68h] [rbp+20h]

  v4 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,72>::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::Render::TextureManager,72>::`vftable';
  this->vfptr = (Scaleform::Render::ImageUpdateSyncVtbl *)&Scaleform::Render::ImageUpdateSync::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::TextureManager::`vftable'{for `Scaleform::RefCountBase<Scaleform::Render::TextureManager,72>'};
  this->vfptr = (Scaleform::Render::ImageUpdateSyncVtbl *)&Scaleform::Render::TextureManager::`vftable'{for `Scaleform::Render::ImageUpdateSync'};
  v5 = (Scaleform::ArrayLH<Scaleform::Render::TextureFormat *,2,Scaleform::ArrayDefaultPolicy> *)&this->ServiceCommandInstance;
  v17 = v5;
  v5->Data.Data = (Scaleform::Render::TextureFormat **)&Scaleform::RefCountImplCore::`vftable';
  LODWORD(v5->Data.Size) = 1;
  v5->Data.Data = (Scaleform::Render::TextureFormat **)&Scaleform::RefCountImpl::`vftable';
  v5->Data.Data = (Scaleform::Render::TextureFormat **)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable';
  v5->Data.Data = (Scaleform::Render::TextureFormat **)&Scaleform::RefCountBase<Scaleform::Render::ThreadCommand,2>::`vftable';
  v5->Data.Data = (Scaleform::Render::TextureFormat **)&Scaleform::Render::ThreadCommand::`vftable';
  v5->Data.Data = (Scaleform::Render::TextureFormat **)&Scaleform::Render::TextureManager::ServiceCommand::`vftable';
  v4->ServiceCommandInstance.pManager = v4;
  this->RenderThreadId = renderThreadId;
  this->pRTCommandQueue = commandQueue;
  if ( textureCache )
    _InterlockedExchangeAdd(&textureCache->RefCount, 1u);
  this->pTextureCache.pObject = textureCache;
  v6 = 0i64;
  this->pLocks.pObject = 0i64;
  v7 = &this->ImageUpdates;
  v18 = &this->ImageUpdates;
  v7->Queue.Data.Data = 0i64;
  v7->Queue.Data.Size = 0i64;
  v7->Queue.Data.Policy.Capacity = 0i64;
  v8 = &this->TextureFormats;
  v16 = v8;
  v17 = &this->TextureFormats;
  v8->Data.Data = 0i64;
  v8->Data.Size = 0i64;
  v8->Data.Policy.Capacity = 0i64;
  v9 = &this->Textures;
  v10 = &this->TextureFormats.Data.Size;
  if ( v4 == (Scaleform::Render::TextureManager *)-128i64 )
    v10 = 0i64;
  v9->Root.pPrev = (Scaleform::Render::Texture *)v10;
  v4->Textures.Root.pNext = (Scaleform::Render::Texture *)v10;
  v11 = (signed __int64)&v4->Textures;
  if ( v4 == (Scaleform::Render::TextureManager *)-144i64 )
    v11 = 0i64;
  v4->TextureInitQueue.Root.pPrev = (Scaleform::Render::Texture *)v11;
  v4->TextureInitQueue.Root.pNext = (Scaleform::Render::Texture *)v11;
  v12 = (signed __int64)&v4->TextureInitQueue;
  if ( v4 == (Scaleform::Render::TextureManager *)-160i64 )
    v12 = 0i64;
  v4->DepthStencilInitQueue.Root.pPrev = (Scaleform::Render::DepthStencilSurface *)v12;
  v4->DepthStencilInitQueue.Root.pNext = (Scaleform::Render::DepthStencilSurface *)v12;
  LODWORD(v16) = 72;
  v13 = (Scaleform::Render::TextureManagerLocks *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::Render::TextureManager *, signed __int64, Scaleform::ArrayLH<Scaleform::Render::TextureFormat *,2,Scaleform::ArrayDefaultPolicy> **, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
                                                    Scaleform::Memory::pGlobalHeap,
                                                    v4,
                                                    112i64,
                                                    &v16,
                                                    -2i64);
  v17 = (Scaleform::ArrayLH<Scaleform::Render::TextureFormat *,2,Scaleform::ArrayDefaultPolicy> *)v13;
  if ( v13 )
  {
    Scaleform::Render::TextureManagerLocks::TextureManagerLocks(v13, v4);
    v6 = v14;
  }
  v15 = v4->pLocks.pObject;
  if ( v15 && !_InterlockedDecrement(&v15->RefCount) && v15 )
    v15->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v15->vfptr, 1u);
  v4->pLocks.pObject = v6;
}

// File Line: 1484
// RVA: 0x94D440
void __fastcall Scaleform::Render::TextureManager::~TextureManager(Scaleform::Render::TextureManager *this)
{
  Scaleform::Render::TextureManager *v1; // rdi
  unsigned int v2; // ebx
  __int64 v3; // rcx
  Scaleform::Render::TextureFormat *v4; // rcx
  void **v5; // rbx
  Scaleform::Render::TextureManagerLocks *v6; // rcx
  Scaleform::Render::TextureCache *v7; // rcx

  v1 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::TextureManager::`vftable'{for `Scaleform::RefCountBase<Scaleform::Render::TextureManager,72>'};
  this->vfptr = (Scaleform::Render::ImageUpdateSyncVtbl *)&Scaleform::Render::TextureManager::`vftable'{for `Scaleform::Render::ImageUpdateSync'};
  v2 = 0;
  if ( this->TextureFormats.Data.Size )
  {
    v3 = 0i64;
    do
    {
      v4 = v1->TextureFormats.Data.Data[v3];
      if ( v4 )
        v4->vfptr->__vecDelDtor(v4, 1u);
      v3 = ++v2;
    }
    while ( v2 < v1->TextureFormats.Data.Size );
  }
  v5 = (void **)&v1->TextureFormats.Data.Data;
  if ( v1->TextureFormats.Data.Size && v1->TextureFormats.Data.Policy.Capacity & 0xFFFFFFFFFFFFFFFEui64 )
  {
    if ( *v5 )
    {
      ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      *v5 = 0i64;
    }
    v1->TextureFormats.Data.Policy.Capacity = 0i64;
  }
  v1->TextureFormats.Data.Size = 0i64;
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, *v5);
  Scaleform::Render::ImageUpdateQueue::~ImageUpdateQueue(&v1->ImageUpdates);
  v6 = v1->pLocks.pObject;
  if ( v6 && !_InterlockedDecrement(&v6->RefCount) && v6 )
    v6->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v6->vfptr, 1u);
  v7 = v1->pTextureCache.pObject;
  if ( v7 && !_InterlockedDecrement(&v7->RefCount) && v7 )
    v7->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v7->vfptr, 1u);
  v1->ServiceCommandInstance.vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable';
  v1->vfptr = (Scaleform::Render::ImageUpdateSyncVtbl *)&Scaleform::Render::ImageUpdateSync::`vftable';
  v1->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable';
}

// File Line: 1492
// RVA: 0x9BE570
void __fastcall Scaleform::Render::TextureManager::UpdateImage(Scaleform::Render::TextureManager *this, Scaleform::Render::Image *pimage)
{
  Scaleform::Render::Image *v2; // rsi
  Scaleform::Render::TextureManager *v3; // rdi
  Scaleform::Mutex *v4; // rbx

  v2 = pimage;
  v3 = this;
  v4 = (Scaleform::Mutex *)&this->pRTCommandQueue[8];
  Scaleform::Mutex::DoLock(v4);
  Scaleform::Render::ImageUpdateQueue::Add((Scaleform::Render::ImageUpdateQueue *)&v3->pTextureCache, v2);
  Scaleform::Mutex::Unlock(v4);
}

// File Line: 1498
// RVA: 0x9BE5D0
void __fastcall Scaleform::Render::TextureManager::UpdateImage(Scaleform::Render::TextureManager *this, Scaleform::Render::ImageUpdate *pupdate)
{
  Scaleform::Render::ImageUpdate *v2; // rsi
  Scaleform::Render::TextureManager *v3; // rdi
  Scaleform::Mutex *v4; // rbx

  v2 = pupdate;
  v3 = this;
  v4 = (Scaleform::Mutex *)&this->pRTCommandQueue[8];
  Scaleform::Mutex::DoLock(v4);
  Scaleform::Render::ImageUpdateQueue::Add((Scaleform::Render::ImageUpdateQueue *)&v3->pTextureCache, v2);
  Scaleform::Mutex::Unlock(v4);
}

// File Line: 1504
// RVA: 0x9A0300
void __fastcall Scaleform::Render::TextureManager::ProcessQueues(Scaleform::Render::TextureManager *this)
{
  Scaleform::Render::TextureManager *v1; // rdi
  Scaleform::Mutex *v2; // rbx

  v1 = this;
  v2 = &this->pLocks.pObject->TextureMutex;
  Scaleform::Mutex::DoLock(v2);
  ((void (__fastcall *)(Scaleform::Render::TextureManager *))v1->vfptr[16].__vecDelDtor)(v1);
  ((void (__fastcall *)(Scaleform::Render::TextureManager *))v1->vfptr[17].__vecDelDtor)(v1);
  Scaleform::Render::ImageUpdateQueue::ProcessUpdates(&v1->ImageUpdates, v1);
  Scaleform::Mutex::Unlock(v2);
}

// File Line: 1512
// RVA: 0x95A800
void __fastcall Scaleform::Render::TextureManager::BeginFrame(Scaleform::Render::TextureManager *this)
{
  Scaleform::Render::TextureManager *v1; // rbx
  Scaleform::Render::TextureCache *v2; // rcx

  v1 = this;
  ((void (*)(void))this->vfptr[8].__vecDelDtor)();
  v2 = v1->pTextureCache.pObject;
  if ( v2 )
    ((void (*)(void))v2->vfptr[1].__vecDelDtor)();
}

// File Line: 1519
// RVA: 0x970A20
void __fastcall Scaleform::Render::TextureManager::EndFrame(Scaleform::Render::TextureManager *this)
{
  Scaleform::Render::TextureCache *v1; // rcx

  v1 = this->pTextureCache.pObject;
  if ( v1 )
    ((void (*)(void))v1->vfptr[2].__vecDelDtor)();
}

// File Line: 1525
// RVA: 0x9EC260
Scaleform::Render::TextureFormat *__fastcall Scaleform::Render::TextureManager::precreateTexture(Scaleform::Render::TextureManager *this, Scaleform::Render::ImageFormat format, unsigned int use, Scaleform::Render::ImageBase *pimage)
{
  Scaleform::Render::ImageBase *v4; // rsi
  unsigned int v5; // ebx
  Scaleform::Render::ImageFormat v6; // edi
  Scaleform::Render::TextureManager *v7; // r14
  __int64 v9; // rsi

  v4 = pimage;
  v5 = use;
  v6 = format;
  v7 = this;
  if ( pimage )
  {
    if ( (format ^ ((unsigned int (__fastcall *)(Scaleform::Render::ImageBase *))pimage->vfptr[4].__vecDelDtor)(pimage)) & 0xFFF
      || !((unsigned int (__fastcall *)(Scaleform::Render::ImageBase *))v4->vfptr[3].__vecDelDtor)(v4)
      && !_bittest((const signed int *)&v5, 8u) )
    {
      return 0i64;
    }
  }
  else if ( !(use & 0x4F0) )
  {
    return 0i64;
  }
  v9 = (__int64)v7->vfptr[18].__vecDelDtor((Scaleform::RefCountImplCore *)&v7->vfptr, v6);
  if ( !v9
    || (v6 & 0xFFFu) - 50 <= 0xF && v5 & 0x4E2
    || v5 & 0xC0 && !(unsigned __int8)v7->vfptr[19].__vecDelDtor((Scaleform::RefCountImplCore *)&v7->vfptr, v9) )
  {
    return 0i64;
  }
  return (Scaleform::Render::TextureFormat *)v9;
}

// File Line: 1570
// RVA: 0x9EC0B0
Scaleform::Render::Texture *__fastcall Scaleform::Render::TextureManager::postCreateTexture(Scaleform::Render::TextureManager *this, Scaleform::Render::Texture *ptexture, unsigned int use)
{
  unsigned int v3; // ebp
  Scaleform::Render::Texture *v4; // rdi
  Scaleform::Render::TextureManager *v5; // rsi
  Scaleform::Mutex *v7; // rbx
  Scaleform::Render::Texture *v8; // rsi
  Scaleform::Render::ImageBase *v9; // rcx
  Scaleform::Mutex *v10; // [rsp+48h] [rbp+10h]

  v3 = use;
  v4 = ptexture;
  v5 = this;
  if ( !ptexture )
    return 0i64;
  if ( !((unsigned __int8 (__fastcall *)(Scaleform::Render::Texture *))ptexture->vfptr[2].__vecDelDtor)(ptexture) )
  {
    if ( !_InterlockedDecrement(&v4->RefCount) )
      v4->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v4->vfptr, 1u);
    return 0i64;
  }
  v7 = &v5->pLocks.pObject->TextureMutex;
  v10 = &v5->pLocks.pObject->TextureMutex;
  Scaleform::Mutex::DoLock(v7);
  if ( ((unsigned __int8 (__fastcall *)(Scaleform::Render::TextureManager *))v5->vfptr[7].__vecDelDtor)(v5) )
  {
    ((void (__fastcall *)(Scaleform::Render::TextureManager *))v5->vfptr[16].__vecDelDtor)(v5);
    ((void (__fastcall *)(Scaleform::Render::TextureManager *))v5->vfptr[17].__vecDelDtor)(v5);
    if ( ((unsigned __int8 (__fastcall *)(Scaleform::Render::Texture *))v4->vfptr[1].__vecDelDtor)(v4) )
    {
      v4->pPrev = v5->Textures.Root.pPrev;
      v4->pNext = (Scaleform::Render::Texture *)&v5->TextureFormats.Data.Size;
      v5->Textures.Root.pPrev->pNext = v4;
      v5->Textures.Root.pPrev = v4;
    }
  }
  else
  {
    v4->pPrev = v5->TextureInitQueue.Root.pPrev;
    v4->pNext = (Scaleform::Render::Texture *)&v5->Textures;
    v5->TextureInitQueue.Root.pPrev->pNext = v4;
    v5->TextureInitQueue.Root.pPrev = v4;
    Scaleform::Mutex::Unlock(&v5->pLocks.pObject->TextureMutex);
    v5->pRTCommandQueue->vfptr->PushThreadCommand(
      v5->pRTCommandQueue,
      (Scaleform::Render::ThreadCommand *)&v5->ServiceCommandInstance.vfptr);
    Scaleform::Mutex::DoLock(&v5->pLocks.pObject->TextureMutex);
    while ( v4->State == State_PreCapture )
      Scaleform::WaitCondition::Wait(&v5->pLocks.pObject->TextureInitWC, &v5->pLocks.pObject->TextureMutex, 0xFFFFFFFF);
  }
  v8 = 0i64;
  if ( _bittest((const signed int *)&v3, 8u) )
  {
    v9 = v4->pImage;
    if ( v9 && ((unsigned int (__cdecl *)(Scaleform::Render::ImageBase *))v9->vfptr[3].__vecDelDtor)(v9) == 2 )
      Scaleform::Render::RawImage::freeData((Scaleform::Render::RawImage *)v4->pImage);
    v4->pImage = 0i64;
  }
  if ( v4->State == 1 )
  {
    v4->pImage = 0i64;
    if ( !_InterlockedDecrement(&v4->RefCount) )
      v4->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v4->vfptr, 1u);
    v7 = v10;
  }
  else
  {
    v8 = v4;
  }
  Scaleform::Mutex::Unlock(v7);
  return v8;
}

// File Line: 1628
// RVA: 0x9EBFA0
Scaleform::Render::DepthStencilSurface *__fastcall Scaleform::Render::TextureManager::postCreateDepthStencilSurface(Scaleform::Render::TextureManager *this, Scaleform::Render::DepthStencilSurface *pdss)
{
  Scaleform::Render::DepthStencilSurface *v2; // rsi
  Scaleform::Render::TextureManager *v3; // rdi
  Scaleform::Mutex *v5; // rbx

  v2 = pdss;
  v3 = this;
  if ( !pdss )
    return 0i64;
  v5 = &this->pLocks.pObject->TextureMutex;
  Scaleform::Mutex::DoLock(v5);
  if ( ((unsigned __int8 (__fastcall *)(Scaleform::Render::TextureManager *))v3->vfptr[7].__vecDelDtor)(v3) )
  {
    ((void (__fastcall *)(Scaleform::Render::TextureManager *))v3->vfptr[16].__vecDelDtor)(v3);
    ((void (__fastcall *)(Scaleform::Render::TextureManager *))v3->vfptr[17].__vecDelDtor)(v3);
    ((void (__fastcall *)(Scaleform::Render::DepthStencilSurface *))v2->vfptr[3].__vecDelDtor)(v2);
  }
  else
  {
    v2->pPrev = v3->DepthStencilInitQueue.Root.pPrev;
    v2->pNext = (Scaleform::Render::DepthStencilSurface *)&v3->TextureInitQueue;
    v3->DepthStencilInitQueue.Root.pPrev->pNext = v2;
    v3->DepthStencilInitQueue.Root.pPrev = v2;
    if ( v3->pRTCommandQueue )
    {
      Scaleform::Mutex::Unlock(&v3->pLocks.pObject->TextureMutex);
      v3->pRTCommandQueue->vfptr->PushThreadCommand(
        v3->pRTCommandQueue,
        (Scaleform::Render::ThreadCommand *)&v3->ServiceCommandInstance.vfptr);
      Scaleform::Mutex::DoLock(&v3->pLocks.pObject->TextureMutex);
    }
    while ( v2->State == State_PreCapture )
      Scaleform::WaitCondition::Wait(&v3->pLocks.pObject->TextureInitWC, &v3->pLocks.pObject->TextureMutex, 0xFFFFFFFF);
  }
  Scaleform::Mutex::Unlock(v5);
  return v2;
}

// File Line: 1656
// RVA: 0x9E78B0
Scaleform::Render::TextureFormat *__fastcall Scaleform::Render::TextureManager::getTextureFormat(Scaleform::Render::TextureManager *this, Scaleform::Render::ImageFormat format)
{
  unsigned int v2; // ebx
  Scaleform::Render::ImageFormat v3; // esi
  Scaleform::Render::TextureManager *v4; // rdi
  __int64 v5; // r8
  Scaleform::Render::TextureFormat *v6; // rcx

  v2 = 0;
  v3 = format;
  v4 = this;
  if ( !this->TextureFormats.Data.Size )
    return 0i64;
  v5 = 0i64;
  while ( 1 )
  {
    v6 = v4->TextureFormats.Data.Data[v5];
    if ( v6 )
    {
      if ( ((unsigned int (*)(void))v6->vfptr->GetImageFormat)() == v3 )
        break;
    }
    v5 = ++v2;
    if ( v2 >= v4->TextureFormats.Data.Size )
      return 0i64;
  }
  return v4->TextureFormats.Data.Data[v2];
}

// File Line: 1666
// RVA: 0x9E96E0
Scaleform::Render::MappedTextureBase *__fastcall Scaleform::Render::TextureManager::mapTexture(Scaleform::Render::TextureManager *this, Scaleform::Render::Texture *ptexture, unsigned int mipLevel, unsigned int levelCount)
{
  unsigned int v4; // esi
  unsigned int v5; // ebp
  Scaleform::Render::Texture *v6; // r14
  Scaleform::Render::TextureManager *v7; // rbx
  __int64 v8; // rdi
  __int64 v9; // rbx

  v4 = levelCount;
  v5 = mipLevel;
  v6 = ptexture;
  v7 = this;
  v8 = ((__int64 (*)(void))this->vfptr[23].__vecDelDtor)();
  _InterlockedCompareExchange((volatile signed __int32 *)(v8 + 20), -1, 0);
  if ( *(_DWORD *)(v8 + 20) == -1 )
  {
    v9 = v8;
  }
  else
  {
    v9 = ((__int64 (__fastcall *)(Scaleform::Render::TextureManager *))v7->vfptr[24].__vecDelDtor)(v7);
    if ( !v9 )
      return 0i64;
  }
  if ( (*(unsigned __int8 (__fastcall **)(__int64, Scaleform::Render::Texture *, _QWORD, _QWORD))(*(_QWORD *)v9 + 8i64))(
         v9,
         v6,
         v5,
         v4) )
  {
    return (Scaleform::Render::MappedTextureBase *)v9;
  }
  if ( v9 != v8 )
    (**(void (__fastcall ***)(__int64, signed __int64))v9)(v9, 1i64);
  return 0i64;
}

// File Line: 1686
// RVA: 0x9F8880
void __fastcall Scaleform::Render::TextureManager::unmapTexture(Scaleform::Render::TextureManager *this, Scaleform::Render::Texture *ptexture, bool applyUpdate)
{
  Scaleform::Render::MappedTextureBase *v3; // rdi
  Scaleform::Render::TextureManager *v4; // rbx

  v3 = ptexture->pMap;
  v4 = this;
  v3->vfptr->Unmap(v3, applyUpdate);
  if ( v3 != (Scaleform::Render::MappedTextureBase *)((__int64 (__fastcall *)(Scaleform::Render::TextureManager *))v4->vfptr[23].__vecDelDtor)(v4) )
    v3->vfptr->__vecDelDtor(v3, 1u);
}

// File Line: 1696
// RVA: 0x9874E0
Scaleform::Render::ImageSwizzler *__fastcall Scaleform::Render::TextureManager::GetImageSwizzler(Scaleform::Render::TextureManager *this)
{
  if ( !(_S6_9 & 1) )
  {
    _S6_9 |= 1u;
    swizzler.vfptr = (Scaleform::Render::ImageSwizzlerVtbl *)&Scaleform::Render::ImageSwizzler::`vftable';
    atexit(Scaleform::Render::TextureManager::GetImageSwizzler_::_2_::_dynamic_atexit_destructor_for__swizzler__);
  }
  return &swizzler;
}

// File Line: 1704
// RVA: 0x9943A0
char __fastcall Scaleform::Render::Texture::Initialize(Scaleform::Render::Texture *this)
{
  Scaleform::Render::TextureManagerLocks *v1; // r8
  Scaleform::RefCountImplCoreVtbl *v2; // r8

  v1 = this->pManagerLocks.pObject;
  if ( v1 )
    v1 = (Scaleform::Render::TextureManagerLocks *)v1->pManager;
  v2 = v1->TextureMutex.vfptr;
  if ( this->State == 2 && v2 )
    (*((void (__fastcall **)(Scaleform::RefCountImplCoreVtbl *, Scaleform::Render::Texture *))v2->__vecDelDtor + 3))(
      v2,
      this);
  return 1;
}

// File Line: 1712
// RVA: 0x998CF0
void __fastcall Scaleform::Render::Texture::LoseManager(Scaleform::Render::Texture *this)
{
  Scaleform::Render::Texture *v1; // rdi
  _RTL_CRITICAL_SECTION *v2; // rbx
  Scaleform::Render::Texture *v3; // rdx
  Scaleform::Render::ImageBase *v4; // rcx

  v1 = this;
  v2 = &this->pManagerLocks.pObject->ImageLock.cs;
  EnterCriticalSection(v2);
  v1->pPrev->pNext = v1->pNext;
  v3 = v1->pNext;
  v3->pPrev = v1->pPrev;
  v1->pNext = (Scaleform::Render::Texture *)-1i64;
  v1->pPrev = 0i64;
  v1->pNext = 0i64;
  LOBYTE(v3) = 1;
  v1->vfptr[11].__vecDelDtor((Scaleform::RefCountImplCore *)&v1->vfptr, (unsigned int)v3);
  v1->State = 4;
  v1->pFormat = 0i64;
  v4 = v1->pImage;
  if ( v4 )
  {
    v1->pImage = 0i64;
    v4->vfptr[24].__vecDelDtor((Scaleform::RefCountImplCore *)&v4->vfptr, 0);
  }
  LeaveCriticalSection(v2);
}

// File Line: 1737
// RVA: 0x998DA0
void __fastcall Scaleform::Render::Texture::LoseTextureData(Scaleform::Render::Texture *this)
{
  Scaleform::Render::Texture *v1; // rdi
  Scaleform::Render::ImageBase *v2; // rcx
  _RTL_CRITICAL_SECTION *v3; // rbx
  Scaleform::Render::ImageBase *v4; // rcx

  v1 = this;
  v2 = this->pImage;
  if ( v2 && ((unsigned int (__cdecl *)(Scaleform::Render::ImageBase *))v2->vfptr[3].__vecDelDtor)(v2) == 6 )
    Scaleform::Render::DrawableImage::unmapTextureRT((Scaleform::Render::DrawableImage *)v1->pImage);
  v3 = &v1->pManagerLocks.pObject->ImageLock.cs;
  EnterCriticalSection(v3);
  v1->vfptr[11].__vecDelDtor((Scaleform::RefCountImplCore *)&v1->vfptr, 0);
  v1->State = 3;
  v4 = v1->pImage;
  if ( v4 )
    v4->vfptr[24].__vecDelDtor((Scaleform::RefCountImplCore *)&v4->vfptr, 1u);
  LeaveCriticalSection(v3);
}

// File Line: 1763
// RVA: 0x9A7E80
void __fastcall Scaleform::Render::Texture::ReleaseHWTextures(Scaleform::Render::Texture *this, bool __formal)
{
  Scaleform::Render::Texture *v2; // rdx
  Scaleform::Render::TextureManagerLocks *v3; // rcx
  Scaleform::RefCountImplCoreVtbl *v4; // rcx

  v2 = this;
  v3 = this->pManagerLocks.pObject;
  if ( v3 )
    v3 = (Scaleform::Render::TextureManagerLocks *)v3->pManager;
  v4 = v3->TextureMutex.vfptr;
  if ( v4 )
    (*((void (__fastcall **)(Scaleform::RefCountImplCoreVtbl *, Scaleform::Render::Texture *))v4->__vecDelDtor + 6))(
      v4,
      v2);
}

// File Line: 1772
// RVA: 0x95A060
void __fastcall Scaleform::Render::Texture::ApplyTexture(Scaleform::Render::Texture *this, __int64 stage, Scaleform::Render::ImageFillMode *fillMode)
{
  Scaleform::Render::Texture *v3; // rbx
  Scaleform::Render::TextureManagerLocks *v4; // rax
  Scaleform::Render::TextureManager *v5; // rcx
  Scaleform::Render::TextureCache *v6; // rcx

  v3 = this;
  if ( this->State == 3 )
    ((void (__fastcall *)(Scaleform::Render::Texture *, __int64, Scaleform::Render::ImageFillMode *))this->vfptr[1].__vecDelDtor)(
      this,
      stage,
      fillMode);
  v4 = v3->pManagerLocks.pObject;
  if ( v4 )
    v5 = v4->pManager;
  else
    v5 = 0i64;
  v6 = v5->pTextureCache.pObject;
  if ( v6 )
    ((void (__fastcall *)(Scaleform::Render::TextureCache *, Scaleform::Render::Texture *, Scaleform::Render::ImageFillMode *))v6->vfptr[5].__vecDelDtor)(
      v6,
      v3,
      fillMode);
}

// File Line: 1786
// RVA: 0x9992A0
bool __fastcall Scaleform::Render::Texture::Map(Scaleform::Render::Texture *this, Scaleform::Render::ImageData *pdata, __int64 mipLevel, unsigned int levelCount)
{
  unsigned int v4; // ebp
  Scaleform::Render::ImageData *v5; // rdi
  Scaleform::Render::Texture *v6; // rsi
  Scaleform::Render::TextureManagerLocks *v7; // rax
  Scaleform::Render::TextureManager *v8; // rcx
  __int64 v9; // rax
  Scaleform::Render::MappedTextureBase *v10; // rax
  Scaleform::Render::ImagePlane *v11; // r14
  int v12; // er15
  Scaleform::Render::ImageFormat v13; // ebx

  v4 = levelCount;
  v5 = pdata;
  v6 = this;
  if ( !levelCount )
    v4 = (unsigned __int8)this->MipLevels - (_DWORD)mipLevel;
  v7 = this->pManagerLocks.pObject;
  if ( v7 )
    v8 = v7->pManager;
  else
    v8 = 0i64;
  v9 = ((__int64 (__fastcall *)(Scaleform::Render::TextureManager *, Scaleform::Render::Texture *, __int64, _QWORD))v8->vfptr[21].__vecDelDtor)(
         v8,
         v6,
         mipLevel,
         v4);
  if ( v9 )
  {
    v10 = v6->pMap;
    v11 = v10->Data.pPlanes;
    v12 = v10->Data.RawPlaneCount;
    v13 = ((unsigned int (__fastcall *)(Scaleform::Render::Texture *))v6->vfptr[5].__vecDelDtor)(v6);
    Scaleform::Render::ImageData::Clear(v5);
    v5->Flags |= 1u;
    v5->Format = v13;
    v5->LevelCount = v4;
    v5->pPlanes = v11;
    v5->RawPlaneCount = v12;
    if ( v11 && v12 == 1 )
    {
      v5->Plane0.Width = v11->Width;
      v5->Plane0.Height = v11->Height;
      v5->Plane0.Pitch = v11->Pitch;
      v5->Plane0.DataSize = v11->DataSize;
      v5->Plane0.pData = v11->pData;
    }
    v5->Use = v6->Use;
    LOBYTE(v9) = 1;
  }
  return v9;
}

// File Line: 1806
// RVA: 0x9BB640
char __fastcall Scaleform::Render::Texture::Unmap(Scaleform::Render::Texture *this, __int64 a2, __int64 a3)
{
  Scaleform::Render::TextureManagerLocks *v4; // rax
  Scaleform::Render::TextureManager *v5; // r9

  if ( !this->pMap )
    return 0;
  v4 = this->pManagerLocks.pObject;
  if ( v4 )
    v5 = v4->pManager;
  else
    v5 = 0i64;
  LOBYTE(a3) = 1;
  ((void (__fastcall *)(Scaleform::Render::TextureManager *, Scaleform::Render::Texture *, __int64))v5->vfptr[22].__vecDelDtor)(
    v5,
    this,
    a3);
  return 1;
}

// File Line: 1856
// RVA: 0x9BC210
__int64 __fastcall Scaleform::Render::Texture::Update(Scaleform::Render::Texture *this)
{
  Scaleform::Render::Texture *v1; // r13
  Scaleform::Render::ImageFormat v2; // esi
  Scaleform::Render::TextureManagerLocks *v3; // rcx
  unsigned __int8 v4; // r12
  unsigned __int8 v5; // r15
  unsigned __int8 v6; // r12
  Scaleform::Render::ImageData *v7; // r14
  __int64 v8; // rdi
  __int64 v9; // rbx
  _RTL_CRITICAL_SECTION *v10; // rsi
  Scaleform::Render::ImageBase *v11; // rcx
  __int64 v12; // rax
  Scaleform::Render::ImageData *v13; // rax
  Scaleform::Render::RawImage *v14; // rax
  void (__fastcall *v15)(char *, const char *, unsigned __int64, Scaleform::Render::Palette *); // rax
  unsigned __int8 v16; // r14
  Scaleform::Render::Size<unsigned long> *v17; // rax
  Scaleform::Render::RawImage *v18; // rax
  Scaleform::Render::ResizeImageType v19; // eax
  Scaleform::Render::ImageData *v20; // r15
  unsigned __int64 v21; // r8
  __int64 v22; // r9
  Scaleform::Render::Size<unsigned long> *v23; // rax
  Scaleform::Render::RawImage *v24; // r14
  void (__fastcall *v25)(char *, const char *, unsigned __int64, Scaleform::Render::Palette *, void *); // rax
  unsigned int v26; // er14
  unsigned int v27; // eax
  unsigned int v28; // ecx
  signed __int64 v29; // rax
  unsigned int v30; // ecx
  unsigned int v31; // edx
  unsigned __int64 v32; // r8
  unsigned __int64 v33; // r9
  char *v34; // r10
  unsigned int v35; // ecx
  signed __int64 v36; // rax
  unsigned int v37; // ebx
  unsigned int v38; // esi
  unsigned __int64 v39; // r12
  char *v40; // rcx
  unsigned int v41; // edx
  Scaleform::Render::MappedTextureBase *v42; // r8
  signed int v43; // eax
  unsigned int v44; // eax
  unsigned int v45; // ecx
  signed __int64 v46; // r14
  unsigned int v47; // edi
  unsigned int v48; // eax
  __int64 v49; // r15
  char *v50; // r14
  char *v51; // rdi
  __int64 v52; // rax
  unsigned __int64 v53; // r15
  char *v54; // r12
  unsigned __int64 v55; // r13
  __int64 v56; // rsi
  __int64 v57; // rdi
  __int64 v58; // rbx
  Scaleform::Render::ImageFormat fmt; // [rsp+40h] [rbp-C0h]
  Scaleform::Render::ImageData *src; // [rsp+48h] [rbp-B8h]
  Scaleform::Render::TextureManager *v62; // [rsp+50h] [rbp-B0h]
  Scaleform::Render::ImageFormat format; // [rsp+58h] [rbp-A8h]
  unsigned int v64; // [rsp+5Ch] [rbp-A4h]
  Scaleform::Render::ResizeImageType resizeType; // [rsp+60h] [rbp-A0h]
  Scaleform::Render::ImagePlane splane; // [rsp+68h] [rbp-98h]
  unsigned int v67; // [rsp+88h] [rbp-78h]
  unsigned __int64 v68; // [rsp+90h] [rbp-70h]
  __int64 v69; // [rsp+98h] [rbp-68h]
  Scaleform::Render::ImagePlane dplane; // [rsp+A0h] [rbp-60h]
  Scaleform::Render::RawImage *v71; // [rsp+C0h] [rbp-40h]
  Scaleform::Render::ImagePlane p; // [rsp+C8h] [rbp-38h]
  int v73; // [rsp+E8h] [rbp-18h]
  __int64 v74; // [rsp+F0h] [rbp-10h]
  char *v75; // [rsp+F8h] [rbp-8h]
  __int64 v76; // [rsp+100h] [rbp+0h]
  Scaleform::Render::RawImage *v77; // [rsp+108h] [rbp+8h]
  Scaleform::Render::ImageData v78; // [rsp+110h] [rbp+10h]
  Scaleform::Render::ImageData v79; // [rsp+150h] [rbp+50h]
  unsigned __int64 v80; // [rsp+190h] [rbp+90h]
  unsigned __int64 v81; // [rsp+198h] [rbp+98h]
  unsigned __int64 v82; // [rsp+1A0h] [rbp+A0h]
  char *v83; // [rsp+1A8h] [rbp+A8h]
  __int64 v84; // [rsp+1B0h] [rbp+B0h]
  unsigned __int64 v85; // [rsp+1B8h] [rbp+B8h]
  unsigned int v86; // [rsp+1C0h] [rbp+C0h]
  Scaleform::Render::Palette *v87; // [rsp+1C8h] [rbp+C8h]
  _RTL_CRITICAL_SECTION *v88; // [rsp+1D0h] [rbp+D0h]
  void (__fastcall *v89)(char *, char *, unsigned __int64, __int64, _QWORD); // [rsp+1D8h] [rbp+D8h]
  Scaleform::Render::ImagePlane v90; // [rsp+1E0h] [rbp+E0h]
  char v91; // [rsp+200h] [rbp+100h]
  char v92; // [rsp+208h] [rbp+108h]
  __int64 v93; // [rsp+210h] [rbp+110h]
  Scaleform::Render::Texture *v94; // [rsp+270h] [rbp+170h]
  char v95; // [rsp+278h] [rbp+178h]
  unsigned int v96; // [rsp+280h] [rbp+180h]
  unsigned int mipLevelCount; // [rsp+288h] [rbp+188h]

  v94 = this;
  v93 = -2i64;
  v1 = this;
  v2 = ((unsigned int (*)(void))this->vfptr[5].__vecDelDtor)();
  fmt = v2;
  v3 = v1->pManagerLocks.pObject;
  if ( v3 )
    v62 = v3->pManager;
  else
    v62 = 0i64;
  v4 = v1->TextureFlags;
  v5 = v4 & 1;
  v6 = (v4 >> 1) & 1;
  v95 = 0;
  v7 = 0i64;
  *(_QWORD *)&v78.Format = 0i64;
  *(_DWORD *)&v78.Flags = 0x10000;
  v78.pPlanes = &v78.Plane0;
  v78.pPalette.pObject = 0i64;
  *(_QWORD *)&v78.Plane0.Width = 0i64;
  v78.Plane0.Pitch = 0i64;
  v78.Plane0.DataSize = 0i64;
  v78.Plane0.pData = 0i64;
  *(_QWORD *)&v79.Format = 0i64;
  *(_DWORD *)&v79.Flags = 0x10000;
  v79.pPlanes = &v79.Plane0;
  v79.pPalette.pObject = 0i64;
  *(_QWORD *)&v79.Plane0.Width = 0i64;
  v79.Plane0.Pitch = 0i64;
  v79.Plane0.DataSize = 0i64;
  v79.Plane0.pData = 0i64;
  v8 = 0i64;
  v77 = 0i64;
  v9 = 0i64;
  v71 = 0i64;
  if ( v1->Use & 2 )
    mipLevelCount = 1;
  else
    mipLevelCount = (unsigned __int8)v1->MipLevels;
  format = (unsigned int)v1->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)&v1->vfptr, 0);
  resizeType = 0;
  ((void (__fastcall *)(Scaleform::Render::Texture *, _QWORD, _QWORD, _QWORD, Scaleform::Render::ResizeImageType *, Scaleform::Render::ImageFormat *, char *))v1->vfptr[20].__vecDelDtor)(
    v1,
    v5,
    v6,
    (unsigned int)v2,
    &resizeType,
    &format,
    &v95);
  v10 = &v1->pManagerLocks.pObject->ImageLock.cs;
  v88 = v10;
  EnterCriticalSection(v10);
  v11 = v1->pImage;
  if ( !v11 || v1->TextureFlags & 4 )
    goto LABEL_99;
  if ( ((unsigned int (*)(void))v11->vfptr[3].__vecDelDtor)() != 2 )
  {
    if ( v5 )
      goto LABEL_17;
    goto LABEL_13;
  }
  if ( !v5 )
  {
LABEL_13:
    if ( !v95
      && (unsigned __int8)v62->vfptr[19].__vecDelDtor(
                            (Scaleform::RefCountImplCore *)&v62->vfptr,
                            (unsigned int)v1->pFormat)
      && (__int64)v62->vfptr[20].__vecDelDtor((Scaleform::RefCountImplCore *)&v62->vfptr, (unsigned int)v1) )
    {
      v13 = &v1->pMap->Data;
LABEL_19:
      src = v13;
      if ( v95 )
        v15 = Scaleform::Render::ImageBase::CopyScanlineDefault;
      else
        v15 = (void (__fastcall *)(char *, const char *, unsigned __int64, Scaleform::Render::Palette *))((__int64 (*)(void))v1->pFormat->vfptr->GetScanlineCopyFn)();
      if ( !((unsigned __int8 (__fastcall *)(Scaleform::Render::ImageBase *, Scaleform::Render::ImageData *, _QWORD, _QWORD))v1->pImage->vfptr[8].__vecDelDtor)(
              v1->pImage,
              src,
              v15,
              0i64) )
      {
        if ( src == &v1->pMap->Data )
        {
          ((void (__fastcall *)(Scaleform::Render::TextureManager *, Scaleform::Render::Texture *, _QWORD))v62->vfptr[22].__vecDelDtor)(
            v62,
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
    v13 = &v78;
    goto LABEL_19;
  }
  v12 = ((__int64 (*)(void))v1->pImage->vfptr[9].__vecDelDtor)();
  Scaleform::Render::ImageData::operator=(&v78, (Scaleform::Render::ImageData *)(v12 + 40));
  src = &v78;
LABEL_25:
  if ( v5 )
  {
    if ( !v95
      && (unsigned __int8)v62->vfptr[19].__vecDelDtor(
                            (Scaleform::RefCountImplCore *)&v62->vfptr,
                            (unsigned int)v1->pFormat)
      && (__int64)v62->vfptr[20].__vecDelDtor((Scaleform::RefCountImplCore *)&v62->vfptr, (unsigned int)v1) )
    {
      v7 = &v1->pMap->Data;
    }
    else
    {
      v17 = (Scaleform::Render::Size<unsigned long> *)((__int64 (__fastcall *)(Scaleform::Render::Texture *, char *, _QWORD))v1->vfptr[6].__vecDelDtor)(
                                                        v1,
                                                        &v92,
                                                        0i64);
      v18 = Scaleform::Render::RawImage::Create(format, mipLevelCount, v17, 0, 0i64, 0i64);
      v9 = (__int64)v18;
      v71 = v18;
      if ( !v18 )
        goto LABEL_99;
      Scaleform::Render::ImageData::operator=(&v79, &v18->Data);
      v7 = &v79;
    }
    v19 = resizeType;
    if ( resizeType == ResizeNone )
    {
      v19 = (unsigned int)Scaleform::Render::GetImageFormatRescaleType(fmt);
      resizeType = v19;
    }
    Scaleform::Render::RescaleImageData(v7, src, v19);
    v20 = v7;
    src = v7;
  }
  else
  {
    v20 = src;
  }
  v73 = fmt & 0xFFF;
  if ( fmt & 0xFFF )
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
    && (unsigned __int8)v62->vfptr[19].__vecDelDtor(
                          (Scaleform::RefCountImplCore *)&v62->vfptr,
                          (unsigned int)v1->pFormat) )
  {
    goto LABEL_60;
  }
  if ( !(unsigned __int8)v62->vfptr[19].__vecDelDtor(
                           (Scaleform::RefCountImplCore *)&v62->vfptr,
                           (unsigned int)v1->pFormat) )
  {
    v26 = 0;
    v27 = v96;
    if ( v96 )
    {
      do
      {
        *(_QWORD *)&p.Width = 0i64;
        p.Pitch = 0i64;
        p.DataSize = 0i64;
        p.pData = 0i64;
        v80 = 0i64;
        v81 = 0i64;
        v82 = 0i64;
        v83 = 0i64;
        v84 = 0i64;
        v85 = 0i64;
        v28 = v20->RawPlaneCount;
        if ( v26 >= v28 )
        {
          Scaleform::Render::ImagePlane::GetMipLevel(&v20->pPlanes[v26 % v28], v20->Format, v26 / v28, &p, v26 % v28);
          v34 = p.pData;
          v33 = p.DataSize;
          v32 = p.Pitch;
          v31 = p.Height;
          v30 = p.Width;
        }
        else
        {
          v29 = (signed __int64)&v20->pPlanes[v26];
          v30 = *(_DWORD *)v29;
          p.Width = *(_DWORD *)v29;
          v31 = *(_DWORD *)(v29 + 4);
          p.Height = *(_DWORD *)(v29 + 4);
          v32 = *(_QWORD *)(v29 + 8);
          p.Pitch = *(_QWORD *)(v29 + 8);
          v33 = *(_QWORD *)(v29 + 16);
          p.DataSize = *(_QWORD *)(v29 + 16);
          v34 = *(char **)(v29 + 24);
          p.pData = *(char **)(v29 + 24);
        }
        v80 = __PAIR__(v31, v30);
        v81 = v32;
        v82 = v33;
        v83 = v34;
        v84 = 0i64;
        v85 = __PAIR__(v31, v30);
        v86 = v26;
        ((void (__fastcall *)(Scaleform::Render::Texture *, unsigned __int64 *, signed __int64))v1->vfptr[18].__vecDelDtor)(
          v1,
          &v80,
          1i64);
        ++v26;
        v27 = v96;
      }
      while ( v26 < v96 );
    }
    goto LABEL_61;
  }
  if ( v62->vfptr[20].__vecDelDtor((Scaleform::RefCountImplCore *)&v62->vfptr, (unsigned int)v1) )
  {
    v7 = &v1->pMap->Data;
LABEL_53:
    v25 = (void (__fastcall *)(char *, const char *, unsigned __int64, Scaleform::Render::Palette *, void *))((__int64 (*)(void))v1->pFormat->vfptr->GetScanlineCopyFn)();
    Scaleform::Render::ConvertImageData(v7, v20, v25, 0i64);
LABEL_60:
    v27 = v96;
LABEL_61:
    if ( v6 )
    {
      v22 = 0i64;
      mipLevelCount = 0;
      if ( v27 )
      {
        do
        {
          *(_QWORD *)&splane.Width = 0i64;
          splane.Pitch = 0i64;
          splane.DataSize = 0i64;
          splane.pData = 0i64;
          *(_QWORD *)&dplane.Width = 0i64;
          dplane.Pitch = 0i64;
          dplane.DataSize = 0i64;
          dplane.pData = 0i64;
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
            v36 = (signed __int64)&v20->pPlanes[(unsigned int)v22];
            v37 = *(_DWORD *)v36;
            splane.Width = *(_DWORD *)v36;
            v38 = *(_DWORD *)(v36 + 4);
            splane.Height = *(_DWORD *)(v36 + 4);
            v39 = *(_QWORD *)(v36 + 8);
            splane.Pitch = *(_QWORD *)(v36 + 8);
            v21 = *(_QWORD *)(v36 + 16);
            v74 = v21;
            splane.DataSize = v21;
            v40 = *(char **)(v36 + 24);
            splane.pData = *(char **)(v36 + 24);
          }
          v68 = v39;
          v75 = v40;
          v41 = 1;
          v67 = 1;
          if ( v1->MipLevels > 1u )
          {
            do
            {
              v42 = v1->pMap;
              if ( v42->Data.Format & 0xFFF )
              {
                if ( (v42->Data.Format & 0xFFF) == 200 )
                {
                  v43 = 3;
                }
                else if ( (v42->Data.Format & 0xFFF) == 201 )
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
              v45 = v42->Data.RawPlaneCount;
              if ( v44 >= v45 )
              {
                Scaleform::Render::ImagePlane::GetMipLevel(
                  &v42->Data.pPlanes[v44 % v45],
                  v42->Data.Format,
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
                v46 = (signed __int64)&v42->Data.pPlanes[v44];
                v47 = *(_DWORD *)v46;
                dplane.Width = *(_DWORD *)v46;
                v48 = *(_DWORD *)(v46 + 4);
                dplane.Height = *(_DWORD *)(v46 + 4);
                v49 = *(_QWORD *)(v46 + 8);
                dplane.Pitch = *(_QWORD *)(v46 + 8);
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
                if ( v37 < 1 )
                  v37 = 1;
                LODWORD(v69) = v37;
                v90.Width = v37;
                v38 >>= 1;
                if ( v38 < 1 )
                  v38 = 1;
                v64 = v38;
                v90.Height = v38;
                Scaleform::Render::GenerateMipLevel(&v90, &splane, fmt, v22);
                v87 = src->pPalette.pObject;
                v89 = (void (__fastcall *)(char *, char *, unsigned __int64, __int64, _QWORD))((__int64 (*)(void))v1->pFormat->vfptr->GetScanlineCopyFn)();
                v52 = (unsigned int)Scaleform::Render::ImageData::GetFormatBitsPerPixel(fmt, mipLevelCount);
                if ( (unsigned int)(v73 - 50) > 3 )
                  v53 = v38;
                else
                  v53 = (unsigned __int64)(v38 + 3) >> 2;
                v54 = v51;
                if ( v53 )
                {
                  v55 = v52 * (unsigned __int64)v37 >> 3;
                  v56 = v76;
                  v57 = v68;
                  v58 = (__int64)v87;
                  do
                  {
                    v89(v50, v54, v55, v58, 0i64);
                    v54 += v57;
                    v50 += v56;
                    --v53;
                  }
                  while ( v53 );
                  v38 = v64;
                  v1 = v94;
                  v37 = v69;
                }
                v39 = v68;
              }
              else
              {
                Scaleform::Render::GenerateMipLevel(&dplane, &splane, fmt, v22);
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
        v10 = v88;
      }
    }
    if ( v20 == &v1->pMap->Data )
    {
      LOBYTE(v21) = 1;
      ((void (__fastcall *)(Scaleform::Render::TextureManager *, Scaleform::Render::Texture *, unsigned __int64, __int64))v62->vfptr[22].__vecDelDtor)(
        v62,
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
                                                    &v91,
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
  LeaveCriticalSection(v10);
  if ( v9 )
    (*(void (__fastcall **)(__int64))(*(_QWORD *)v9 + 16i64))(v9);
  if ( v8 )
    (*(void (__fastcall **)(__int64))(*(_QWORD *)v8 + 16i64))(v8);
  if ( v79.Flags & 2 )
  {
    v79.Flags &= 0xFDu;
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v79.pPlanes);
  }
  v79.pPlanes = &v79.Plane0;
  if ( v79.pPalette.pObject && !_InterlockedDecrement(&v79.pPalette.pObject->RefCount.Value) )
    ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
  if ( v78.Flags & 2 )
  {
    v78.Flags &= 0xFDu;
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v78.pPlanes);
  }
  v78.pPlanes = &v78.Plane0;
  if ( v78.pPalette.pObject && !_InterlockedDecrement(&v78.pPalette.pObject->RefCount.Value) )
    ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
  return v16;
}

// File Line: 2038
// RVA: 0x980980
unsigned __int64 __fastcall Scaleform::Render::Texture::GetBytes(Scaleform::Render::Texture *this, int *memRegion)
{
  unsigned int v2; // ebx
  __int64 v3; // rdi
  Scaleform::Render::ImageFormat v4; // er9
  int v5; // ecx
  unsigned int v6; // eax
  unsigned int v7; // ecx
  unsigned __int64 result; // rax
  unsigned int v9; // eax
  unsigned int v10; // ecx

  if ( memRegion )
    *memRegion = 1;
  v2 = this->ImgSize.Width;
  v3 = this->ImgSize.Height;
  v4 = ((unsigned int (*)(void))this->vfptr[4].__vecDelDtor)();
  v5 = v4 & 0xFFF;
  if ( v5 == 50 )
  {
    v6 = (v2 + 3) >> 2;
    v7 = (unsigned int)(v3 + 3) >> 2;
    if ( v7 < 1 )
      v7 = 1;
    if ( v6 < 1 )
      v6 = 1;
    result = 8 * v7 * v6;
  }
  else if ( (unsigned int)(v5 - 51) <= 2 || (unsigned int)(v5 - 64) <= 1 )
  {
    v9 = (v2 + 3) >> 2;
    v10 = (unsigned int)(v3 + 3) >> 2;
    if ( v10 < 1 )
      v10 = 1;
    if ( v9 < 1 )
      v9 = 1;
    result = 16 * v10 * v9;
  }
  else
  {
    result = v3 * Scaleform::Render::ImageData::GetFormatPitch(v4, v2, 0);
  }
  return result;
}

