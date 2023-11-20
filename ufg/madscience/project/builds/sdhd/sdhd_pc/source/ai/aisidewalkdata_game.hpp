// File Line: 52
// RVA: 0x387FB0
void __fastcall UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game>::SetToNull(UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game> *this)
{
  UFG::qResourceInventory *v1; // rax
  UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game> *v2; // rbx
  UFG::qResourceWarehouse *v3; // rax

  this->mPtr = 0i64;
  v1 = `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>'::`2'::result;
  v2 = this;
  if ( !`UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>'::`2'::result )
  {
    v3 = UFG::qResourceWarehouse::Instance();
    v1 = UFG::qResourceWarehouse::GetInventory(v3, 0x43E99F7Eu);
    `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>'::`2'::result = v1;
  }
  UFG::qResourceHandle::Close((UFG::qResourceHandle *)&v2->mPrev, v1);
  v2->mObjUID = -1;
  v2->mIndex = -1;
  v2->mNameUID = -1;
  v2->mPtr = 0i64;
}

