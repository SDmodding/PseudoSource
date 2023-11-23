// File Line: 49
// RVA: 0x77B4E0
void __fastcall Scaleform::GFx::AS3::Classes::fl_display::BlendMode::BlendMode(
        Scaleform::GFx::AS3::Classes::fl_display::BlendMode *this,
        Scaleform::GFx::AS3::ClassTraits::Traits *t)
{
  Scaleform::GFx::AS3::Class::Class(this, t);
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Classes::fl_display::BlendMode::`vftable;
  this->ADD = "add";
  this->ALPHA = "alpha";
  this->DARKEN = "darken";
  this->DIFFERENCE = "difference";
  this->ERASE = "erase";
  this->HARDLIGHT = "hardlight";
  this->INVERT = "invert";
  this->LAYER = "layer";
  this->LIGHTEN = "lighten";
  this->MULTIPLY = "multiply";
  this->NORMAL = "normal";
  this->OVERLAY = "overlay";
  this->SCREEN = "screen";
  this->SUBTRACT = "subtract";
}

// File Line: 55
// RVA: 0x7E6210
__int64 __fastcall Scaleform::GFx::AS3::Classes::fl_display::BlendMode::GetBlendMode(Scaleform::GFx::ASString *value)
{
  unsigned int v1; // esi
  const char *pData; // rdi
  __int64 v3; // rcx
  char v4; // al
  __int64 v6; // rcx
  char v7; // al
  __int64 v8; // rcx
  char v9; // al
  __int64 v10; // rcx
  char v11; // al
  __int64 v12; // rcx
  char v13; // al
  __int64 v14; // rcx
  char v15; // al
  __int64 v16; // rcx
  char v17; // al
  __int64 v18; // rcx
  char v19; // al
  __int64 v20; // rcx
  char v21; // al
  __int64 v22; // rcx
  char v23; // al

  v1 = 0;
  pData = value->pNode->pData;
  v3 = 0i64;
  while ( 1 )
  {
    v4 = pData[v3++];
    if ( v4 != aNormal_0[v3 - 1] )
      break;
    if ( v3 == 7 )
      return 1i64;
  }
  v6 = 0i64;
  while ( 1 )
  {
    v7 = pData[v6++];
    if ( v7 != aAdd_4[v6 - 1] )
      break;
    if ( v6 == 4 )
      return 8i64;
  }
  v8 = 0i64;
  while ( 1 )
  {
    v9 = pData[v8++];
    if ( v9 != aAlpha_0[v8 - 1] )
      break;
    if ( v8 == 6 )
      return 11i64;
  }
  if ( !strcmp(pData, "multiply") )
    return 3i64;
  if ( !strcmp(pData, "subtract") )
    return 9i64;
  v10 = 0i64;
  while ( 1 )
  {
    v11 = pData[v10++];
    if ( v11 != aLayer[v10 - 1] )
      break;
    if ( v10 == 6 )
      return 2i64;
  }
  v12 = 0i64;
  while ( 1 )
  {
    v13 = pData[v12++];
    if ( v13 != aScreen_0[v12 - 1] )
      break;
    if ( v12 == 7 )
      return 4i64;
  }
  v14 = 0i64;
  while ( 1 )
  {
    v15 = pData[v14++];
    if ( v15 != aLighten[v14 - 1] )
      break;
    if ( v14 == 8 )
      return 5i64;
  }
  v16 = 0i64;
  while ( 1 )
  {
    v17 = pData[v16++];
    if ( v17 != aDarken[v16 - 1] )
      break;
    if ( v16 == 7 )
      return 6i64;
  }
  if ( !strcmp(pData, "difference") )
    return 7i64;
  v18 = 0i64;
  while ( 1 )
  {
    v19 = pData[v18++];
    if ( v19 != aInvert[v18 - 1] )
      break;
    if ( v18 == 7 )
      return 10i64;
  }
  v20 = 0i64;
  while ( 1 )
  {
    v21 = pData[v20++];
    if ( v21 != aErase[v20 - 1] )
      break;
    if ( v20 == 6 )
      return 12i64;
  }
  v22 = 0i64;
  while ( 1 )
  {
    v23 = pData[v22++];
    if ( v23 != aOverlay[v22 - 1] )
      break;
    if ( v22 == 8 )
      return 13i64;
  }
  if ( !strcmp(pData, "hardlight") )
    return 14;
  return v1;
}

// File Line: 122
// RVA: 0x74CB00
Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *__fastcall Scaleform::GFx::AS3::ClassTraits::fl_display::BlendMode::MakeClassTraits(
        Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *result,
        Scaleform::GFx::AS3::VM *vm)
{
  Scaleform::MemoryHeap *MHeap; // rsi
  Scaleform::GFx::AS3::ClassTraits::Traits *v5; // rax
  Scaleform::GFx::AS3::ClassTraits::Traits *v6; // rdi
  Scaleform::GFx::AS3::InstanceTraits::CTraits *v7; // rax
  Scaleform::GFx::AS3::InstanceTraits::CTraits *v8; // rdi
  Scaleform::GFx::AS3::Classes::fl_display::BlendMode *v9; // rax

  MHeap = vm->MHeap;
  v5 = (Scaleform::GFx::AS3::ClassTraits::Traits *)MHeap->vfptr->Alloc(MHeap, 208ui64, 0i64);
  v6 = v5;
  if ( v5 )
  {
    Scaleform::GFx::AS3::ClassTraits::Traits::Traits(v5, vm, &Scaleform::GFx::AS3::fl_display::BlendModeCI);
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl::Object::`vftable;
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_display::BlendMode::`vftable;
  }
  else
  {
    v6 = 0i64;
  }
  result->pV = v6;
  v7 = (Scaleform::GFx::AS3::InstanceTraits::CTraits *)MHeap->vfptr->Alloc(MHeap, 240ui64, 0i64);
  v8 = v7;
  if ( v7 )
  {
    Scaleform::GFx::AS3::InstanceTraits::CTraits::CTraits(v7, vm, &Scaleform::GFx::AS3::fl_display::BlendModeCI);
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl::Object::`vftable;
  }
  else
  {
    v8 = 0i64;
  }
  Scaleform::GFx::AS3::ClassTraits::Traits::SetInstanceTraits(
    result->pV,
    (Scaleform::Pickable<Scaleform::GFx::AS3::InstanceTraits::Traits>)v8);
  v9 = (Scaleform::GFx::AS3::Classes::fl_display::BlendMode *)MHeap->vfptr->Alloc(MHeap, 184ui64, 0i64);
  if ( v9 )
    Scaleform::GFx::AS3::Classes::fl_display::BlendMode::BlendMode(v9, result->pV);
  return result;
}

