// File Line: 108
// RVA: 0x8A7950
void __fastcall Scaleform::GFx::ShapeBaseCharacterDef::~ShapeBaseCharacterDef(
        Scaleform::GFx::ShapeBaseCharacterDef *this)
{
  Scaleform::Render::ShapeMeshProvider *pObject; // rcx

  this->vfptr = (Scaleform::GFx::ResourceVtbl *)&Scaleform::GFx::ShapeBaseCharacterDef::`vftable;
  pObject = this->pShapeMeshProvider.pObject;
  if ( pObject )
    pObject->Scaleform::Render::MeshProvider_KeySupport::Scaleform::Render::MeshProvider_RCImpl::Scaleform::Render::MeshProvider::vfptr->Release(&pObject->Scaleform::Render::MeshProvider);
  this->vfptr = (Scaleform::GFx::ResourceVtbl *)&Scaleform::GFx::CharacterDef::`vftable;
  this->vfptr = (Scaleform::GFx::ResourceVtbl *)&Scaleform::GFx::Resource::`vftable;
}

// File Line: 126
// RVA: 0x8DDD00
__int64 __fastcall Scaleform::GFx::ShapeBaseCharacterDef::GetResourceTypeCode(
        Scaleform::GFx::ShapeBaseCharacterDef *this)
{
  return 34048i64;
}

// File Line: 131
// RVA: 0x8B8470
Scaleform::Ptr<Scaleform::Render::ShapeMeshProvider> *__fastcall Scaleform::GFx::ShapeBaseCharacterDef::BindResourcesInStyles(
        Scaleform::GFx::ShapeBaseCharacterDef *this,
        Scaleform::Ptr<Scaleform::Render::ShapeMeshProvider> *result,
        Scaleform::GFx::ResourceBinding *__formal)
{
  Scaleform::Render::ShapeMeshProvider *pObject; // rcx

  pObject = this->pShapeMeshProvider.pObject;
  if ( pObject )
    (*((void (__fastcall **)(Scaleform::Render::MeshProvider *, Scaleform::Ptr<Scaleform::Render::ShapeMeshProvider> *, Scaleform::GFx::ResourceBinding *))&pObject->Scaleform::Render::MeshProvider_KeySupport::Scaleform::Render::MeshProvider_RCImpl::Scaleform::Render::MeshProvider::vfptr->__vecDelDtor
     + 1))(
      &pObject->Scaleform::Render::MeshProvider,
      result,
      __formal);
  result->pObject = (Scaleform::Render::ShapeMeshProvider *)this->pShapeMeshProvider;
  return result;
}

