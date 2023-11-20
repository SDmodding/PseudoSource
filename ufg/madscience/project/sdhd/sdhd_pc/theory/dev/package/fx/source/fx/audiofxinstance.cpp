// File Line: 11
// RVA: 0x1C0DE0
void __fastcall Render::AudioFXInstance::AudioFXInstance(Render::AudioFXInstance *this)
{
  Render::AudioFXInstance *v1; // rbx
  UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance> *v2; // rax

  v1 = this;
  v2 = (UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance> *)&this->mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  this->vfptr = (Render::FXComponentInstanceVtbl *)&Render::FXComponentInstance::`vftable';
  *(_QWORD *)&this->mForceSuspendState = 0i64;
  *(_WORD *)&this->mIsActive = 0;
  this->vfptr = (Render::FXComponentInstanceVtbl *)&Render::AudioFXInstance::`vftable';
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&this->mSettingsHandle.mPrev);
  v1->mOneShot.m_pOneShot = 0i64;
}

// File Line: 15
// RVA: 0x1CD3E0
void __fastcall Render::AudioFXInstance::Init(Render::AudioFXInstance *this, unsigned int settingsId)
{
  UFG::qResourceInventory *v2; // rax
  unsigned int v3; // ebx
  Render::AudioFXInstance *v4; // rdi
  UFG::qResourceWarehouse *v5; // rax

  this->mSettingsId = settingsId;
  v2 = `UFG::qGetResourceInventory<Render::AudioFXSettings>'::`2'::result;
  v3 = settingsId;
  v4 = this;
  if ( !`UFG::qGetResourceInventory<Render::AudioFXSettings>'::`2'::result )
  {
    v5 = UFG::qResourceWarehouse::Instance();
    v2 = UFG::qResourceWarehouse::GetInventory(v5, 0xD77CCEB2);
    `UFG::qGetResourceInventory<Render::AudioFXSettings>'::`2'::result = v2;
  }
  UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v4->mSettingsHandle.mPrev, 0xD77CCEB2, v3, v2);
}

// File Line: 21
// RVA: 0x1C5430
void __fastcall Render::AudioFXInstance::Activate(Render::AudioFXInstance *this, int a2, int a3)
{
  Render::AudioFXInstance *v3; // rbx
  UFG::qResourceData *v4; // rsi
  Render::FXInstance *v5; // rax
  UFG::qMatrix44 *v6; // rdi
  UFG::qMatrix44 *v7; // rdx
  UFG::qMatrix44 dst; // [rsp+30h] [rbp-48h]

  v3 = this;
  if ( !this->mIsActive )
  {
    v4 = this->mSettingsHandle.mData;
    if ( v4 )
    {
      if ( Track<TriggerRecoilPostEffectTask>::DeleteTaskWhenItReturnsFalse((hkGeometryUtils::IVertices *)this, a2, a3) )
      {
        v5 = v3->mContainer;
        v6 = (UFG::qMatrix44 *)v5->mParentNode.m_pPointer;
        if ( !v6 || v5->mBasisRelativeToParent )
        {
          v7 = &v5->mBasis;
        }
        else
        {
          UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v5->mParentNode.m_pPointer);
          v7 = v6 + 2;
        }
        Render::FXInstance::CalcBasisHelper(
          &dst,
          v7,
          (UFG::qResourceHandle *)&v3->mContainer->mSettings.mPrev,
          v3->mComponentIndex,
          v3->mStartTime);
        if ( !UFG::OneShotHandle::IsValid(&v3->mOneShot) )
          UFG::OneShotPool::GetOneShotHandle(&v3->mOneShot, &dst);
        if ( UFG::OneShotHandle::IsValid(&v3->mOneShot) )
        {
          UFG::OneShot::Play(v3->mOneShot.m_pOneShot, (unsigned int)v4[1].mNode.mParent);
          v3->mIsActive = 1;
        }
      }
    }
  }
}

// File Line: 52
// RVA: 0x1CA800
void __fastcall Render::AudioFXInstance::Deactivate(Render::AudioFXInstance *this, bool willLoopImmediately)
{
  UFG::OneShotHandle *v2; // rbx
  UFG::OneShot *v3; // rax
  UFG::AudioEvent *v4; // rcx

  v2 = &this->mOneShot;
  this->mIsActive = 0;
  if ( UFG::OneShotHandle::IsValid(&this->mOneShot) )
  {
    v3 = v2->m_pOneShot;
    if ( v2->m_pOneShot->m_bIsInitialized )
    {
      if ( v3->m_controller.m_pEvent )
      {
        v4 = v3->m_controller.m_pEvent;
        if ( v4 )
          UFG::AudioEvent::StopAndForget(v4, 0x9C4u);
      }
    }
  }
}

// File Line: 70
// RVA: 0x1D5D30
void __fastcall Render::AudioFXInstance::Resume(Render::AudioFXInstance *this, float sim_time)
{
  UFG::AudioEntity **v2; // rbx

  v2 = (UFG::AudioEntity **)&this->mOneShot;
  if ( UFG::OneShotHandle::IsValid(&this->mOneShot) )
    UFG::AudioEntity::ResumeAllEvents(*v2);
}

// File Line: 80
// RVA: 0x1D87A0
void __fastcall Render::AudioFXInstance::Update(Render::AudioFXInstance *this, UFG::qVector3 *cam_pos, float sim_time)
{
  Render::AudioFXInstance *v3; // rdi
  Render::FXInstance *v4; // rax
  UFG::qMatrix44 *v5; // rbx
  UFG::qMatrix44 *v6; // rdx
  UFG::OneShot *v7; // rcx
  UFG::qVector4 v8; // xmm1
  UFG::qVector4 v9; // xmm0
  UFG::qMatrix44 dst; // [rsp+30h] [rbp-48h]

  v3 = this;
  if ( UFG::OneShotHandle::IsValid(&this->mOneShot) )
  {
    v4 = v3->mContainer;
    v5 = (UFG::qMatrix44 *)v4->mParentNode.m_pPointer;
    if ( !v5 || v4->mBasisRelativeToParent )
    {
      v6 = &v4->mBasis;
    }
    else
    {
      UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v4->mParentNode.m_pPointer);
      v6 = v5 + 2;
    }
    Render::FXInstance::CalcBasisHelper(
      &dst,
      v6,
      (UFG::qResourceHandle *)&v3->mContainer->mSettings.mPrev,
      v3->mComponentIndex,
      v3->mStartTime);
    v7 = v3->mOneShot.m_pOneShot;
    v8 = dst.v2;
    v7->m_WorldMatrix.v0 = dst.v0;
    v7->m_WorldMatrix.v1 = dst.v1;
    v9 = dst.v3;
    v7->m_WorldMatrix.v2 = v8;
    v7->m_WorldMatrix.v3 = v9;
    UFG::AudioEntity::ForcePositionUpdate((UFG::AudioEntity *)&v7->vfptr);
  }
}

