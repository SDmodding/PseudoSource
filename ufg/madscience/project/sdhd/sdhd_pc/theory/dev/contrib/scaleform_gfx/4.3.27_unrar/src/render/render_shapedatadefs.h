// File Line: 119
// RVA: 0x77C260
void __fastcall Scaleform::Render::ComplexFill::ComplexFill(Scaleform::Render::ComplexFill *this)
{
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,71>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::Render::ComplexFill,71>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::ComplexFill::`vftable;
  this->pImage.pObject = 0i64;
  this->pGradient.pObject = 0i64;
  *(_OWORD *)&this->ImageMatrix.M[0][0] = 0x3F800000ui64;
  this->ImageMatrix.M[1][0] = 0.0;
  *(_QWORD *)&this->ImageMatrix.M[1][1] = 1065353216i64;
  this->ImageMatrix.M[1][3] = 0.0;
  this->FillMode.Fill = 0;
  this->BindIndex = -1;
}

// File Line: 121
// RVA: 0x895130
void __fastcall Scaleform::Render::ComplexFill::ComplexFill(Scaleform::Render::ComplexFill *this, Scaleform::Render::ComplexFill *o)
{
  Scaleform::Render::ComplexFill *v2; // rdi
  Scaleform::Render::ComplexFill *v3; // rbx
  Scaleform::Render::Image *v4; // rcx
  Scaleform::GFx::Resource *v5; // rcx

  v2 = o;
  v3 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,71>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::Render::ComplexFill,71>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::ComplexFill::`vftable;
  v4 = o->pImage.pObject;
  if ( v4 )
    ((void (__cdecl *)(Scaleform::Render::Image *))v4->vfptr[1].__vecDelDtor)(v4);
  v3->pImage.pObject = v2->pImage.pObject;
  v5 = (Scaleform::GFx::Resource *)v2->pGradient.pObject;
  if ( v5 )
    Scaleform::Render::RenderBuffer::AddRef(v5);
  v3->pGradient.pObject = v2->pGradient.pObject;
  v3->ImageMatrix.M[0][0] = v2->ImageMatrix.M[0][0];
  v3->ImageMatrix.M[0][1] = v2->ImageMatrix.M[0][1];
  v3->ImageMatrix.M[0][2] = v2->ImageMatrix.M[0][2];
  v3->ImageMatrix.M[0][3] = v2->ImageMatrix.M[0][3];
  v3->ImageMatrix.M[1][0] = v2->ImageMatrix.M[1][0];
  v3->ImageMatrix.M[1][1] = v2->ImageMatrix.M[1][1];
  v3->ImageMatrix.M[1][2] = v2->ImageMatrix.M[1][2];
  v3->ImageMatrix.M[1][3] = v2->ImageMatrix.M[1][3];
  v3->FillMode.Fill = v2->FillMode.Fill;
  v3->BindIndex = v2->BindIndex;
}

// File Line: 246
// RVA: 0x821780
void __fastcall Scaleform::Render::ShapeDataInterface::SkipPathData(Scaleform::Render::ShapeDataInterface *this, Scaleform::Render::ShapePosInfo *pos)
{
  Scaleform::Render::ShapePosInfo *v2; // rdi
  Scaleform::Render::ShapeDataInterface *v3; // rbx
  char v4; // [rsp+20h] [rbp-28h]

  v2 = pos;
  v3 = this;
  while ( ((unsigned int (__fastcall *)(Scaleform::Render::ShapeDataInterface *, Scaleform::Render::ShapePosInfo *, char *))v3->vfptr[9].__vecDelDtor)(
            v3,
            v2,
            &v4) )
    ;
}

