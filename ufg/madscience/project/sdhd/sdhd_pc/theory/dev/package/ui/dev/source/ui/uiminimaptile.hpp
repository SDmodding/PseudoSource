// File Line: 34
// RVA: 0xA23D10
void __fastcall UFG::UIMinimapTile::~UIMinimapTile(UFG::UIMinimapTile *this)
{
  UFG::UIMinimapTile *v1; // rbx
  UFG::qResourceHandle *v2; // rdi
  UFG::qResourceInventory *v3; // rax
  UFG::qResourceWarehouse *v4; // rax
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v5; // rcx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v6; // rax
  UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0> *v7; // [rsp+40h] [rbp+8h]

  v1 = this;
  v2 = (UFG::qResourceHandle *)&this->mMapTileHandle.mPrev;
  v3 = `UFG::qGetResourceInventory<Illusion::Texture>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Texture>::`2::result )
  {
    v4 = UFG::qResourceWarehouse::Instance();
    v3 = UFG::qResourceWarehouse::GetInventory(v4, 0x8B43FABF);
    `UFG::qGetResourceInventory<Illusion::Texture>::`2::result = v3;
  }
  UFG::qResourceHandle::Close(v2, v3);
  UFG::qResourceHandle::~qResourceHandle(v2);
  v7 = &v1->mResourceHandles;
  UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0>::DeleteNodes(&v1->mResourceHandles);
  v5 = v1->mResourceHandles.mNode.mPrev;
  v6 = v1->mResourceHandles.mNode.mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v7->mNode.mPrev = &v7->mNode;
  v7->mNode.mNext = &v7->mNode;
}

