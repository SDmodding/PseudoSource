// File Line: 50
// RVA: 0x2D370
void __fastcall Illusion::CreateTargetParams::CreateTargetParams(
        Illusion::CreateTargetParams *this,
        const char *in_name,
        unsigned int in_texture_type)
{
  UFG::qString::qString(&this->name, in_name);
  this->texture_type = in_texture_type;
  *(_QWORD *)&this->width = 0i64;
  this->depth = 1;
  this->array_size = 1;
  *(_DWORD *)this->mrt_formats = -1;
  this->num_mrt = 1;
  this->target_flags = 0;
  this->num_mips = 1;
  this->textures[0] = 0i64;
  this->textures[1] = 0i64;
  this->textures[2] = 0i64;
  this->textures[3] = 0i64;
  this->depth_texture = 0i64;
  *(_QWORD *)this->esram_offset = 0i64;
  *(_QWORD *)&this->esram_offset[2] = 0i64;
  *(_QWORD *)this->esram_usage_bytes = 0i64;
  *(_QWORD *)&this->esram_usage_bytes[2] = 0i64;
  *(_QWORD *)&this->esram_offset_depth = 0i64;
  *(_DWORD *)this->use_esram = 0;
  this->use_esram_depth = 0;
}

