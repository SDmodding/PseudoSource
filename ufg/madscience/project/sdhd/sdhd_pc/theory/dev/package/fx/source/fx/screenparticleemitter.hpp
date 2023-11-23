// File Line: 152
// RVA: 0x1C4770
void __fastcall Render::ScreenParticleEmitterManager::~ScreenParticleEmitterManager(
        Render::ScreenParticleEmitterManager *this)
{
  UFG::qNode<Render::ScreenParticleEmitterManager::ScreenParticle,Render::ScreenParticleEmitterManager::ScreenParticle> *mPrev; // rcx
  UFG::qNode<Render::ScreenParticleEmitterManager::ScreenParticle,Render::ScreenParticleEmitterManager::ScreenParticle> *mNext; // rax
  UFG::qNode<Render::ScreenParticleEmitterManager::ScreenParticle,Render::ScreenParticleEmitterManager::ScreenParticle> *v4; // rcx
  UFG::qNode<Render::ScreenParticleEmitterManager::ScreenParticle,Render::ScreenParticleEmitterManager::ScreenParticle> *v5; // rax
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v7; // rax

  `eh vector destructor iterator(
    this->mBuffer,
    0x58ui64,
    128,
    (void (__fastcall *)(void *))UFG::TargetSphere::~TargetSphere);
  UFG::qList<UFG::FractureConnectivity::Connection,UFG::FractureConnectivity::Connection,1,0>::DeleteNodes((UFG::qList<UFG::qReflectField,UFG::qReflectField,1,0> *)&this->mInactiveList);
  mPrev = this->mInactiveList.mNode.mPrev;
  mNext = this->mInactiveList.mNode.mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->mInactiveList.mNode.mPrev = &this->mInactiveList.mNode;
  this->mInactiveList.mNode.mNext = &this->mInactiveList.mNode;
  UFG::qList<UFG::FractureConnectivity::Connection,UFG::FractureConnectivity::Connection,1,0>::DeleteNodes((UFG::qList<UFG::qReflectField,UFG::qReflectField,1,0> *)&this->mActiveList);
  v4 = this->mActiveList.mNode.mPrev;
  v5 = this->mActiveList.mNode.mNext;
  v4->mNext = v5;
  v5->mPrev = v4;
  this->mActiveList.mNode.mPrev = &this->mActiveList.mNode;
  this->mActiveList.mNode.mNext = &this->mActiveList.mNode;
  Inventory = `UFG::qGetResourceInventory<Illusion::VertexDecl>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::VertexDecl>::`2::result )
  {
    v7 = UFG::qResourceWarehouse::Instance();
    Inventory = UFG::qResourceWarehouse::GetInventory(v7, 0x3E5FDA3Eu);
    `UFG::qGetResourceInventory<Illusion::VertexDecl>::`2::result = Inventory;
  }
  UFG::qResourceHandle::Close(&this->mVertexDeclHandle, Inventory);
  UFG::qResourceHandle::~qResourceHandle(&this->mVertexDeclHandle);
}

