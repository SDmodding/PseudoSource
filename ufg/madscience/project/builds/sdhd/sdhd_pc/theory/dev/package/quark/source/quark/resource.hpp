// File Line: 328
// RVA: 0x333650
void __fastcall UFG::qTypedResourceHandle<1139384190,UFG::AISidewalkSectionResource>::~qTypedResourceHandle<1139384190,UFG::AISidewalkSectionResource>(UFG::qTypedResourceHandle<1139384190,UFG::AISidewalkSectionResource> *this)
{
  UFG::qTypedResourceHandle<1139384190,UFG::AISidewalkSectionResource> *v1; // rbx
  UFG::qResourceInventory *v2; // rax
  UFG::qResourceWarehouse *v3; // rax

  v1 = this;
  v2 = `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>'::`2'::result )
  {
    v3 = UFG::qResourceWarehouse::Instance();
    v2 = UFG::qResourceWarehouse::GetInventory(v3, 0x43E99F7Eu);
    `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>'::`2'::result = v2;
  }
  UFG::qResourceHandle::Close((UFG::qResourceHandle *)&v1->mPrev, v2);
  UFG::qResourceHandle::~qResourceHandle((UFG::qResourceHandle *)&v1->mPrev);
}

