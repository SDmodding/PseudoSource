// File Line: 62
// RVA: 0x6D0F60
void __fastcall Scaleform::GFx::AvmDisplayObjBase::~AvmDisplayObjBase(Scaleform::GFx::AvmDisplayObjBase *this)
{
  this->vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AvmDisplayObjBase::`vftable';
}

// File Line: 165
// RVA: 0x89C370
void __fastcall Scaleform::GFx::DisplayObjectBase::PerspectiveDataType::PerspectiveDataType(Scaleform::GFx::DisplayObjectBase::PerspectiveDataType *this)
{
  Scaleform::GFx::DisplayObjectBase::PerspectiveDataType *v1; // rdi

  v1 = this;
  this->FieldOfView = 0.0;
  this->FocalLength = 0.0;
  memset(&this->ViewMatrix3D, 0, 0x30ui64);
  v1->ViewMatrix3D.M[0][0] = 1.0;
  v1->ViewMatrix3D.M[1][1] = 1.0;
  v1->ViewMatrix3D.M[2][2] = 1.0;
  v1->ProjectionCenter.x = -2.696539702293474e308/*NaN*/;
  v1->ProjectionCenter.y = -2.696539702293474e308/*NaN*/;
}

// File Line: 261
// RVA: 0x6FFEF0
bool __fastcall Scaleform::GFx::DisplayObjectBase::Has3D(Scaleform::GFx::DisplayObjectBase *this)
{
  Scaleform::Render::TreeNode *v1; // rdx
  unsigned __int64 v2; // r8
  unsigned __int64 v3; // rdx
  bool result; // al

  v1 = this->pRenNode.pObject;
  result = 0;
  if ( v1 )
  {
    v2 = (unsigned __int64)v1 & 0xFFFFFFFFFFFFF000ui64;
    v3 = (signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&v1[-1]
                                                             - ((unsigned __int64)v1 & 0xFFFFFFFFFFFFF000ui64))
                                            * (signed __int128)5270498306774157605i64) >> 64) >> 4;
    if ( (*(_WORD *)(*(_QWORD *)(*(_QWORD *)(v2 + 32) + 8 * ((unsigned int)v3 + (v3 >> 63)) + 40) + 10i64) >> 9) & 1 )
      result = 1;
  }
  return result;
}

// File Line: 284
// RVA: 0x6FB760
bool __fastcall Scaleform::GFx::DisplayObjectBase::HasScale9Grid(Scaleform::GFx::DisplayObjectBase *this)
{
  Scaleform::Render::Rect<float> *v1; // rcx
  float v2; // xmm0_4
  bool v3; // cf
  bool v4; // zf
  char v5; // cl
  Scaleform::Render::Rect<float> result; // [rsp+20h] [rbp-18h]

  v1 = Scaleform::GFx::DisplayObjectBase::GetScale9Grid(this, &result);
  if ( v1->x2 <= v1->x1 || (v2 = v1->y2, v3 = v2 < v1->y1, v4 = v2 == v1->y1, v5 = 0, v3 || v4) )
    v5 = 1;
  return v5 == 0;
}

// File Line: 337
// RVA: 0x6F43D0
void __fastcall Scaleform::GFx::DisplayObjectBase::GetMouseX(Scaleform::GFx::DisplayObjectBase *this)
{
  Scaleform::GFx::NumberUtil::NaN();
}

// File Line: 357
// RVA: 0x71E070
void __fastcall Scaleform::GFx::DisplayObjectBase::SetVisible(Scaleform::GFx::DisplayObjectBase *this, bool visible)
{
  Scaleform::GFx::DisplayObjectBase *v2; // rbx

  v2 = this;
  Scaleform::GFx::DisplayObjectBase::SetVisibleFlag(this, visible);
  _((AMD_HD3D *)v2);
}

// File Line: 358
// RVA: 0x6F87D0
__int64 __fastcall Scaleform::GFx::DisplayObjectBase::GetVisible(Scaleform::GFx::DisplayObjectBase *this)
{
  return ((unsigned int)this->Flags >> 14) & 1;
}

// File Line: 415
// RVA: 0x6EFCB0
Scaleform::Render::Matrix2x4<float> *__fastcall Scaleform::GFx::DisplayObjectBase::GetLevelMatrix(Scaleform::GFx::DisplayObjectBase *this, Scaleform::Render::Matrix2x4<float> *result)
{
  Scaleform::Render::Matrix2x4<float> *v2; // rbx

  v2 = result;
  *(_OWORD *)&result->M[0][0] = 0x3F800000ui64;
  result->M[1][0] = 0.0;
  result->M[1][3] = 0.0;
  *(_QWORD *)&result->M[1][1] = 1065353216i64;
  Scaleform::GFx::DisplayObjectBase::GetLevelMatrix(this, result);
  return v2;
}

// File Line: 479
// RVA: 0x7F0A30
signed __int64 __fastcall Scaleform::GFx::DisplayObjectBase::GetTopMostMouseEntity(Scaleform::GFx::DisplayObjectBase *this, Scaleform::Render::Point<float> *pt, Scaleform::GFx::DisplayObjectBase::TopMostDescr *pdescr)
{
  pdescr->pResult = 0i64;
  return 2i64;
}

// File Line: 496
// RVA: 0x6F5360
Scaleform::GFx::MovieDefImpl *__fastcall Scaleform::GFx::DisplayObjectBase::GetResourceMovieDef(Scaleform::GFx::DisplayObjectBase *this)
{
  Scaleform::GFx::InteractiveObject *v1; // rcx
  Scaleform::GFx::MovieDefImpl *result; // rax

  v1 = this->pParent;
  if ( v1 )
    result = (Scaleform::GFx::MovieDefImpl *)((__int64 (*)(void))v1->vfptr[66].__vecDelDtor)();
  else
    result = 0i64;
  return result;
}

// File Line: 499
// RVA: 0x6EFAC0
Scaleform::GFx::FontManager *__fastcall Scaleform::GFx::DisplayObjectBase::GetFontManager(Scaleform::GFx::DisplayObjectBase *this)
{
  Scaleform::GFx::InteractiveObject *v1; // rcx
  Scaleform::GFx::FontManager *result; // rax

  v1 = this->pParent;
  if ( v1 )
    result = (Scaleform::GFx::FontManager *)((__int64 (*)(void))v1->vfptr[67].__vecDelDtor)();
  else
    result = 0i64;
  return result;
}

// File Line: 508
// RVA: 0x6F7200
Scaleform::GFx::InteractiveObject *__fastcall Scaleform::GFx::DisplayObjectBase::GetTopParent(Scaleform::GFx::DisplayObjectBase *this, __int64 ignoreLockRoot)
{
  Scaleform::GFx::InteractiveObject *v2; // rcx
  Scaleform::GFx::InteractiveObject *result; // rax

  v2 = this->pParent;
  if ( v2 )
    result = (Scaleform::GFx::InteractiveObject *)v2->vfptr[68].__vecDelDtor(
                                                    (Scaleform::RefCountNTSImplCore *)&v2->vfptr,
                                                    ignoreLockRoot);
  else
    result = 0i64;
  return result;
}

// File Line: 543
// RVA: 0x705EB0
void __fastcall Scaleform::GFx::DisplayObjectBase::OnEventLoad(Scaleform::GFx::DisplayObjectBase *this)
{
  this->Flags |= 0x2000u;
}

// File Line: 837
// RVA: 0x7E7460
__int64 __fastcall Scaleform::GFx::DisplayObject::GetContinueAnimationFlag(Scaleform::GFx::DisplayObject *this)
{
  return ((unsigned int)this->Flags >> 4) & 1;
}

// File Line: 846
// RVA: 0x7F9580
__int64 __fastcall Scaleform::GFx::DisplayObject::IsUsedAsMask(Scaleform::GFx::DisplayObject *this)
{
  return ((unsigned int)this->Flags >> 2) & 1;
}

// File Line: 897
// RVA: 0x7E5B30
__int64 __fastcall Scaleform::GFx::DisplayObject::GetAcceptAnimMoves(Scaleform::GFx::DisplayObject *this)
{
  return ((unsigned int)this->Flags >> 3) & 1;
}

