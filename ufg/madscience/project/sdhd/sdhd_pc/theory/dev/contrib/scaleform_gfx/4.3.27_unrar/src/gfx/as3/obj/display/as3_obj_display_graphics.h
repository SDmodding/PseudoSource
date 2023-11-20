// File Line: 175
// RVA: 0x82DAC0
void __fastcall Scaleform::GFx::AS3::Instances::fl_display::Graphics::beginBitmapFill(Scaleform::GFx::AS3::Instances::fl_display::Graphics *this, Scaleform::GFx::AS3::Instances::fl_display::BitmapData *bitmap, Scaleform::GFx::AS3::Instances::fl_geom::Matrix *matrix, bool repeat, bool smooth)
{
  bool v5; // bl
  Scaleform::GFx::AS3::Instances::fl_geom::Matrix *v6; // rdi
  Scaleform::GFx::AS3::Instances::fl_display::BitmapData *v7; // rsi
  Scaleform::GFx::AS3::Instances::fl_display::Graphics *v8; // rbp

  v5 = repeat;
  v6 = matrix;
  v7 = bitmap;
  v8 = this;
  if ( !(_S11_12 & 1) )
  {
    _S11_12 |= 1u;
    v.Flags = 0;
    v.Bonus.pWeakProxy = 0i64;
    atexit(Scaleform::GFx::AS3::Value::GetUndefined_::_2_::_dynamic_atexit_destructor_for__v__);
  }
  Scaleform::GFx::AS3::Instances::fl_display::Graphics::beginBitmapFill(v8, &v, v7, v6, v5, smooth);
}

// File Line: 179
// RVA: 0x82DBC0
void __fastcall Scaleform::GFx::AS3::Instances::fl_display::Graphics::beginFill(Scaleform::GFx::AS3::Instances::fl_display::Graphics *this, unsigned int color, long double alpha)
{
  unsigned int v3; // edi
  Scaleform::GFx::AS3::Instances::fl_display::Graphics *v4; // rbx

  v3 = color;
  v4 = this;
  if ( !(_S11_12 & 1) )
  {
    _S11_12 |= 1u;
    v.Flags = 0;
    v.Bonus.pWeakProxy = 0i64;
    atexit(Scaleform::GFx::AS3::Value::GetUndefined_::_2_::_dynamic_atexit_destructor_for__v__);
  }
  _((AMD_HD3D *)v4->pDispObj);
  Scaleform::GFx::DisplayObjectBase::InvalidateHitResult((Scaleform::GFx::DisplayObjectBase *)&v4->pDispObj->vfptr);
  Scaleform::GFx::DrawingContext::AcquirePath(v4->pDrawing.pObject, 1);
  Scaleform::GFx::DrawingContext::BeginSolidFill(v4->pDrawing.pObject, v3 | ((signed int)(alpha * 255.0) << 24));
}

// File Line: 187
// RVA: 0x8332C0
void __fastcall Scaleform::GFx::AS3::Instances::fl_display::Graphics::curveTo(Scaleform::GFx::AS3::Instances::fl_display::Graphics *this, long double controlX, long double controlY, long double anchorX, long double anchorY)
{
  Scaleform::GFx::AS3::Instances::fl_display::Graphics *v5; // rbx
  float v6; // xmm4_4
  float v7; // xmm3_4
  float v8; // xmm2_4
  float v9; // xmm1_4

  v5 = this;
  if ( !(_S11_12 & 1) )
  {
    _S11_12 |= 1u;
    v.Flags = 0;
    v.Bonus.pWeakProxy = 0i64;
    atexit(Scaleform::GFx::AS3::Value::GetUndefined_::_2_::_dynamic_atexit_destructor_for__v__);
  }
  v6 = anchorY;
  v7 = anchorX;
  v8 = controlY;
  v9 = controlX;
  Scaleform::GFx::DrawingContext::CurveTo(v5->pDrawing.pObject, v9 * 20.0, v8 * 20.0, v7 * 20.0, v6 * 20.0);
  Scaleform::GFx::DisplayObjectBase::InvalidateHitResult((Scaleform::GFx::DisplayObjectBase *)&v5->pDispObj->vfptr);
}

// File Line: 219
// RVA: 0x851DF0
void __fastcall Scaleform::GFx::AS3::Instances::fl_display::Graphics::lineTo(Scaleform::GFx::AS3::Instances::fl_display::Graphics *this, long double x, long double y)
{
  Scaleform::GFx::AS3::Instances::fl_display::Graphics *v3; // rbx
  float v4; // xmm2_4
  float v5; // xmm1_4

  v3 = this;
  if ( !(_S11_12 & 1) )
  {
    _S11_12 |= 1u;
    v.Flags = 0;
    v.Bonus.pWeakProxy = 0i64;
    atexit(Scaleform::GFx::AS3::Value::GetUndefined_::_2_::_dynamic_atexit_destructor_for__v__);
  }
  v4 = y * 20.0;
  v5 = x * 20.0;
  Scaleform::GFx::DrawingContext::LineTo(v3->pDrawing.pObject, v5, v4);
  Scaleform::GFx::DisplayObjectBase::InvalidateHitResult((Scaleform::GFx::DisplayObjectBase *)&v3->pDispObj->vfptr);
}

// File Line: 223
// RVA: 0x854D90
void __fastcall Scaleform::GFx::AS3::Instances::fl_display::Graphics::moveTo(Scaleform::GFx::AS3::Instances::fl_display::Graphics *this, long double x, long double y)
{
  Scaleform::GFx::AS3::Instances::fl_display::Graphics *v3; // rbx
  float v4; // xmm2_4
  float v5; // xmm1_4

  v3 = this;
  if ( !(_S11_12 & 1) )
  {
    _S11_12 |= 1u;
    v.Flags = 0;
    v.Bonus.pWeakProxy = 0i64;
    atexit(Scaleform::GFx::AS3::Value::GetUndefined_::_2_::_dynamic_atexit_destructor_for__v__);
  }
  _((AMD_HD3D *)v3->pDispObj);
  Scaleform::GFx::DisplayObjectBase::InvalidateHitResult((Scaleform::GFx::DisplayObjectBase *)&v3->pDispObj->vfptr);
  Scaleform::GFx::DrawingContext::AcquirePath(v3->pDrawing.pObject, 0);
  v4 = y * 20.0;
  v5 = x * 20.0;
  Scaleform::GFx::DrawingContext::MoveTo(v3->pDrawing.pObject, v5, v4);
  Scaleform::GFx::DisplayObjectBase::InvalidateHitResult((Scaleform::GFx::DisplayObjectBase *)&v3->pDispObj->vfptr);
}

// File Line: 252
// RVA: 0x7FBEB0
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_display::Graphics> *__fastcall Scaleform::GFx::AS3::InstanceTraits::fl_display::Graphics::MakeInstance(Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_display::Graphics> *result, Scaleform::GFx::AS3::InstanceTraits::fl_display::Graphics *t)
{
  Scaleform::GFx::AS3::InstanceTraits::fl_display::Graphics *v2; // rsi
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_display::Graphics> *v3; // rdi
  Scaleform::GFx::AS3::Instance *v4; // rax
  Scaleform::GFx::AS3::Instances::fl_display::Graphics *v5; // rbx
  int v7; // [rsp+50h] [rbp+8h]
  Scaleform::GFx::AS3::Instance *v8; // [rsp+58h] [rbp+10h]
  Scaleform::GFx::AS3::Instance *v9; // [rsp+60h] [rbp+18h]

  v2 = t;
  v3 = result;
  v7 = 337;
  v4 = (Scaleform::GFx::AS3::Instance *)t->pVM->MHeap->vfptr->Alloc(
                                          t->pVM->MHeap,
                                          t->MemSize,
                                          (Scaleform::AllocInfo *)&v7);
  v5 = (Scaleform::GFx::AS3::Instances::fl_display::Graphics *)v4;
  v8 = v4;
  v9 = v4;
  if ( v4 )
  {
    Scaleform::GFx::AS3::Instance::Instance(v4, (Scaleform::GFx::AS3::InstanceTraits::Traits *)&v2->vfptr);
    v5->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl::Object::`vftable;
    v5->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl_display::Graphics::`vftable;
    v5->pDrawing.pObject = 0i64;
    v5->pDispObj = 0i64;
  }
  else
  {
    v5 = 0i64;
  }
  v3->pV = v5;
  return v3;
}

