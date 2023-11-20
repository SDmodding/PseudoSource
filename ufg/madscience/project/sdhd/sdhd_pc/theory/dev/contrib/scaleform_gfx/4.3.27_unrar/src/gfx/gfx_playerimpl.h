// File Line: 143
// RVA: 0x6D20F0
void __fastcall Scaleform::GFx::MovieDefRootNode::~MovieDefRootNode(Scaleform::GFx::MovieDefRootNode *this)
{
  Scaleform::Render::RenderBuffer *v1; // rcx

  this->vfptr = (Scaleform::GFx::MovieDefRootNodeVtbl *)&Scaleform::GFx::MovieDefRootNode::`vftable;
  v1 = (Scaleform::Render::RenderBuffer *)this->pFontManager.pObject;
  if ( v1 )
    Scaleform::RefCountImpl::Release(v1);
}

// File Line: 183
// RVA: 0x8A9400
bool __fastcall Scaleform::GFx::AutoTabSortFunctor::operator()(Scaleform::GFx::AutoTabSortFunctor *this, Scaleform::GFx::InteractiveObject *a, Scaleform::GFx::InteractiveObject *b)
{
  Scaleform::GFx::InteractiveObject *v3; // rcx
  Scaleform::GFx::InteractiveObject *v4; // rbx
  Scaleform::GFx::InteractiveObject *v5; // rdi
  float *v6; // rax
  __int64 v7; // kr00_8
  __int64 v8; // kr08_8
  float v9; // xmm0_4
  float v10; // xmm2_4
  Scaleform::GFx::DisplayObjectBase *v11; // rcx
  float *v12; // rax
  __int64 v13; // kr10_8
  __int64 v14; // kr18_8
  float v15; // xmm0_4
  float v16; // xmm2_4
  Scaleform::Render::Rect<float> *v17; // rax
  Scaleform::Render::Rect<float> *v18; // rax
  float v19; // xmm7_4
  float v20; // xmm8_4
  float v21; // xmm5_4
  float v22; // xmm4_4
  bool v23; // cf
  bool v24; // zf
  Scaleform::Render::Rect<float> v26; // [rsp+18h] [rbp-49h]
  Scaleform::Render::Rect<float> pr; // [rsp+28h] [rbp-39h]
  char v28; // [rsp+38h] [rbp-29h]
  Scaleform::Render::Matrix2x4<float> pmat; // [rsp+48h] [rbp-19h]
  Scaleform::Render::Matrix2x4<float> v30; // [rsp+68h] [rbp+7h]

  v3 = a->pParent;
  v4 = b;
  v5 = a;
  *(_OWORD *)&pmat.M[0][0] = _xmm;
  *(__m128 *)&pmat.M[1][0] = _xmm;
  if ( v3 )
  {
    Scaleform::GFx::DisplayObjectBase::GetLevelMatrix((Scaleform::GFx::DisplayObjectBase *)&v3->vfptr, &pmat);
    v6 = (float *)((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *))v5->vfptr[2].__vecDelDtor)(v5);
    v7 = *(_QWORD *)&pmat.M[0][0];
    v8 = *(_QWORD *)&pmat.M[1][0];
    pmat.M[0][0] = (float)(pmat.M[0][1] * v6[4]) + (float)(pmat.M[0][0] * *v6);
    pmat.M[1][0] = (float)(pmat.M[1][1] * v6[4]) + (float)(pmat.M[1][0] * *v6);
    pmat.M[0][1] = (float)(*(float *)&v7 * v6[1]) + (float)(pmat.M[0][1] * v6[5]);
    v9 = pmat.M[1][1] * v6[5];
    v10 = *(float *)&v8 * v6[1];
    pmat.M[0][2] = 0.0;
    *(_QWORD *)&pmat.M[1][1] = COERCE_UNSIGNED_INT(v10 + v9);
    pmat.M[0][3] = pmat.M[0][3] + (float)((float)(*((float *)&v7 + 1) * v6[7]) + (float)(*(float *)&v7 * v6[3]));
    pmat.M[1][3] = pmat.M[1][3] + (float)((float)(*((float *)&v8 + 1) * v6[7]) + (float)(*(float *)&v8 * v6[3]));
  }
  else
  {
    *(_OWORD *)&pmat.M[0][0] = _xmm;
    *(__m128 *)&pmat.M[1][0] = _xmm;
  }
  v11 = v4->pParentChar;
  *(_OWORD *)&v30.M[0][0] = _xmm;
  *(__m128 *)&v30.M[1][0] = _xmm;
  if ( v11 )
  {
    Scaleform::GFx::DisplayObjectBase::GetLevelMatrix(v11, &v30);
    v12 = (float *)((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *))v4->vfptr[2].__vecDelDtor)(v4);
    v13 = *(_QWORD *)&v30.M[0][0];
    v14 = *(_QWORD *)&v30.M[1][0];
    v30.M[0][0] = (float)(v30.M[0][0] * *v12) + (float)(v30.M[0][1] * v12[4]);
    v30.M[1][0] = (float)(v30.M[1][0] * *v12) + (float)(v30.M[1][1] * v12[4]);
    v30.M[0][1] = (float)(*(float *)&v13 * v12[1]) + (float)(v30.M[0][1] * v12[5]);
    v15 = v30.M[1][1] * v12[5];
    v16 = *(float *)&v14 * v12[1];
    v30.M[0][2] = 0.0;
    *(_QWORD *)&v30.M[1][1] = COERCE_UNSIGNED_INT(v16 + v15);
    v30.M[0][3] = v30.M[0][3] + (float)((float)(*((float *)&v13 + 1) * v12[7]) + (float)(*(float *)&v13 * v12[3]));
    v30.M[1][3] = v30.M[1][3] + (float)((float)(*((float *)&v14 + 1) * v12[7]) + (float)(*(float *)&v14 * v12[3]));
  }
  else
  {
    *(_OWORD *)&v30.M[0][0] = _xmm;
    *(__m128 *)&v30.M[1][0] = _xmm;
  }
  v17 = (Scaleform::Render::Rect<float> *)v5->vfptr[93].__vecDelDtor(
                                            (Scaleform::RefCountNTSImplCore *)&v5->vfptr,
                                            (unsigned int)&v28);
  Scaleform::Render::Matrix2x4<float>::EncloseTransform(&pmat, &pr, v17);
  v18 = (Scaleform::Render::Rect<float> *)v4->vfptr[93].__vecDelDtor(
                                            (Scaleform::RefCountNTSImplCore *)&v4->vfptr,
                                            (unsigned int)&v28);
  Scaleform::Render::Matrix2x4<float>::EncloseTransform(&v30, &v26, v18);
  v19 = (float)(pr.x2 + pr.x1) * 0.5;
  v20 = (float)(v26.x2 + v26.x1) * 0.5;
  v21 = (float)(v26.y2 + v26.y1) * 0.5;
  v22 = (float)(pr.y2 + pr.y1) * 0.5;
  if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(pr.y1 - v26.y1) & _xmm) <= 20.0
    || COERCE_FLOAT(COERCE_UNSIGNED_INT(pr.y2 - v26.y2) & _xmm) <= 20.0
    || COERCE_FLOAT(COERCE_UNSIGNED_INT(v22 - v21) & _xmm) <= 20.0 )
  {
    v23 = v20 < v19;
    v24 = v20 == v19;
  }
  else
  {
    v23 = v21 < v22;
    v24 = v21 == v22;
  }
  return !v23 && !v24;
}

// File Line: 214
// RVA: 0x6D0A70
void __fastcall Scaleform::GFx::ASIntervalTimerIntf::~ASIntervalTimerIntf(Scaleform::GFx::ASIntervalTimerIntf *this)
{
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::ASIntervalTimerIntf::`vftable;
  Scaleform::RefCountImplCore::~RefCountImplCore((Scaleform::RefCountImplCore *)&this->vfptr);
}

// File Line: 250
// RVA: 0x7009F0
_BOOL8 __fastcall Scaleform::GFx::FocusGroupDescr::IsFocused(Scaleform::GFx::FocusGroupDescr *this, Scaleform::GFx::InteractiveObject *ch)
{
  Scaleform::GFx::InteractiveObject *v2; // rdi
  Scaleform::GFx::Sprite *v3; // rbx
  bool v4; // di
  Scaleform::Ptr<Scaleform::GFx::Sprite> result; // [rsp+40h] [rbp+8h]
  Scaleform::GFx::Sprite *v7; // [rsp+48h] [rbp+10h]

  v2 = ch;
  Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>::operator Scaleform::Ptr<Scaleform::GFx::DisplayObject>(
    (Scaleform::WeakPtr<Scaleform::GFx::Sprite> *)&this->LastFocused,
    &result);
  v3 = result.pObject;
  if ( result.pObject )
  {
    ++result.pObject->RefCount;
    v3 = result.pObject;
  }
  v7 = v3;
  if ( result.pObject )
    Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&result.pObject->vfptr);
  v4 = v3 == (Scaleform::GFx::Sprite *)v2;
  if ( v3 )
    Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v3->vfptr);
  return v4;
}

// File Line: 310
// RVA: 0x6CD9F0
void __fastcall Scaleform::GFx::MovieImpl::WideStringStorage::WideStringStorage(Scaleform::GFx::MovieImpl::WideStringStorage *this, Scaleform::GFx::ASStringNode *pnode, unsigned __int64 dataSz)
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
  Scaleform::GFx::MovieImpl *v1; // rbx
  Scaleform::GFx::Resource **v2; // rdi
  Scaleform::Render::RenderBuffer *v3; // rcx
  Scaleform::Ptr<Scaleform::Log> result; // [rsp+40h] [rbp+8h]

  v1 = this;
  if ( (this->Flags >> 1) & 1 )
    return this->pCachedLog.pObject;
  v2 = (Scaleform::GFx::Resource **)Scaleform::GFx::StateBag::GetLog((Scaleform::GFx::StateBag *)&this->vfptr, &result);
  if ( *v2 )
    Scaleform::Render::RenderBuffer::AddRef(*v2);
  v3 = (Scaleform::Render::RenderBuffer *)v1->pCachedLog.pObject;
  if ( v3 )
    Scaleform::RefCountImpl::Release(v3);
  v1->pCachedLog.pObject = (Scaleform::Log *)*v2;
  if ( result.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)result.pObject);
  return v1->pCachedLog.pObject;
}

// File Line: 372
// RVA: 0x89C8B0
void __fastcall Scaleform::GFx::MovieImpl::ReturnValueHolder::ReturnValueHolder(Scaleform::GFx::MovieImpl::ReturnValueHolder *this, Scaleform::GFx::ASStringManager *pmgr)
{
  Scaleform::GFx::MovieImpl::ReturnValueHolder *v2; // rbx
  Scaleform::GFx::ASString *v3; // rax
  Scaleform::ArrayCC<Scaleform::GFx::ASString,323,Scaleform::ArrayDefaultPolicy> *v4; // rdx
  Scaleform::GFx::ASStringNode *v5; // rax
  Scaleform::GFx::ASStringNode *v6; // rcx
  bool v7; // zf
  Scaleform::GFx::ASString result; // [rsp+50h] [rbp+18h]
  Scaleform::ArrayCC<Scaleform::GFx::ASString,323,Scaleform::ArrayDefaultPolicy> *v9; // [rsp+58h] [rbp+20h]

  v2 = this;
  this->CharBuffer = 0i64;
  this->CharBufferSize = 0;
  v3 = Scaleform::GFx::ASStringManager::CreateConstString(pmgr, &result, &customWorldMapCaption);
  v4 = &v2->StringArray;
  v9 = v4;
  v4->Data.Data = 0i64;
  v4->Data.Size = 0i64;
  v4->Data.Policy.Capacity = 0i64;
  v5 = v3->pNode;
  v2->StringArray.Data.DefaultValue.pNode = v5;
  ++v5->RefCount;
  v6 = result.pNode;
  v7 = result.pNode->RefCount == 1;
  --v6->RefCount;
  if ( v7 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v6);
  v2->StringArrayPos = 0;
}

// File Line: 433
// RVA: 0x6D25A0
void __fastcall Scaleform::GFx::MovieImpl::StickyVarNode::~StickyVarNode(Scaleform::GFx::MovieImpl::StickyVarNode *this)
{
  Scaleform::GFx::ASStringNode *v1; // rcx
  bool v2; // zf

  this->vfptr = (Scaleform::GFx::MovieImpl::StickyVarNodeVtbl *)&Scaleform::GFx::MovieImpl::StickyVarNode::`vftable;
  v1 = this->Name.pNode;
  v2 = v1->RefCount-- == 1;
  if ( v2 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v1);
}

// File Line: 436
// RVA: 0x6DAB50
void __fastcall Scaleform::GFx::MovieImpl::StickyVarNode::Assign(Scaleform::GFx::MovieImpl::StickyVarNode *this, Scaleform::GFx::MovieImpl::StickyVarNode *node)
{
  Scaleform::GFx::ASStringNode *v2; // rdi
  Scaleform::GFx::MovieImpl::StickyVarNode *v3; // rbx
  Scaleform::GFx::MovieImpl::StickyVarNode *v4; // rsi
  Scaleform::GFx::ASStringNode *v5; // rcx
  bool v6; // zf

  v2 = node->Name.pNode;
  v3 = this;
  v4 = node;
  ++v2->RefCount;
  v5 = this->Name.pNode;
  v6 = v5->RefCount-- == 1;
  if ( v6 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v5);
  v3->Name.pNode = v2;
  v3->Permanent = v4->Permanent;
}

// File Line: 628
// RVA: 0x9099E0
void __fastcall Scaleform::GFx::MovieImpl::SetMouseCursorCount(Scaleform::GFx::MovieImpl *this, unsigned int n)
{
  signed int v2; // eax

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
  signed int v2; // eax

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
Scaleform::Render::Rect<float> *__fastcall Scaleform::GFx::MovieImpl::GetVisibleFrameRect(Scaleform::GFx::MovieImpl *this, Scaleform::Render::Rect<float> *result)
{
  Scaleform::Render::Rect<float> *v2; // rax
  float v3; // xmm1_4
  float v4; // xmm0_4

  v2 = result;
  v3 = this->VisibleFrameRect.x2 * 0.050000001;
  result->x1 = this->VisibleFrameRect.x1 * 0.050000001;
  v4 = this->VisibleFrameRect.y1;
  result->x2 = v3;
  result->y1 = v4 * 0.050000001;
  result->y2 = this->VisibleFrameRect.y2 * 0.050000001;
  return v2;
}

// File Line: 713
// RVA: 0x8DDE70
Scaleform::Render::Rect<float> *__fastcall Scaleform::GFx::MovieImpl::GetSafeRect(Scaleform::GFx::MovieImpl *this, Scaleform::Render::Rect<float> *result)
{
  result->x1 = this->SafeRect.x1;
  result->y1 = this->SafeRect.y1;
  result->x2 = this->SafeRect.x2;
  result->y2 = this->SafeRect.y2;
  return result;
}

// File Line: 714
// RVA: 0x90B4F0
void __fastcall Scaleform::GFx::MovieImpl::SetSafeRect(Scaleform::GFx::MovieImpl *this, Scaleform::Render::Rect<float> *rect)
{
  float v2; // eax
  float v3; // xmm2_4
  float v4; // xmm0_4

  v2 = rect->x1;
  v3 = rect->y2;
  v4 = rect->y1;
  this->SafeRect.x2 = rect->x2;
  this->SafeRect.y2 = v3;
  this->SafeRect.x1 = v2;
  this->SafeRect.y1 = v4;
}

// File Line: 716
// RVA: 0x906FB0
void __fastcall Scaleform::GFx::MovieImpl::SetEdgeAAMode(Scaleform::GFx::MovieImpl *this, Scaleform::Render::EdgeAAMode edgeAA)
{
  Scaleform::Render::TreeNode::SetEdgeAAMode((Scaleform::Render::TreeNode *)&this->pRenderRoot.pObject->0, edgeAA);
}

// File Line: 717
// RVA: 0x8D7380
__int64 __fastcall Scaleform::GFx::MovieImpl::GetEdgeAAMode(Scaleform::GFx::MovieImpl *this)
{
  return *(_WORD *)(*(_QWORD *)(*(_QWORD *)(((_QWORD)this->pRenderRoot.pObject & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                              + 8
                              * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&this->pRenderRoot.pObject[-1] - ((_QWORD)this->pRenderRoot.pObject & 0xFFFFFFFFFFFFF000ui64))
                                                                                   * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                               + ((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&this->pRenderRoot.pObject[-1]
                                                                                        - ((_QWORD)this->pRenderRoot.pObject & 0xFFFFFFFFFFFFF000ui64))
                                                                       * (signed __int128)5270498306774157605i64) >> 64) >> 63))
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
    this->Flags &= 0xFFFFFFFB;
}

// File Line: 729
// RVA: 0x906190
void __fastcall Scaleform::GFx::MovieImpl::SetActionErrorsSuppress(Scaleform::GFx::MovieImpl *this, bool suppressActionErrors)
{
  if ( suppressActionErrors )
    this->Flags |= 0x40u;
  else
    this->Flags &= 0xFFFFFFBF;
}

// File Line: 733
// RVA: 0x8D4D40
float __fastcall Scaleform::GFx::MovieImpl::GetBackgroundAlpha(Scaleform::GFx::MovieImpl *this)
{
  return (float)(unsigned __int8)this->BackgroundColor.Channels.Alpha * 0.0039215689;
}

// File Line: 747
// RVA: 0x8D6CD0
Scaleform::Render::ContextImpl::DisplayHandle<Scaleform::Render::TreeRoot> *__fastcall Scaleform::GFx::MovieImpl::GetDisplayHandle(Scaleform::GFx::MovieImpl *this)
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
  Scaleform::GFx::MovieImpl *v1; // rbx
  Scaleform::Render::DrawableImageContext *v2; // rax
  Scaleform::Render::ContextImpl::Context *v3; // rcx
  bool result; // al

  v1 = this;
  result = 0;
  if ( Scaleform::Render::ContextImpl::Context::IsShutdownComplete(&this->RenderContext) )
  {
    v2 = v1->DIContext.pObject;
    if ( !v2 || (v3 = v2->RContext) == 0i64 || Scaleform::Render::ContextImpl::Context::IsShutdownComplete(v3) )
      result = 1;
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
  return !this->pRenderRoot.pObject || (this->Flags2 >> 2) & 1;
}

// File Line: 836
// RVA: 0x8E7530
__int64 __fastcall Scaleform::GFx::MovieImpl::IsPaused(Scaleform::GFx::MovieImpl *this)
{
  return (this->Flags >> 20) & 1;
}

// File Line: 888
// RVA: 0x8DE430
Scaleform::GFx::MovieDefRootNode *__fastcall Scaleform::GFx::MovieImpl::GetStateBagImpl(Scaleform::GFx::MovieImpl *this)
{
  Scaleform::GFx::MovieDefRootNode *result; // rax

  result = this->RootMovieDefNodes.Root.pPrev;
  if ( result )
    result = (Scaleform::GFx::MovieDefRootNode *)((char *)result + 16);
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
Scaleform::Ptr<Scaleform::GFx::InteractiveObject> *__fastcall Scaleform::GFx::MovieImpl::GetFocusedCharacter(Scaleform::GFx::MovieImpl *this, Scaleform::Ptr<Scaleform::GFx::InteractiveObject> *result, unsigned int controllerIdx)
{
  Scaleform::Ptr<Scaleform::GFx::InteractiveObject> *v3; // rbx
  Scaleform::GFx::Sprite *v4; // rax
  Scaleform::Ptr<Scaleform::GFx::Sprite> resulta; // [rsp+40h] [rbp+8h]
  Scaleform::Ptr<Scaleform::GFx::InteractiveObject> *v7; // [rsp+48h] [rbp+10h]

  v7 = result;
  v3 = result;
  Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>::operator Scaleform::Ptr<Scaleform::GFx::DisplayObject>(
    (Scaleform::WeakPtr<Scaleform::GFx::Sprite> *)&this->FocusGroups[(unsigned __int8)this->FocusGroupIndexes[controllerIdx]].LastFocused,
    &resulta);
  v4 = resulta.pObject;
  if ( resulta.pObject )
  {
    ++resulta.pObject->RefCount;
    v4 = resulta.pObject;
  }
  v3->pObject = (Scaleform::GFx::InteractiveObject *)&v4->vfptr;
  if ( resulta.pObject )
    Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&resulta.pObject->vfptr);
  return v3;
}

// File Line: 1037
// RVA: 0x700A60
bool __fastcall Scaleform::GFx::MovieImpl::IsKeyboardFocused(Scaleform::GFx::MovieImpl *this, Scaleform::GFx::InteractiveObject *ch, unsigned int controllerIdx)
{
  __int64 v3; // rdi
  Scaleform::GFx::MovieImpl *v4; // rbx

  v3 = controllerIdx;
  v4 = this;
  return (unsigned __int8)Scaleform::GFx::FocusGroupDescr::IsFocused(
                            &this->FocusGroups[(unsigned __int8)this->FocusGroupIndexes[controllerIdx]],
                            ch)
      && v4->FocusGroups[(unsigned __int8)v4->FocusGroupIndexes[v3]].FocusRectShown;
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
    this->Flags &= 0xFFFFBFFF;
}

