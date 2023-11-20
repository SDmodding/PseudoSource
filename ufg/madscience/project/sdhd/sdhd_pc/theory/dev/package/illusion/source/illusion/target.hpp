// File Line: 50
// RVA: 0x2D370
void __fastcall Illusion::CreateTargetParams::CreateTargetParams(Illusion::CreateTargetParams *this, const char *in_name, unsigned int in_texture_type)
{
  unsigned int v3; // ebx
  Illusion::CreateTargetParams *v4; // rdi

  v3 = in_texture_type;
  v4 = this;
  UFG::qString::qString(&this->name, in_name);
  v4->texture_type = v3;
  *(_QWORD *)&v4->width = 0i64;
  v4->depth = 1;
  v4->array_size = 1;
  *(_DWORD *)v4->mrt_formats = -1;
  v4->num_mrt = 1;
  v4->target_flags = 0;
  v4->num_mips = 1;
  v4->textures[0] = 0i64;
  v4->textures[1] = 0i64;
  v4->textures[2] = 0i64;
  v4->textures[3] = 0i64;
  v4->depth_texture = 0i64;
  *(_QWORD *)v4->esram_offset = 0i64;
  *(_QWORD *)&v4->esram_offset[2] = 0i64;
  *(_QWORD *)v4->esram_usage_bytes = 0i64;
  *(_QWORD *)&v4->esram_usage_bytes[2] = 0i64;
  *(_QWORD *)&v4->esram_offset_depth = 0i64;
  *(_DWORD *)v4->use_esram = 0;
  v4->use_esram_depth = 0;
}

