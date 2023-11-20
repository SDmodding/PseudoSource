// File Line: 21
// RVA: 0x70B80
void __fastcall Render::CloudVolumeManager::~CloudVolumeManager(Render::CloudVolumeManager *this)
{
  Render::CloudVolumeManager *v1; // rbx
  UFG::qResourceHandle *v2; // rdi
  UFG::qResourceInventory *v3; // rax
  UFG::qResourceWarehouse *v4; // rax
  UFG::qResourceHandle *v5; // rbx
  UFG::qResourceInventory *v6; // rax
  UFG::qResourceWarehouse *v7; // rax

  v1 = this;
  v2 = (UFG::qResourceHandle *)&this->mStateBlockStormy.mPrev;
  v3 = `UFG::qGetResourceInventory<Illusion::StateBlock>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<Illusion::StateBlock>'::`2'::result )
  {
    v4 = UFG::qResourceWarehouse::Instance();
    v3 = UFG::qResourceWarehouse::GetInventory(v4, 0x4D04C7F2u);
    `UFG::qGetResourceInventory<Illusion::StateBlock>'::`2'::result = v3;
  }
  UFG::qResourceHandle::Close(v2, v3);
  UFG::qResourceHandle::~qResourceHandle(v2);
  v5 = (UFG::qResourceHandle *)&v1->mStateBlockSunny.mPrev;
  v6 = `UFG::qGetResourceInventory<Illusion::StateBlock>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<Illusion::StateBlock>'::`2'::result )
  {
    v7 = UFG::qResourceWarehouse::Instance();
    v6 = UFG::qResourceWarehouse::GetInventory(v7, 0x4D04C7F2u);
    `UFG::qGetResourceInventory<Illusion::StateBlock>'::`2'::result = v6;
  }
  UFG::qResourceHandle::Close(v5, v6);
  UFG::qResourceHandle::~qResourceHandle(v5);
}

