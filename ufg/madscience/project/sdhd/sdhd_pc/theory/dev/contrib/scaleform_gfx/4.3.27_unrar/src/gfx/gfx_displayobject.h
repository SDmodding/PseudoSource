// File Line: 62
// RVA: 0x6D0F60
void __fastcall Scaleform::GFx::AvmDisplayObjBase::~AvmDisplayObjBase(Scaleform::GFx::AvmDisplayObjBase *this)
{
  this->vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AvmDisplayObjBase::`vftable;
}

// File Line: 165
// RVA: 0x89C370
void __fastcall Scaleform::GFx::DisplayObjectBase::PerspectiveDataType::PerspectiveDataType(
        Scaleform::GFx::DisplayObjectBase::PerspectiveDataType *this)
{
  this->FieldOfView = 0.0;
  this->FocalLength = 0.0;
  memset(&this->ViewMatrix3D, 0, sizeof(this->ViewMatrix3D));
  this->ViewMatrix3D.M[0][0] = 1.0;
  this->ViewMatrix3D.M[1][1] = 1.0;
  this->ViewMatrix3D.M[2][2] = 1.0;
  this->ProjectionCenter.x = NAN;
  this->ProjectionCenter.y = NAN;
}

// File Line: 261
// RVA: 0x6FFEF0
bool __fastcall Scaleform::GFx::DisplayObjectBase::Has3D(Scaleform::GFx::DisplayObjectBase *this)
{
  Scaleform::Render::TreeNode *pObject; // rdx
  unsigned __int64 v2; // r8
  unsigned __int64 v3; // rdx
  bool result; // al

  pObject = this->pRenNode.pObject;
  result = 0;
  if ( pObject )
  {
    v2 = (unsigned __int64)pObject & 0xFFFFFFFFFFFFF000ui64;
    v3 = (__int64)((unsigned __int128)((__int64)((__int64)&pObject[-1]
                                               - ((unsigned __int64)pObject & 0xFFFFFFFFFFFFF000ui64))
                                     * (__int128)0x4924924924924925i64) >> 64) >> 4;
    if ( (*(_WORD *)(*(_QWORD *)(*(_QWORD *)(v2 + 32) + 8 * ((unsigned int)v3 + (v3 >> 63)) + 40) + 10i64) & 0x200) != 0 )
      return 1;
  }
  return result;
}

// File Line: 284
// RVA: 0x6FB760
bool __fastcall Scaleform::GFx::DisplayObjectBase::HasScale9Grid(Scaleform::GFx::DisplayObjectBase *this)
{
  Scaleform::Render::Rect<float> *Scale9Grid; // rcx
  bool v2; // cc
  char v3; // cl
  Scaleform::Render::Rect<float> result; // [rsp+20h] [rbp-18h] BYREF

  Scale9Grid = Scaleform::GFx::DisplayObjectBase::GetScale9Grid(this, &result);
  if ( Scale9Grid->x2 <= Scale9Grid->x1 || (v2 = Scale9Grid->y2 <= Scale9Grid->y1, v3 = 0, v2) )
    v3 = 1;
  return v3 == 0;
}

// File Line: 337
// RVA: 0x6F43D0
// attributes: thunk
long double __fastcall Scaleform::GFx::DisplayObjectBase::GetMouseX(Scaleform::GFx::DisplayObjectBase *this)
{
  return Scaleform::GFx::NumberUtil::NaN();
}

// File Line: 357
// RVA: 0x71E070
void __fastcall Scaleform::GFx::DisplayObjectBase::SetVisible(Scaleform::GFx::DisplayObjectBase *this, bool visible)
{
  Scaleform::GFx::DisplayObjectBase::SetVisibleFlag(this, visible);
  _((AMD_HD3D *)this);
}

// File Line: 358
// RVA: 0x6F87D0
__int64 __fastcall Scaleform::GFx::DisplayObjectBase::GetVisible(Scaleform::GFx::DisplayObjectBase *this)
{
  return (this->Flags >> 14) & 1;
}

// File Line: 415
// RVA: 0x6EFCB0
Scaleform::Render::Matrix2x4<float> *__fastcall Scaleform::GFx::DisplayObjectBase::GetLevelMatrix(
        Scaleform::GFx::DisplayObjectBase *this,
        Scaleform::Render::Matrix2x4<float> *result)
{
  *(_OWORD *)&result->M[0][0] = 0x3F800000ui64;
  result->M[1][0] = 0.0;
  result->M[1][3] = 0.0;
  *(_QWORD *)&result->M[1][1] = 1065353216i64;
  Scaleform::GFx::DisplayObjectBase::GetLevelMatrix(this, result);
  return result;
}

// File Line: 479
// RVA: 0x7F0A30
__int64 __fastcall Scaleform::GFx::DisplayObjectBase::GetTopMostMouseEntity(
        Scaleform::GFx::DisplayObjectBase *this,
        Scaleform::Render::Point<float> *pt,
        Scaleform::GFx::DisplayObjectBase::TopMostDescr *pdescr)
{
  pdescr->pResult = 0i64;
  return 2i64;
}

// File Line: 496
// RVA: 0x6F5360
Scaleform::GFx::MovieDefImpl *__fastcall Scaleform::GFx::DisplayObjectBase::GetResourceMovieDef(
        Scaleform::GFx::DisplayObjectBase *this)
{
  Scaleform::GFx::InteractiveObject *pParent; // rcx

  pParent = this->pParent;
  if ( pParent )
    return (Scaleform::GFx::MovieDefImpl *)((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *))pParent->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[66].__vecDelDtor)(pParent);
  else
    return 0i64;
}

// File Line: 499
// RVA: 0x6EFAC0
Scaleform::GFx::FontManager *__fastcall Scaleform::GFx::DisplayObjectBase::GetFontManager(
        Scaleform::GFx::DisplayObjectBase *this)
{
  Scaleform::GFx::InteractiveObject *pParent; // rcx

  pParent = this->pParent;
  if ( pParent )
    return (Scaleform::GFx::FontManager *)((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *))pParent->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[67].__vecDelDtor)(pParent);
  else
    return 0i64;
}

// File Line: 508
// RVA: 0x6F7200
Scaleform::GFx::InteractiveObject *__fastcall Scaleform::GFx::DisplayObjectBase::GetTopParent(
        Scaleform::GFx::DisplayObjectBase *this,
        __int64 ignoreLockRoot)
{
  Scaleform::GFx::InteractiveObject *pParent; // rcx

  pParent = this->pParent;
  if ( pParent )
    return (Scaleform::GFx::InteractiveObject *)pParent->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[68].__vecDelDtor(
                                                  pParent,
                                                  ignoreLockRoot);
  else
    return 0i64;
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
  return (this->Flags >> 4) & 1;
}

// File Line: 846
// RVA: 0x7F9580
__int64 __fastcall Scaleform::GFx::DisplayObject::IsUsedAsMask(Scaleform::GFx::DisplayObject *this)
{
  return (this->Flags >> 2) & 1;
}

// File Line: 897
// RVA: 0x7E5B30
__int64 __fastcall Scaleform::GFx::DisplayObject::GetAcceptAnimMoves(Scaleform::GFx::DisplayObject *this)
{
  return (this->Flags >> 3) & 1;
}

