// File Line: 16
// RVA: 0x1C1E50
void __fastcall Render::ScreenParticleEmitterInstance::ScreenParticleEmitterInstance(Render::ScreenParticleEmitterInstance *this)
{
  Render::ScreenParticleEmitterInstance *v1; // rbx
  UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance> *v2; // rax

  v1 = this;
  v2 = (UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance> *)&this->mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  this->vfptr = (Render::FXComponentInstanceVtbl *)&Render::FXComponentInstance::`vftable';
  *(_QWORD *)&this->mForceSuspendState = 0i64;
  *(_WORD *)&this->mIsActive = 0;
  this->vfptr = (Render::FXComponentInstanceVtbl *)&Render::ScreenParticleEmitterInstance::`vftable';
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&this->mSettingsHandle.mPrev);
  v1->mIsEmitting = 0;
  *(_QWORD *)&v1->mStartEmissionSimTime = 0i64;
}

// File Line: 20
// RVA: 0x1C46D0
void __fastcall Render::ScreenParticleEmitterInstance::~ScreenParticleEmitterInstance(Render::ScreenParticleEmitterInstance *this)
{
  Render::ScreenParticleEmitterInstance *v1; // rbx
  UFG::qResourceHandle *v2; // rdi
  UFG::qResourceInventory *v3; // rax
  UFG::qResourceWarehouse *v4; // rax
  UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance> *v5; // rdx
  UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance> *v6; // rcx
  UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance> *v7; // rax

  v1 = this;
  this->vfptr = (Render::FXComponentInstanceVtbl *)&Render::ScreenParticleEmitterInstance::`vftable';
  v2 = (UFG::qResourceHandle *)&this->mSettingsHandle.mPrev;
  v3 = `UFG::qGetResourceInventory<Render::ScreenParticleEmitterSettings>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<Render::ScreenParticleEmitterSettings>'::`2'::result )
  {
    v4 = UFG::qResourceWarehouse::Instance();
    v3 = UFG::qResourceWarehouse::GetInventory(v4, 0x354C3CDCu);
    `UFG::qGetResourceInventory<Render::ScreenParticleEmitterSettings>'::`2'::result = v3;
  }
  UFG::qResourceHandle::Close(v2, v3);
  UFG::qResourceHandle::~qResourceHandle(v2);
  v1->vfptr = (Render::FXComponentInstanceVtbl *)&Render::FXComponentInstance::`vftable';
  v5 = (UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance> *)&v1->mPrev;
  v6 = v1->mPrev;
  v7 = v1->mNext;
  v6->mNext = v7;
  v7->mPrev = v6;
  v5->mPrev = v5;
  v5->mNext = v5;
}

// File Line: 24
// RVA: 0x1CFB80
void __fastcall Render::ScreenParticleEmitterInstance::Init(Render::ScreenParticleEmitterInstance *this, unsigned int settingsId)
{
  UFG::qResourceInventory *v2; // rax
  unsigned int v3; // ebx
  Render::ScreenParticleEmitterInstance *v4; // rdi
  UFG::qResourceWarehouse *v5; // rax

  this->mSettingsId = settingsId;
  v2 = `UFG::qGetResourceInventory<Render::ScreenParticleEmitterSettings>'::`2'::result;
  v3 = settingsId;
  v4 = this;
  if ( !`UFG::qGetResourceInventory<Render::ScreenParticleEmitterSettings>'::`2'::result )
  {
    v5 = UFG::qResourceWarehouse::Instance();
    v2 = UFG::qResourceWarehouse::GetInventory(v5, 0x354C3CDCu);
    `UFG::qGetResourceInventory<Render::ScreenParticleEmitterSettings>'::`2'::result = v2;
  }
  UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v4->mSettingsHandle.mPrev, 0x354C3CDCu, v3, v2);
}

// File Line: 50
// RVA: 0x1D9B90
void __fastcall Render::ScreenParticleEmitterInstance::Update(Render::ScreenParticleEmitterInstance *this, UFG::qVector3 *cam_pos, float simTime)
{
  Render::ScreenParticleEmitterSettings *v3; // rdi
  UFG::qVector3 *v4; // rbp
  float v5; // xmm6_4
  Render::ScreenParticleEmitterInstance *v6; // rbx
  Render::FXInstance *v7; // rax
  UFG::SimComponent *v8; // rsi
  UFG::qMatrix44 *v9; // rdx
  __m128 v10; // xmm2
  unsigned int v11; // edx
  float v12; // xmm1_4
  int v13; // edx
  __int64 v14; // rbx
  UFG::qMatrix44 dst; // [rsp+30h] [rbp-58h]

  v3 = (Render::ScreenParticleEmitterSettings *)this->mSettingsHandle.mData;
  v4 = cam_pos;
  v5 = simTime;
  v6 = this;
  if ( v3 )
  {
    v7 = this->mContainer;
    v8 = v7->mParentNode.m_pPointer;
    if ( !v8 || v7->mBasisRelativeToParent )
    {
      v9 = &v7->mBasis;
    }
    else
    {
      UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v7->mParentNode.m_pPointer);
      v9 = (UFG::qMatrix44 *)&v8[2];
    }
    Render::FXInstance::CalcBasisHelper(
      &dst,
      v9,
      (UFG::qResourceHandle *)&v6->mContainer->mSettings.mPrev,
      v6->mComponentIndex,
      v6->mStartTime);
    v10 = (__m128)LODWORD(dst.v3.y);
    v10.m128_f32[0] = (float)((float)((float)(dst.v3.y - v4->y) * (float)(dst.v3.y - v4->y))
                            + (float)((float)(dst.v3.x - v4->x) * (float)(dst.v3.x - v4->x)))
                    + (float)((float)(dst.v3.z - v4->z) * (float)(dst.v3.z - v4->z));
    if ( COERCE_FLOAT(_mm_sqrt_ps(v10)) >= v3->mEmissionDistance )
    {
      v6->mIsEmitting = 0;
    }
    else
    {
      v11 = 0;
      if ( !v6->mIsEmitting )
      {
        v6->mStartEmissionSimTime = v5;
        v6->mParticlesEmitted = 0;
        v6->mIsEmitting = 1;
        v11 = v3->mEmissionInit;
      }
      v12 = (float)((float)(v5 - v6->mStartEmissionSimTime) * v3->mEmissionRate) - (float)v6->mParticlesEmitted;
      v13 = (signed int)v12 + v11;
      v6->mParticlesEmitted += (signed int)v12;
      if ( v13 > 0 )
      {
        v14 = (unsigned int)v13;
        do
        {
          Render::ScreenParticleEmitterManager::AddParticle(&Render::gScreenParticleEmitterManager, v3, v5);
          --v14;
        }
        while ( v14 );
      }
    }
  }
}

