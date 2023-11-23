// File Line: 11
// RVA: 0x1C0DE0
void __fastcall Render::AudioFXInstance::AudioFXInstance(Render::AudioFXInstance *this)
{
  this->mPrev = &this->UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance>;
  this->mNext = &this->UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance>;
  this->vfptr = (Render::FXComponentInstanceVtbl *)&Render::FXComponentInstance::`vftable;
  *(_QWORD *)&this->mForceSuspendState = 0i64;
  *(_WORD *)&this->mIsActive = 0;
  this->vfptr = (Render::FXComponentInstanceVtbl *)&Render::AudioFXInstance::`vftable;
  UFG::qResourceHandle::qResourceHandle(&this->mSettingsHandle);
  this->mOneShot.m_pOneShot = 0i64;
}

// File Line: 15
// RVA: 0x1CD3E0
void __fastcall Render::AudioFXInstance::Init(Render::AudioFXInstance *this, unsigned int settingsId)
{
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v5; // rax

  this->mSettingsId = settingsId;
  Inventory = `UFG::qGetResourceInventory<Render::AudioFXSettings>::`2::result;
  if ( !`UFG::qGetResourceInventory<Render::AudioFXSettings>::`2::result )
  {
    v5 = UFG::qResourceWarehouse::Instance();
    Inventory = UFG::qResourceWarehouse::GetInventory(v5, 0xD77CCEB2);
    `UFG::qGetResourceInventory<Render::AudioFXSettings>::`2::result = Inventory;
  }
  UFG::qResourceHandle::Init(&this->mSettingsHandle, 0xD77CCEB2, settingsId, Inventory);
}

// File Line: 21
// RVA: 0x1C5430
void __fastcall Render::AudioFXInstance::Activate(Render::AudioFXInstance *this, int a2, int a3)
{
  UFG::qResourceData *mData; // rsi
  Render::FXInstance *mContainer; // rax
  UFG::SimComponent *m_pPointer; // rdi
  UFG::qMatrix44 *p_mBasis; // rdx
  UFG::qMatrix44 dst; // [rsp+30h] [rbp-48h] BYREF

  if ( !this->mIsActive )
  {
    mData = this->mSettingsHandle.mData;
    if ( mData )
    {
      if ( Track<TriggerRecoilPostEffectTask>::DeleteTaskWhenItReturnsFalse((hkGeometryUtils::IVertices *)this, a2, a3) )
      {
        mContainer = this->mContainer;
        m_pPointer = mContainer->mParentNode.m_pPointer;
        if ( !m_pPointer || mContainer->mBasisRelativeToParent )
        {
          p_mBasis = &mContainer->mBasis;
        }
        else
        {
          UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)mContainer->mParentNode.m_pPointer);
          p_mBasis = (UFG::qMatrix44 *)&m_pPointer[2];
        }
        Render::FXInstance::CalcBasisHelper(
          &dst,
          p_mBasis,
          &this->mContainer->mSettings,
          this->mComponentIndex,
          this->mStartTime);
        if ( !UFG::OneShotHandle::IsValid(&this->mOneShot) )
          UFG::OneShotPool::GetOneShotHandle(&this->mOneShot, &dst);
        if ( UFG::OneShotHandle::IsValid(&this->mOneShot) )
        {
          UFG::OneShot::Play(this->mOneShot.m_pOneShot, (unsigned int)mData[1].mNode.mParent);
          this->mIsActive = 1;
        }
      }
    }
  }
}

// File Line: 52
// RVA: 0x1CA800
void __fastcall Render::AudioFXInstance::Deactivate(Render::AudioFXInstance *this, bool willLoopImmediately)
{
  UFG::OneShotHandle *p_mOneShot; // rbx
  UFG::OneShot *m_pOneShot; // rax
  UFG::AudioEvent *m_pEvent; // rcx

  p_mOneShot = &this->mOneShot;
  this->mIsActive = 0;
  if ( UFG::OneShotHandle::IsValid(&this->mOneShot) )
  {
    m_pOneShot = p_mOneShot->m_pOneShot;
    if ( p_mOneShot->m_pOneShot->m_bIsInitialized )
    {
      if ( m_pOneShot->m_controller.m_pEvent )
      {
        m_pEvent = m_pOneShot->m_controller.m_pEvent;
        if ( m_pEvent )
          UFG::AudioEvent::StopAndForget(m_pEvent, 2500);
      }
    }
  }
}

// File Line: 70
// RVA: 0x1D5D30
void __fastcall Render::AudioFXInstance::Resume(Render::AudioFXInstance *this, float sim_time)
{
  UFG::OneShotHandle *p_mOneShot; // rbx

  p_mOneShot = &this->mOneShot;
  if ( UFG::OneShotHandle::IsValid(&this->mOneShot) )
    UFG::AudioEntity::ResumeAllEvents(p_mOneShot->m_pOneShot);
}

// File Line: 80
// RVA: 0x1D87A0
void __fastcall Render::AudioFXInstance::Update(Render::AudioFXInstance *this, UFG::qVector3 *cam_pos, float sim_time)
{
  Render::FXInstance *mContainer; // rax
  UFG::SimComponent *m_pPointer; // rbx
  UFG::qMatrix44 *p_mBasis; // rdx
  UFG::OneShot *m_pOneShot; // rcx
  UFG::qVector4 v8; // xmm1
  UFG::qVector4 v9; // xmm0
  UFG::qMatrix44 dst; // [rsp+30h] [rbp-48h] BYREF

  if ( UFG::OneShotHandle::IsValid(&this->mOneShot) )
  {
    mContainer = this->mContainer;
    m_pPointer = mContainer->mParentNode.m_pPointer;
    if ( !m_pPointer || mContainer->mBasisRelativeToParent )
    {
      p_mBasis = &mContainer->mBasis;
    }
    else
    {
      UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)mContainer->mParentNode.m_pPointer);
      p_mBasis = (UFG::qMatrix44 *)&m_pPointer[2];
    }
    Render::FXInstance::CalcBasisHelper(
      &dst,
      p_mBasis,
      &this->mContainer->mSettings,
      this->mComponentIndex,
      this->mStartTime);
    m_pOneShot = this->mOneShot.m_pOneShot;
    v8 = dst.v2;
    m_pOneShot->m_WorldMatrix.v0 = dst.v0;
    m_pOneShot->m_WorldMatrix.v1 = dst.v1;
    v9 = dst.v3;
    m_pOneShot->m_WorldMatrix.v2 = v8;
    m_pOneShot->m_WorldMatrix.v3 = v9;
    UFG::AudioEntity::ForcePositionUpdate(m_pOneShot);
  }
}

