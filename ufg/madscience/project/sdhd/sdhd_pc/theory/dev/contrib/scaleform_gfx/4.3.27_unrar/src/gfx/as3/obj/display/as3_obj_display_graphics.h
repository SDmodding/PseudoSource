// File Line: 175
// RVA: 0x82DAC0
void __fastcall Scaleform::GFx::AS3::Instances::fl_display::Graphics::beginBitmapFill(
        Scaleform::GFx::AS3::Instances::fl_display::Graphics *this,
        Scaleform::GFx::AS3::Instances::fl_display::BitmapData *bitmap,
        Scaleform::GFx::AS3::Instances::fl_geom::Matrix *matrix,
        bool repeat,
        bool smooth)
{
  if ( (_S11_12 & 1) == 0 )
  {
    _S11_12 |= 1u;
    v.Flags = 0;
    v.Bonus.pWeakProxy = 0i64;
    atexit(Scaleform::GFx::AS3::Value::GetUndefined_::_2_::_dynamic_atexit_destructor_for__v__);
  }
  Scaleform::GFx::AS3::Instances::fl_display::Graphics::beginBitmapFill(this, &v, bitmap, matrix, repeat, smooth);
}

// File Line: 179
// RVA: 0x82DBC0
void __fastcall Scaleform::GFx::AS3::Instances::fl_display::Graphics::beginFill(
        Scaleform::GFx::AS3::Instances::fl_display::Graphics *this,
        unsigned int color,
        long double alpha)
{
  if ( (_S11_12 & 1) == 0 )
  {
    _S11_12 |= 1u;
    v.Flags = 0;
    v.Bonus.pWeakProxy = 0i64;
    atexit(Scaleform::GFx::AS3::Value::GetUndefined_::_2_::_dynamic_atexit_destructor_for__v__);
  }
  _((AMD_HD3D *)this->pDispObj);
  Scaleform::GFx::DisplayObjectBase::InvalidateHitResult(this->pDispObj);
  Scaleform::GFx::DrawingContext::AcquirePath(this->pDrawing.pObject, 1);
  Scaleform::GFx::DrawingContext::BeginSolidFill(this->pDrawing.pObject, color | ((int)(alpha * 255.0) << 24));
}

// File Line: 187
// RVA: 0x8332C0
void __fastcall Scaleform::GFx::AS3::Instances::fl_display::Graphics::curveTo(
        Scaleform::GFx::AS3::Instances::fl_display::Graphics *this,
        long double controlX,
        long double controlY,
        long double anchorX,
        long double anchorY)
{
  float v6; // xmm4_4
  float v7; // xmm3_4
  float v8; // xmm2_4
  float v9; // xmm1_4

  if ( (_S11_12 & 1) == 0 )
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
  Scaleform::GFx::DrawingContext::CurveTo(this->pDrawing.pObject, v9 * 20.0, v8 * 20.0, v7 * 20.0, v6 * 20.0);
  Scaleform::GFx::DisplayObjectBase::InvalidateHitResult(this->pDispObj);
}

// File Line: 219
// RVA: 0x851DF0
void __fastcall Scaleform::GFx::AS3::Instances::fl_display::Graphics::lineTo(
        Scaleform::GFx::AS3::Instances::fl_display::Graphics *this,
        long double x,
        long double y)
{
  float v4; // xmm2_4
  float v5; // xmm1_4

  if ( (_S11_12 & 1) == 0 )
  {
    _S11_12 |= 1u;
    v.Flags = 0;
    v.Bonus.pWeakProxy = 0i64;
    atexit(Scaleform::GFx::AS3::Value::GetUndefined_::_2_::_dynamic_atexit_destructor_for__v__);
  }
  v4 = y * 20.0;
  v5 = x * 20.0;
  Scaleform::GFx::DrawingContext::LineTo(this->pDrawing.pObject, v5, v4);
  Scaleform::GFx::DisplayObjectBase::InvalidateHitResult(this->pDispObj);
}

// File Line: 223
// RVA: 0x854D90
void __fastcall Scaleform::GFx::AS3::Instances::fl_display::Graphics::moveTo(
        Scaleform::GFx::AS3::Instances::fl_display::Graphics *this,
        long double x,
        long double y)
{
  float v4; // xmm2_4
  float v5; // xmm1_4

  if ( (_S11_12 & 1) == 0 )
  {
    _S11_12 |= 1u;
    v.Flags = 0;
    v.Bonus.pWeakProxy = 0i64;
    atexit(Scaleform::GFx::AS3::Value::GetUndefined_::_2_::_dynamic_atexit_destructor_for__v__);
  }
  _((AMD_HD3D *)this->pDispObj);
  Scaleform::GFx::DisplayObjectBase::InvalidateHitResult(this->pDispObj);
  Scaleform::GFx::DrawingContext::AcquirePath(this->pDrawing.pObject, 0);
  v4 = y * 20.0;
  v5 = x * 20.0;
  Scaleform::GFx::DrawingContext::MoveTo(this->pDrawing.pObject, v5, v4);
  Scaleform::GFx::DisplayObjectBase::InvalidateHitResult(this->pDispObj);
}

// File Line: 252
// RVA: 0x7FBEB0
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_display::Graphics> *__fastcall Scaleform::GFx::AS3::InstanceTraits::fl_display::Graphics::MakeInstance(
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_display::Graphics> *result,
        Scaleform::GFx::AS3::InstanceTraits::fl_display::Graphics *t)
{
  Scaleform::GFx::AS3::Instance *v4; // rax
  Scaleform::GFx::AS3::Instances::fl_display::Graphics *v5; // rbx
  int v7; // [rsp+50h] [rbp+8h] BYREF
  Scaleform::GFx::AS3::Instance *v8; // [rsp+58h] [rbp+10h]
  Scaleform::GFx::AS3::Instance *v9; // [rsp+60h] [rbp+18h]

  v7 = 337;
  v4 = (Scaleform::GFx::AS3::Instance *)t->pVM->MHeap->vfptr->Alloc(t->pVM->MHeap, t->MemSize, &v7);
  v5 = (Scaleform::GFx::AS3::Instances::fl_display::Graphics *)v4;
  v8 = v4;
  v9 = v4;
  if ( v4 )
  {
    Scaleform::GFx::AS3::Instance::Instance(v4, t);
    v5->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl::Object::`vftable;
    v5->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl_display::Graphics::`vftable;
    v5->pDrawing.pObject = 0i64;
    v5->pDispObj = 0i64;
  }
  else
  {
    v5 = 0i64;
  }
  result->pV = v5;
  return result;
}

