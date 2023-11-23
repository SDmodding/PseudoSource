// File Line: 509
// RVA: 0x98ACE0
void __fastcall Scaleform::Render::Color::GetRGBAFloat(
        Scaleform::Render::Color *this,
        float *pr,
        float *pg,
        float *pb,
        float *pa)
{
  unsigned __int8 Red; // al
  float v6; // xmm0_4
  unsigned __int8 Green; // al
  float v8; // xmm0_4
  float v9; // xmm0_4
  unsigned __int8 Alpha; // al

  Red = this->Channels.Red;
  if ( Red )
    v6 = (float)Red * 0.0039215689;
  else
    v6 = 0.0;
  *pr = v6;
  Green = this->Channels.Green;
  if ( Green )
    v8 = (float)Green * 0.0039215689;
  else
    v8 = 0.0;
  *pg = v8;
  if ( this->Channels.Blue )
    v9 = (float)(unsigned __int8)this->Channels.Blue * 0.0039215689;
  else
    v9 = 0.0;
  *pb = v9;
  Alpha = this->Channels.Alpha;
  if ( Alpha )
    *pa = (float)Alpha * 0.0039215689;
  else
    *pa = 0.0;
}

