// File Line: 509
// RVA: 0x98ACE0
void __fastcall Scaleform::Render::Color::GetRGBAFloat(Scaleform::Render::Color *this, float *pr, float *pg, float *pb, float *pa)
{
  unsigned __int8 v5; // al
  float v6; // xmm0_4
  unsigned __int8 v7; // al
  float v8; // xmm0_4
  float v9; // xmm0_4
  unsigned __int8 v10; // al

  v5 = this->Channels.Red;
  if ( v5 )
    v6 = (float)v5 * 0.0039215689;
  else
    v6 = 0.0;
  *pr = v6;
  v7 = this->Channels.Green;
  if ( v7 )
    v8 = (float)v7 * 0.0039215689;
  else
    v8 = 0.0;
  *pg = v8;
  if ( this->Channels.Blue )
    v9 = (float)(unsigned __int8)this->Channels.Blue * 0.0039215689;
  else
    v9 = 0.0;
  *pb = v9;
  v10 = this->Channels.Alpha;
  if ( v10 )
    *pa = (float)v10 * 0.0039215689;
  else
    *pa = 0.0;
}

