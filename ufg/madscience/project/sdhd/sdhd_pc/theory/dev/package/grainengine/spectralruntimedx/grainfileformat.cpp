// File Line: 8
// RVA: 0x15C230
void __fastcall GrainFileHeader::Fixup(GrainFileHeader *this, char *data)
{
  int v2; // r10d
  float *v3; // rdx
  float v4; // eax
  __int64 v5; // r8

  v2 = 0;
  v3 = (float *)(data + 16);
  if ( this->NumberOfGrains <= 0 )
  {
    this->WaveData = v3;
  }
  else
  {
    do
    {
      v4 = *v3;
      v5 = v2++;
      v3 += 4;
      *(float *)&this->pGrains[v5].OffsetIntoSample = v4;
      this->pGrains[v5].StartFrequency = *(v3 - 3);
      this->pGrains[v5].EndFrequency = *(v3 - 2);
      this->pGrains[v5].SizeOfGrain = *((_WORD *)v3 - 2);
      this->pGrains[v5].Index = *((_WORD *)v3 - 1);
    }
    while ( v2 < this->NumberOfGrains );
    this->WaveData = v3;
  }
}

// File Line: 67
// RVA: 0x15C2A0
__int64 __fastcall GrainFileHeader::GetGrainFileHeader(GrainFileHeader *this, char *data)
{
  *(_DWORD *)this->ID = *(_DWORD *)data;
  this->SampleRate = *((_DWORD *)data + 1);
  this->NumberOfGrains = *((_DWORD *)data + 2);
  this->NumberOfSamples = *((_DWORD *)data + 3);
  return 16i64;
}

