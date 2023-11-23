// File Line: 143
// RVA: 0x6D20F0
void __fastcall Scaleform::GFx::MovieDefRootNode::~MovieDefRootNode(Scaleform::GFx::MovieDefRootNode *this)
{
  Scaleform::Render::RenderBuffer *pObject; // rcx

  this->vfptr = (Scaleform::GFx::MovieDefRootNodeVtbl *)&Scaleform::GFx::MovieDefRootNode::`vftable;
  pObject = (Scaleform::Render::RenderBuffer *)this->pFontManager.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
}

// File Line: 183
// RVA: 0x8A9400
bool __fastcall Scaleform::GFx::AutoTabSortFunctor::operator()(
        Scaleform::GFx::AutoTabSortFunctor *this,
        Scaleform::GFx::InteractiveObject *a,
        Scaleform::GFx::InteractiveObject *b)
{
  Scaleform::GFx::InteractiveObject *pParent; // rcx
  float *v6; // rax
  float v7; // xmm3_4
  float v8; // xmm4_4
  float v9; // xmm5_4
  float v10; // xmm6_4
  float v11; // xmm0_4
  float v12; // xmm2_4
  Scaleform::GFx::InteractiveObject *v13; // rcx
  float *v14; // rax
  float v15; // xmm3_4
  float v16; // xmm4_4
  float v17; // xmm5_4
  float v18; // xmm6_4
  float v19; // xmm0_4
  float v20; // xmm2_4
  Scaleform::Render::Rect<float> *v21; // rax
  Scaleform::Render::Rect<float> *v22; // rax
  float v23; // xmm7_4
  float v24; // xmm8_4
  float v25; // xmm5_4
  float v26; // xmm4_4
  bool v27; // cf
  bool v28; // zf
  Scaleform::Render::Rect<float> v30; // [rsp+18h] [rbp-49h] BYREF
  Scaleform::Render::Rect<float> pr; // [rsp+28h] [rbp-39h] BYREF
  char v32[16]; // [rsp+38h] [rbp-29h] BYREF
  Scaleform::Render::Matrix2x4<float> pmat; // [rsp+48h] [rbp-19h] BYREF
  Scaleform::Render::Matrix2x4<float> v34; // [rsp+68h] [rbp+7h] BYREF

  pParent = a->pParent;
  *(_OWORD *)&pmat.M[0][0] = _xmm;
  *(__m128 *)&pmat.M[1][0] = _xmm;
  if ( pParent )
  {
    Scaleform::GFx::DisplayObjectBase::GetLevelMatrix(pParent, &pmat);
    v6 = (float *)((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *))a->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[2].__vecDelDtor)(a);
    v7 = pmat.M[0][0];
    v8 = pmat.M[0][1];
    v9 = pmat.M[1][0];
    v10 = pmat.M[1][1];
    pmat.M[0][0] = (float)(pmat.M[0][1] * v6[4]) + (float)(pmat.M[0][0] * *v6);
    pmat.M[1][0] = (float)(pmat.M[1][1] * v6[4]) + (float)(pmat.M[1][0] * *v6);
    pmat.M[0][1] = (float)(v7 * v6[1]) + (float)(pmat.M[0][1] * v6[5]);
    v11 = pmat.M[1][1] * v6[5];
    v12 = v9 * v6[1];
    pmat.M[0][2] = 0.0;
    *(_QWORD *)&pmat.M[1][1] = COERCE_UNSIGNED_INT(v12 + v11);
    pmat.M[0][3] = pmat.M[0][3] + (float)((float)(v8 * v6[7]) + (float)(v7 * v6[3]));
    pmat.M[1][3] = pmat.M[1][3] + (float)((float)(v10 * v6[7]) + (float)(v9 * v6[3]));
  }
  else
  {
    *(_OWORD *)&pmat.M[0][0] = _xmm;
    *(__m128 *)&pmat.M[1][0] = _xmm;
  }
  v13 = b->pParent;
  *(_OWORD *)&v34.M[0][0] = _xmm;
  *(__m128 *)&v34.M[1][0] = _xmm;
  if ( v13 )
  {
    Scaleform::GFx::DisplayObjectBase::GetLevelMatrix(v13, &v34);
    v14 = (float *)((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *))b->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[2].__vecDelDtor)(b);
    v15 = v34.M[0][0];
    v16 = v34.M[0][1];
    v17 = v34.M[1][0];
    v18 = v34.M[1][1];
    v34.M[0][0] = (float)(v34.M[0][0] * *v14) + (float)(v34.M[0][1] * v14[4]);
    v34.M[1][0] = (float)(v34.M[1][0] * *v14) + (float)(v34.M[1][1] * v14[4]);
    v34.M[0][1] = (float)(v15 * v14[1]) + (float)(v34.M[0][1] * v14[5]);
    v19 = v34.M[1][1] * v14[5];
    v20 = v17 * v14[1];
    v34.M[0][2] = 0.0;
    *(_QWORD *)&v34.M[1][1] = COERCE_UNSIGNED_INT(v20 + v19);
    v34.M[0][3] = v34.M[0][3] + (float)((float)(v16 * v14[7]) + (float)(v15 * v14[3]));
    v34.M[1][3] = v34.M[1][3] + (float)((float)(v18 * v14[7]) + (float)(v17 * v14[3]));
  }
  else
  {
    *(_OWORD *)&v34.M[0][0] = _xmm;
    *(__m128 *)&v34.M[1][0] = _xmm;
  }
  v21 = (Scaleform::Render::Rect<float> *)a->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[93].__vecDelDtor(
                                            a,
                                            v32);
  Scaleform::Render::Matrix2x4<float>::EncloseTransform(&pmat, &pr, v21);
  v22 = (Scaleform::Render::Rect<float> *)b->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[93].__vecDelDtor(
                                            b,
                                            v32);
  Scaleform::Render::Matrix2x4<float>::EncloseTransform(&v34, &v30, v22);
  v23 = (float)(pr.x2 + pr.x1) * 0.5;
  v24 = (float)(v30.x2 + v30.x1) * 0.5;
  v25 = (float)(v30.y2 + v30.y1) * 0.5;
  v26 = (float)(pr.y2 + pr.y1) * 0.5;
  if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(pr.y1 - v30.y1) & _xmm) <= 20.0
    || COERCE_FLOAT(COERCE_UNSIGNED_INT(pr.y2 - v30.y2) & _xmm) <= 20.0
    || COERCE_FLOAT(COERCE_UNSIGNED_INT(v26 - v25) & _xmm) <= 20.0 )
  {
    v27 = v24 < v23;
    v28 = v24 == v23;
  }
  else
  {
    v27 = v25 < v26;
    v28 = v25 == v26;
  }
  return !v27 && !v28;
}

// File Line: 214
// RVA: 0x6D0A70
void __fastcall Scaleform::GFx::ASIntervalTimerIntf::~ASIntervalTimerIntf(Scaleform::GFx::ASIntervalTimerIntf *this)
{
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::ASIntervalTimerIntf::`vftable;
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
}

// File Line: 250
// RVA: 0x7009F0
_BOOL8 __fastcall Scaleform::GFx::FocusGroupDescr::IsFocused(
        Scaleform::GFx::FocusGroupDescr *this,
        Scaleform::GFx::Sprite *ch)
{
  Scaleform::GFx::Sprite *pObject; // rbx
  bool v4; // di
  Scaleform::Ptr<Scaleform::GFx::Sprite> result; // [rsp+40h] [rbp+8h] BYREF
  Scaleform::GFx::Sprite *v7; // [rsp+48h] [rbp+10h]

  Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>::operator Scaleform::Ptr<Scaleform::GFx::DisplayObject>(
    (Scaleform::WeakPtr<Scaleform::GFx::Sprite> *)&this->LastFocused,
    &result);
  pObject = result.pObject;
  if ( result.pObject )
  {
    ++result.pObject->RefCount;
    pObject = result.pObject;
  }
  v7 = pObject;
  if ( result.pObject )
    Scaleform::RefCountNTSImpl::Release(result.pObject);
  v4 = pObject == ch;
  if ( pObject )
    Scaleform::RefCountNTSImpl::Release(pObject);
  return v4;
}

// File Line: 310
// RVA: 0x6CD9F0
void __fastcall Scaleform::GFx::MovieImpl::WideStringStorage::WideStringStorage(
        Scaleform::GFx::MovieImpl::WideStringStorage *this,
        Scaleform::GFx::ASStringNode *pnode,
        unsigned __int64 dataSz)
{
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,327>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::GFx::MovieImpl::WideStringStorage,327>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::MovieImpl::WideStringStorage::`vftable;
  this->pNode = pnode;
  ++pnode->RefCount;
  Scaleform::UTF8Util::DecodeStringSafe((wchar_t *)this->pData, dataSz, this->pNode->pData, this->pNode->Size);
}

// File Line: 335
// RVA: 0x6EEA50
Scaleform::Log *__fastcall Scaleform::GFx::MovieImpl::GetCachedLog(Scaleform::GFx::MovieImpl *this)
{
  Scaleform::GFx::Resource **Log; // rdi
  Scaleform::Render::RenderBuffer *pObject; // rcx
  Scaleform::Ptr<Scaleform::Log> result; // [rsp+40h] [rbp+8h] BYREF

  if ( (this->Flags & 2) != 0 )
    return this->pCachedLog.pObject;
  Log = (Scaleform::GFx::Resource **)Scaleform::GFx::StateBag::GetLog(&this->Scaleform::GFx::StateBag, &result);
  if ( *Log )
    Scaleform::Render::RenderBuffer::AddRef(*Log);
  pObject = (Scaleform::Render::RenderBuffer *)this->pCachedLog.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  this->pCachedLog.pObject = (Scaleform::Log *)*Log;
  if ( result.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)result.pObject);
  return this->pCachedLog.pObject;
}

// File Line: 372
// RVA: 0x89C8B0
void __fastcall Scaleform::GFx::MovieImpl::ReturnValueHolder::ReturnValueHolder(
        Scaleform::GFx::MovieImpl::ReturnValueHolder *this,
        Scaleform::GFx::ASStringManager *pmgr)
{
  Scaleform::GFx::ASString *v3; // rax
  Scaleform::GFx::ASStringNode *pNode; // rax
  Scaleform::GFx::ASStringNode *v5; // rcx
  Scaleform::GFx::ASString result; // [rsp+50h] [rbp+18h] BYREF
  Scaleform::ArrayCC<Scaleform::GFx::ASString,323,Scaleform::ArrayDefaultPolicy> *p_StringArray; // [rsp+58h] [rbp+20h]

  this->CharBuffer = 0i64;
  this->CharBufferSize = 0;
  v3 = Scaleform::GFx::ASStringManager::CreateConstString(pmgr, &result, &customCaption);
  p_StringArray = &this->StringArray;
  this->StringArray.Data.Data = 0i64;
  this->StringArray.Data.Size = 0i64;
  this->StringArray.Data.Policy.Capacity = 0i64;
  pNode = v3->pNode;
  this->StringArray.Data.DefaultValue.pNode = pNode;
  ++pNode->RefCount;
  v5 = result.pNode;
  if ( result.pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v5);
  this->StringArrayPos = 0;
}

// File Line: 433
// RVA: 0x6D25A0
void __fastcall Scaleform::GFx::MovieImpl::StickyVarNode::~StickyVarNode(
        Scaleform::GFx::MovieImpl::StickyVarNode *this)
{
  Scaleform::GFx::ASStringNode *pNode; // rcx

  this->vfptr = (Scaleform::GFx::MovieImpl::StickyVarNodeVtbl *)&Scaleform::GFx::MovieImpl::StickyVarNode::`vftable;
  pNode = this->Name.pNode;
  if ( pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}

// File Line: 436
// RVA: 0x6DAB50
void __fastcall Scaleform::GFx::MovieImpl::StickyVarNode::Assign(
        Scaleform::GFx::MovieImpl::StickyVarNode *this,
        Scaleform::GFx::MovieImpl::StickyVarNode *node)
{
  Scaleform::GFx::ASStringNode *pNode; // rdi
  Scaleform::GFx::ASStringNode *v5; // rcx

  pNode = node->Name.pNode;
  ++pNode->RefCount;
  v5 = this->Name.pNode;
  if ( v5->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v5);
  this->Name.pNode = pNode;
  this->Permanent = node->Permanent;
}

// File Line: 628
// RVA: 0x9099E0
void __fastcall Scaleform::GFx::MovieImpl::SetMouseCursorCount(Scaleform::GFx::MovieImpl *this, unsigned int n)
{
  unsigned int v2; // eax

  v2 = 6;
  if ( n <= 6 )
    v2 = n;
  this->MouseCursorCount = v2;
}

// File Line: 632
// RVA: 0x8DB1E0
__int64 __fastcall Scaleform::GFx::MovieImpl::GetMouseCursorCount(Scaleform::GFx::MovieImpl *this)
{
  return this->MouseCursorCount;
}

// File Line: 636
// RVA: 0x906A60
void __fastcall Scaleform::GFx::MovieImpl::SetControllerCount(Scaleform::GFx::MovieImpl *this, unsigned int n)
{
  unsigned int v2; // eax

  v2 = 6;
  if ( n <= 6 )
    v2 = n;
  this->ControllerCount = v2;
}

// File Line: 640
// RVA: 0x8D64E0
__int64 __fastcall Scaleform::GFx::MovieImpl::GetControllerCount(Scaleform::GFx::MovieImpl *this)
{
  return this->ControllerCount;
}

// File Line: 707
// RVA: 0x8E1780
__int64 __fastcall Scaleform::GFx::MovieImpl::GetViewScaleMode(UFG::EncounterBase *this)
{
  return this->mInsideDynamicRadiusCount;
}

// File Line: 709
// RVA: 0x8E1580
__int64 __fastcall Scaleform::GFx::MovieImpl::GetViewAlignment(UFG::CopSystem *this)
{
  return (unsigned int)this->mHeatLevel;
}

// File Line: 710
// RVA: 0x8E1880
Scaleform::Render::Rect<float> *__fastcall Scaleform::GFx::MovieImpl::GetVisibleFrameRect(
        Scaleform::GFx::MovieImpl *this,
        Scaleform::Render::Rect<float> *result)
{
  Scaleform::Render::Rect<float> *v2; // rax
  float v3; // xmm1_4
  float y1; // xmm0_4

  v2 = result;
  v3 = this->VisibleFrameRect.x2 * 0.050000001;
  result->x1 = this->VisibleFrameRect.x1 * 0.050000001;
  y1 = this->VisibleFrameRect.y1;
  result->x2 = v3;
  result->y1 = y1 * 0.050000001;
  result->y2 = this->VisibleFrameRect.y2 * 0.050000001;
  return v2;
}

// File Line: 713
// RVA: 0x8DDE70
Scaleform::Render::Rect<float> *__fastcall Scaleform::GFx::MovieImpl::GetSafeRect(
        Scaleform::GFx::MovieImpl *this,
        Scaleform::Render::Rect<float> *result)
{
  *result = this->SafeRect;
  return result;
}

// File Line: 714
// RVA: 0x90B4F0
void __fastcall Scaleform::GFx::MovieImpl::SetSafeRect(
        Scaleform::GFx::MovieImpl *this,
        Scaleform::Render::Rect<float> *rect)
{
  float x1; // eax
  float y2; // xmm2_4
  float y1; // xmm0_4

  x1 = rect->x1;
  y2 = rect->y2;
  y1 = rect->y1;
  this->SafeRect.x2 = rect->x2;
  this->SafeRect.y2 = y2;
  this->SafeRect.x1 = x1;
  this->SafeRect.y1 = y1;
}

// File Line: 716
// RVA: 0x906FB0
void __fastcall Scaleform::GFx::MovieImpl::SetEdgeAAMode(
        Scaleform::GFx::MovieImpl *this,
        Scaleform::Render::EdgeAAMode edgeAA)
{
  Scaleform::Render::TreeNode::SetEdgeAAMode(this->pRenderRoot.pObject, edgeAA);
}

// File Line: 717
// RVA: 0x8D7380
__int64 __fastcall Scaleform::GFx::MovieImpl::GetEdgeAAMode(Scaleform::GFx::MovieImpl *this)
{
  return *(_WORD *)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)this->pRenderRoot.pObject & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                              + 8i64
                              * (unsigned int)((int)(LODWORD(this->pRenderRoot.pObject)
                                                   - ((__int64)this->pRenderRoot.pObject & 0xFFFFF000)
                                                   - 56)
                                             / 56)
                              + 40)
                  + 10i64) & 0xC;
}

// File Line: 722
// RVA: 0x90E8C0
void __fastcall Scaleform::GFx::MovieImpl::SetVerboseAction(Scaleform::GFx::MovieImpl *this, bool verboseAction)
{
  if ( verboseAction )
    this->Flags |= 4u;
  else
    this->Flags &= ~4u;
}

// File Line: 729
// RVA: 0x906190
void __fastcall Scaleform::GFx::MovieImpl::SetActionErrorsSuppress(
        Scaleform::GFx::MovieImpl *this,
        bool suppressActionErrors)
{
  if ( suppressActionErrors )
    this->Flags |= 0x40u;
  else
    this->Flags &= ~0x40u;
}

// File Line: 733
// RVA: 0x8D4D40
float __fastcall Scaleform::GFx::MovieImpl::GetBackgroundAlpha(Scaleform::GFx::MovieImpl *this)
{
  return (float)(unsigned __int8)this->BackgroundColor.Channels.Alpha * 0.0039215689;
}

// File Line: 747
// RVA: 0x8D6CD0
Scaleform::Render::ContextImpl::DisplayHandle<Scaleform::Render::TreeRoot> *__fastcall Scaleform::GFx::MovieImpl::GetDisplayHandle(
        Scaleform::GFx::MovieImpl *this)
{
  return &this->hDisplayRoot;
}

// File Line: 749
// RVA: 0x906950
void __fastcall Scaleform::GFx::MovieImpl::SetCaptureThread(Scaleform::GFx::MovieImpl *this, void *captureThreadId)
{
  _((AMD_HD3D *)&this->RenderContext);
}

// File Line: 752
// RVA: 0x910860
void __fastcall Scaleform::GFx::MovieImpl::ShutdownRendering(Scaleform::GFx::MovieImpl *this, bool wait)
{
  Scaleform::Render::ContextImpl::Context::Shutdown(&this->RenderContext, wait);
}

// File Line: 754
// RVA: 0x8E7850
bool __fastcall Scaleform::GFx::MovieImpl::IsShutdownRenderingComplete(Scaleform::GFx::MovieImpl *this)
{
  Scaleform::Render::DrawableImageContext *pObject; // rax
  Scaleform::Render::ContextImpl::Context *RContext; // rcx
  bool result; // al

  result = 0;
  if ( Scaleform::Render::ContextImpl::Context::IsShutdownComplete(&this->RenderContext) )
  {
    pObject = this->DIContext.pObject;
    if ( !pObject )
      return 1;
    RContext = pObject->RContext;
    if ( !RContext || Scaleform::Render::ContextImpl::Context::IsShutdownComplete(RContext) )
      return 1;
  }
  return result;
}

// File Line: 803
// RVA: 0x8E12A0
void *__fastcall Scaleform::GFx::MovieImpl::GetUserData(Scaleform::GFx::MovieImpl *this)
{
  return this->UserData;
}

// File Line: 804
// RVA: 0x90E890
void __fastcall Scaleform::GFx::MovieImpl::SetUserData(Scaleform::GFx::MovieImpl *this, void *ud)
{
  this->UserData = ud;
}

// File Line: 811
// RVA: 0x7F91A0
bool __fastcall Scaleform::GFx::MovieImpl::IsShutdowning(Scaleform::GFx::MovieImpl *this)
{
  return !this->pRenderRoot.pObject || (this->Flags2 & 4) != 0;
}

// File Line: 836
// RVA: 0x8E7530
__int64 __fastcall Scaleform::GFx::MovieImpl::IsPaused(Scaleform::GFx::MovieImpl *this)
{
  return (this->Flags >> 20) & 1;
}

// File Line: 888
// RVA: 0x8DE430
Scaleform::GFx::MovieDefRootNode *__fastcall Scaleform::GFx::MovieImpl::GetStateBagImpl(
        Scaleform::GFx::MovieImpl *this)
{
  Scaleform::GFx::MovieDefRootNode *result; // rax

  result = this->RootMovieDefNodes.Root.pPrev;
  if ( result )
    return (Scaleform::GFx::MovieDefRootNode *)((char *)result + 16);
  return result;
}

// File Line: 893
// RVA: 0x8E7440
__int64 __fastcall Scaleform::GFx::MovieImpl::IsMovieFocused(Scaleform::GFx::MovieImpl *this)
{
  return (this->Flags >> 18) & 1;
}

// File Line: 1024
// RVA: 0x7E9800
Scaleform::Ptr<Scaleform::GFx::InteractiveObject> *__fastcall Scaleform::GFx::MovieImpl::GetFocusedCharacter(
        Scaleform::GFx::MovieImpl *this,
        Scaleform::Ptr<Scaleform::GFx::InteractiveObject> *result,
        unsigned int controllerIdx)
{
  Scaleform::GFx::Sprite *pObject; // rax
  Scaleform::Ptr<Scaleform::GFx::Sprite> resulta; // [rsp+40h] [rbp+8h] BYREF
  Scaleform::Ptr<Scaleform::GFx::InteractiveObject> *v7; // [rsp+48h] [rbp+10h]

  v7 = result;
  Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>::operator Scaleform::Ptr<Scaleform::GFx::DisplayObject>(
    (Scaleform::WeakPtr<Scaleform::GFx::Sprite> *)&this->FocusGroups[(unsigned __int8)this->FocusGroupIndexes[controllerIdx]].LastFocused,
    &resulta);
  pObject = resulta.pObject;
  if ( resulta.pObject )
  {
    ++resulta.pObject->RefCount;
    pObject = resulta.pObject;
  }
  result->pObject = pObject;
  if ( resulta.pObject )
    Scaleform::RefCountNTSImpl::Release(resulta.pObject);
  return result;
}

// File Line: 1037
// RVA: 0x700A60
bool __fastcall Scaleform::GFx::MovieImpl::IsKeyboardFocused(
        Scaleform::GFx::MovieImpl *this,
        Scaleform::GFx::Sprite *ch,
        unsigned int controllerIdx)
{
  __int64 v3; // rdi

  v3 = controllerIdx;
  return Scaleform::GFx::FocusGroupDescr::IsFocused(
           &this->FocusGroups[(unsigned __int8)this->FocusGroupIndexes[controllerIdx]],
           ch)
      && this->FocusGroups[(unsigned __int8)this->FocusGroupIndexes[v3]].FocusRectShown;
}

// File Line: 1137
// RVA: 0x8E6F40
__int64 __fastcall Scaleform::GFx::MovieImpl::IsExitRequested(Scaleform::GFx::MovieImpl *this)
{
  return (this->Flags >> 21) & 1;
}

// File Line: 1141
// RVA: 0x8B0020
__int64 __fastcall Scaleform::GFx::MovieImpl::AcceptAnimMovesWith3D(Scaleform::GFx::MovieImpl *this)
{
  return this->Flags2 & 1;
}

// File Line: 1170
// RVA: 0x90C1E0
void __fastcall Scaleform::GFx::MovieImpl::SetStageAutoOrients(Scaleform::GFx::MovieImpl *this, bool v)
{
  if ( v )
    this->Flags |= 0x4000u;
  else
    this->Flags &= ~0x4000u;
}

