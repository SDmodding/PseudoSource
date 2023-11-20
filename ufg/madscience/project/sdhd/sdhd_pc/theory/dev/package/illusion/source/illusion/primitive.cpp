// File Line: 35
// RVA: 0x956E0
bool __fastcall Illusion::Primitive::SetBuffers(Illusion::Primitive *this, Illusion::Primitive::Type prim_type, const void *vertices, const int num_vertices, Illusion::VertexDecl *decl, const void *indices, const int num_indices, const bool dupe_vertex_buffer)
{
  int v8; // er11

  this->mVertexStream = vertices;
  this->mVertexDecl = decl;
  this->mPrimType = prim_type;
  this->mNumVerts = num_vertices;
  this->mNumIndices = num_indices;
  v8 = num_vertices;
  this->mIndexStream = indices;
  this->mIndexSize = 2;
  if ( indices )
    v8 = num_indices;
  this->mNumPrims = (v8 - sPrimCount[prim_type][0]) / sPrimCount[prim_type][1];
  return Illusion::IPrimitivePlat::SetBuffers((Illusion::IPrimitivePlat *)this, dupe_vertex_buffer);
}

