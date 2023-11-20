// File Line: 108
// RVA: 0x8A7950
void __fastcall Scaleform::GFx::ShapeBaseCharacterDef::~ShapeBaseCharacterDef(Scaleform::GFx::ShapeBaseCharacterDef *this)
{
  Scaleform::GFx::ShapeBaseCharacterDef *v1; // rbx
  Scaleform::Render::ShapeMeshProvider *v2; // rcx

  v1 = this;
  this->vfptr = (Scaleform::GFx::ResourceVtbl *)&Scaleform::GFx::ShapeBaseCharacterDef::`vftable;
  v2 = this->pShapeMeshProvider.pObject;
  if ( v2 )
    ((void (__cdecl *)(Scaleform::Render::MeshProviderVtbl **))v2->vfptr->Release)(&v2->vfptr);
  v1->vfptr = (Scaleform::GFx::ResourceVtbl *)&Scaleform::GFx::CharacterDef::`vftable;
  v1->vfptr = (Scaleform::GFx::ResourceVtbl *)&Scaleform::GFx::Resource::`vftable;
}

// File Line: 126
// RVA: 0x8DDD00
signed __int64 __fastcall Scaleform::GFx::ShapeBaseCharacterDef::GetResourceTypeCode(Scaleform::GFx::ShapeBaseCharacterDef *this)
{
  return 34048i64;
}

// File Line: 131
// RVA: 0x8B8470
Scaleform::Ptr<Scaleform::Render::ShapeMeshProvider> *__fastcall Scaleform::GFx::ShapeBaseCharacterDef::BindResourcesInStyles(Scaleform::GFx::ShapeBaseCharacterDef *this, Scaleform::Ptr<Scaleform::Render::ShapeMeshProvider> *result, Scaleform::GFx::ResourceBinding *__formal)
{
  Scaleform::Ptr<Scaleform::Render::ShapeMeshProvider> *v3; // rbx
  Scaleform::GFx::ShapeBaseCharacterDef *v4; // rdi
  Scaleform::Render::ShapeMeshProvider *v5; // rcx

  v3 = result;
  v4 = this;
  v5 = this->pShapeMeshProvider.pObject;
  if ( v5 )
    (*((void (__fastcall **)(Scaleform::Render::MeshProviderVtbl **, Scaleform::Ptr<Scaleform::Render::ShapeMeshProvider> *, Scaleform::GFx::ResourceBinding *))&v5->vfptr->__vecDelDtor
     + 1))(
      &v5->vfptr,
      result,
      __formal);
  v3->pObject = (Scaleform::Render::ShapeMeshProvider *)v4->pShapeMeshProvider;
  return v3;
}

