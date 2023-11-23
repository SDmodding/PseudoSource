// File Line: 149
// RVA: 0x9976B0
bool __fastcall Scaleform::List<Scaleform::Render::MeshKeySet,Scaleform::Render::MeshKeySet>::IsEmpty(
        Scaleform::List<Scaleform::Render::MeshKeySet,Scaleform::Render::MeshKeySet> *this)
{
  Scaleform::Render::MeshKeySet *v1; // rdx

  v1 = (Scaleform::Render::MeshKeySet *)&this[-1].Root.8;
  if ( !this )
    v1 = 0i64;
  return this->Root.pNext == v1;
}

