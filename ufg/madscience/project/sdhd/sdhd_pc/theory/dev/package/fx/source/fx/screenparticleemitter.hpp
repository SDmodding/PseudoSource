// File Line: 152
// RVA: 0x1C4770
void __fastcall Render::ScreenParticleEmitterManager::~ScreenParticleEmitterManager(Render::ScreenParticleEmitterManager *this)
{
  Render::ScreenParticleEmitterManager *v1; // rdi
  UFG::qNode<Render::ScreenParticleEmitterManager::ScreenParticle,Render::ScreenParticleEmitterManager::ScreenParticle> *v2; // rcx
  UFG::qNode<Render::ScreenParticleEmitterManager::ScreenParticle,Render::ScreenParticleEmitterManager::ScreenParticle> *v3; // rax
  UFG::qNode<Render::ScreenParticleEmitterManager::ScreenParticle,Render::ScreenParticleEmitterManager::ScreenParticle> *v4; // rcx
  UFG::qNode<Render::ScreenParticleEmitterManager::ScreenParticle,Render::ScreenParticleEmitterManager::ScreenParticle> *v5; // rax
  UFG::qResourceInventory *v6; // rax
  UFG::qResourceWarehouse *v7; // rax

  v1 = this;
  `eh vector destructor iterator'(
    this->mBuffer,
    0x58ui64,
    128,
    (void (__fastcall *)(void *))UFG::TargetSphere::~TargetSphere);
  UFG::qList<UFG::FractureConnectivity::Connection,UFG::FractureConnectivity::Connection,1,0>::DeleteNodes((UFG::qList<UFG::qReflectField,UFG::qReflectField,1,0> *)&v1->mInactiveList);
  v2 = v1->mInactiveList.mNode.mPrev;
  v3 = v1->mInactiveList.mNode.mNext;
  v2->mNext = v3;
  v3->mPrev = v2;
  v1->mInactiveList.mNode.mPrev = &v1->mInactiveList.mNode;
  v1->mInactiveList.mNode.mNext = &v1->mInactiveList.mNode;
  UFG::qList<UFG::FractureConnectivity::Connection,UFG::FractureConnectivity::Connection,1,0>::DeleteNodes((UFG::qList<UFG::qReflectField,UFG::qReflectField,1,0> *)&v1->mActiveList);
  v4 = v1->mActiveList.mNode.mPrev;
  v5 = v1->mActiveList.mNode.mNext;
  v4->mNext = v5;
  v5->mPrev = v4;
  v1->mActiveList.mNode.mPrev = &v1->mActiveList.mNode;
  v1->mActiveList.mNode.mNext = &v1->mActiveList.mNode;
  v6 = `UFG::qGetResourceInventory<Illusion::VertexDecl>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<Illusion::VertexDecl>'::`2'::result )
  {
    v7 = UFG::qResourceWarehouse::Instance();
    v6 = UFG::qResourceWarehouse::GetInventory(v7, 0x3E5FDA3Eu);
    `UFG::qGetResourceInventory<Illusion::VertexDecl>'::`2'::result = v6;
  }
  UFG::qResourceHandle::Close((UFG::qResourceHandle *)&v1->mVertexDeclHandle.mPrev, v6);
  UFG::qResourceHandle::~qResourceHandle((UFG::qResourceHandle *)&v1->mVertexDeclHandle.mPrev);
}

