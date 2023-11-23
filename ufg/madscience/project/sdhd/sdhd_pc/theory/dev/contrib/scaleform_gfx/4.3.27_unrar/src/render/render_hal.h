// File Line: 71
// RVA: 0x9B2770
void __fastcall Scaleform::Render::StereoImplBase::SetParams(
        Scaleform::Render::StereoImplBase *this,
        Scaleform::Render::StereoParams *p)
{
  this->S3DParams = *p;
}

// File Line: 150
// RVA: 0x94AE20
void __fastcall Scaleform::Render::HALNotify::~HALNotify(Scaleform::Render::HALNotify *this)
{
  this->vfptr = (Scaleform::Render::HALNotifyVtbl *)&Scaleform::Render::HALNotify::`vftable;
}

// File Line: 251
// RVA: 0x997980
__int64 __fastcall Scaleform::Render::HAL::IsInitialized(Scaleform::Render::HAL *this)
{
  return this->HALState & 1;
}

// File Line: 289
// RVA: 0x9B5380
void __fastcall Scaleform::Render::HAL::SetUserMatrix(
        Scaleform::Render::HAL *this,
        Scaleform::Render::Matrix2x4<float> *m)
{
  this->Matrices.pObject->vfptr[3].__vecDelDtor(this->Matrices.pObject, (unsigned int)m);
}

// File Line: 290
// RVA: 0x9B5370
void __fastcall Scaleform::Render::HAL::SetUserMatrix(
        Scaleform::Render::HAL *this,
        Scaleform::Render::Matrix2x4<float> *user,
        Scaleform::Render::Matrix2x4<float> *user3D)
{
  ((void (__fastcall *)(Scaleform::Render::MatrixState *, Scaleform::Render::Matrix2x4<float> *, Scaleform::Render::Matrix2x4<float> *))this->Matrices.pObject->vfptr[2].__vecDelDtor)(
    this->Matrices.pObject,
    user,
    user3D);
}

// File Line: 297
// RVA: 0x98A250
Scaleform::Render::Matrix2x4<float> *__fastcall Scaleform::Render::HAL::GetOrientationMatrix(
        Scaleform::Render::HAL *this,
        Scaleform::Render::Matrix2x4<float> *result)
{
  *result = this->Matrices.pObject->Orient2D;
  return result;
}

// File Line: 310
// RVA: 0x98AF80
Scaleform::Render::RenderBufferManager *__fastcall Scaleform::Render::HAL::GetRenderBufferManager(
        Scaleform::Render::HAL *this)
{
  return this->pRenderBufferManager.pObject;
}

// File Line: 362
// RVA: 0x9AF1E0
void __fastcall RandomCondition::SetLevel(RandomCondition *this, unsigned int level)
{
  HIDWORD(this->IWeightedCondition::vfptr) = level;
}

// File Line: 363
// RVA: 0x982D30
unsigned __int64 __fastcall Scaleform::Render::FileImageSource::GetUse(UFG::qFileOp *this)
{
  return *(unsigned int *)this->mStatus;
}

// File Line: 583
// RVA: 0x98AD80
Scaleform::Render::RQCacheInterface *__fastcall Scaleform::Render::HAL::GetRQCacheInterface(
        Scaleform::Render::HAL *this)
{
  return &this->QueueProcessor.Caches;
}

// File Line: 619
// RVA: 0x9B3F00
void __fastcall Scaleform::Render::HAL::SetStereoImpl(
        Scaleform::Render::HAL *this,
        Scaleform::Render::StereoImplBase *simpl)
{
  Scaleform::Render::MatrixState *pObject; // rdi
  Scaleform::Render::StereoImplBase *v4; // rcx

  pObject = this->Matrices.pObject;
  if ( simpl )
    _InterlockedExchangeAdd(&simpl->RefCount, 1u);
  v4 = pObject->S3DImpl.pObject;
  if ( !v4 || _InterlockedDecrement(&v4->RefCount) )
  {
    pObject->S3DImpl.pObject = simpl;
  }
  else
  {
    v4->vfptr->__vecDelDtor(v4, 1u);
    pObject->S3DImpl.pObject = simpl;
  }
}

// File Line: 625
// RVA: 0x9B3F70
void __fastcall Scaleform::Render::HAL::SetStereoParams(
        Scaleform::Render::HAL *this,
        Scaleform::Render::StereoParams *sParams)
{
  __m128 v2; // xmm1
  Scaleform::Render::StereoImplBase *pObject; // rcx

  if ( sParams->DisplayWidthCm == 0.0 )
  {
    v2 = (__m128)(unsigned int)FLOAT_1_0;
    v2.m128_f32[0] = (float)((float)(1.0 / sParams->DisplayAspectRatio) * (float)(1.0 / sParams->DisplayAspectRatio))
                   + 1.0;
    sParams->DisplayWidthCm = (float)(sParams->DisplayDiagInches / _mm_sqrt_ps(v2).m128_f32[0]) * 2.54;
  }
  pObject = this->Matrices.pObject->S3DImpl.pObject;
  if ( pObject )
    ((void (__fastcall *)(Scaleform::Render::StereoImplBase *))pObject->vfptr[1].__vecDelDtor)(pObject);
}

// File Line: 638
// RVA: 0x9B3EE0
void __fastcall Scaleform::Render::HAL::SetStereoDisplay(
        Scaleform::Render::HAL *this,
        Scaleform::Render::StereoDisplay sDisplay,
        bool setstate)
{
  this->Matrices.pObject->S3DDisplay = sDisplay;
  this->Matrices.pObject->UVPOChanged = 1;
}

// File Line: 703
// RVA: 0x9EB750
void __fastcall Scaleform::Render::HAL::notifyHandlers(Scaleform::Render::HAL *this, unsigned int type)
{
  Scaleform::Render::HALNotify *pNext; // r8
  Scaleform::List<Scaleform::Render::HALNotify,Scaleform::Render::HALNotify> *p_NotifyList; // rdi
  __int64 v5; // rax
  Scaleform::Render::HALNotify *v6; // rbx

  pNext = this->NotifyList.Root.pNext;
  p_NotifyList = &this->NotifyList;
  while ( 1 )
  {
    v5 = p_NotifyList ? (__int64)&p_NotifyList[-1].Root.8 : 0i64;
    if ( pNext == (Scaleform::Render::HALNotify *)v5 )
      break;
    v6 = pNext->pNext;
    pNext->vfptr->OnHALEvent(pNext, (Scaleform::Render::HALNotifyType)type);
    pNext = v6;
  }
}

