// File Line: 36
// RVA: 0x16D160
void __fastcall UFG::qCompressHeader::EndianSwap(UFG::qCompressHeader *this)
{
  UFG::qCompressHeader *v2; // r8
  UFG::qCompressHeader *i; // r9
  char mID; // al
  char v5; // dl
  unsigned __int16 *p_mType; // rdx
  unsigned __int16 *j; // r8
  char v8; // al
  char v9; // cl
  unsigned __int16 *p_mVersion; // rdx
  unsigned __int16 *k; // r8
  char v12; // al
  char v13; // cl
  unsigned int *p_mDataOffset; // rdx
  unsigned int *m; // r8
  char v16; // al
  char v17; // cl
  unsigned int *p_mInPlaceExtraNumBytes; // rdx
  unsigned int *n; // r8
  char v20; // al
  char v21; // cl
  __int64 *p_mCompressedNumBytes; // rdx
  __int64 *ii; // r8
  char v24; // al
  char v25; // cl
  __int64 *p_mUncompressedNumBytes; // rdx
  __int64 *jj; // r8
  char v28; // al
  char v29; // cl
  __int64 *p_mUncompressedChecksum; // rdx
  __int64 *kk; // r8
  char v32; // al
  char v33; // cl
  unsigned int *p_pad0; // rdx
  unsigned int *mm; // r8
  char v36; // al
  char v37; // cl
  unsigned int *p_pad1; // rdx
  unsigned int *nn; // r8
  char v40; // al
  char v41; // cl
  unsigned int *p_pad2; // rdx
  unsigned int *i1; // r8
  char v44; // al
  char v45; // cl
  unsigned int *p_pad3; // rdx
  unsigned int *i2; // r8
  char v48; // al
  char v49; // cl
  unsigned int *p_pad4; // rdx
  unsigned int *i3; // r8
  char v52; // al
  char v53; // cl
  unsigned int *p_pad5; // rdx
  unsigned int *i4; // r8
  char v56; // al
  char v57; // cl

  if ( this->mID != QCMP )
  {
    v2 = (UFG::qCompressHeader *)((char *)&this->mID + 3);
    for ( i = this; i < v2; i = (UFG::qCompressHeader *)((char *)i + 1) )
    {
      mID = v2->mID;
      v5 = i->mID;
      v2 = (UFG::qCompressHeader *)((char *)v2 - 1);
      LOBYTE(i->mID) = mID;
      BYTE1(v2->mID) = v5;
    }
    p_mType = &this->mType;
    for ( j = (unsigned __int16 *)((char *)&this->mType + 1);
          p_mType < j;
          p_mType = (unsigned __int16 *)((char *)p_mType + 1) )
    {
      v8 = *(_BYTE *)j;
      v9 = *(_BYTE *)p_mType;
      j = (unsigned __int16 *)((char *)j - 1);
      *(_BYTE *)p_mType = v8;
      *((_BYTE *)j + 1) = v9;
    }
    p_mVersion = &this->mVersion;
    for ( k = (unsigned __int16 *)((char *)&this->mVersion + 1);
          p_mVersion < k;
          p_mVersion = (unsigned __int16 *)((char *)p_mVersion + 1) )
    {
      v12 = *(_BYTE *)k;
      v13 = *(_BYTE *)p_mVersion;
      k = (unsigned __int16 *)((char *)k - 1);
      *(_BYTE *)p_mVersion = v12;
      *((_BYTE *)k + 1) = v13;
    }
    p_mDataOffset = &this->mDataOffset;
    for ( m = (unsigned int *)((char *)&this->mDataOffset + 3);
          p_mDataOffset < m;
          p_mDataOffset = (unsigned int *)((char *)p_mDataOffset + 1) )
    {
      v16 = *(_BYTE *)m;
      v17 = *(_BYTE *)p_mDataOffset;
      m = (unsigned int *)((char *)m - 1);
      *(_BYTE *)p_mDataOffset = v16;
      *((_BYTE *)m + 1) = v17;
    }
    p_mInPlaceExtraNumBytes = &this->mInPlaceExtraNumBytes;
    for ( n = (unsigned int *)((char *)&this->mInPlaceExtraNumBytes + 3);
          p_mInPlaceExtraNumBytes < n;
          p_mInPlaceExtraNumBytes = (unsigned int *)((char *)p_mInPlaceExtraNumBytes + 1) )
    {
      v20 = *(_BYTE *)n;
      v21 = *(_BYTE *)p_mInPlaceExtraNumBytes;
      n = (unsigned int *)((char *)n - 1);
      *(_BYTE *)p_mInPlaceExtraNumBytes = v20;
      *((_BYTE *)n + 1) = v21;
    }
    p_mCompressedNumBytes = &this->mCompressedNumBytes;
    for ( ii = (__int64 *)((char *)&this->mCompressedNumBytes + 7);
          p_mCompressedNumBytes < ii;
          p_mCompressedNumBytes = (__int64 *)((char *)p_mCompressedNumBytes + 1) )
    {
      v24 = *(_BYTE *)ii;
      v25 = *(_BYTE *)p_mCompressedNumBytes;
      ii = (__int64 *)((char *)ii - 1);
      *(_BYTE *)p_mCompressedNumBytes = v24;
      *((_BYTE *)ii + 1) = v25;
    }
    p_mUncompressedNumBytes = &this->mUncompressedNumBytes;
    for ( jj = (__int64 *)((char *)&this->mUncompressedNumBytes + 7);
          p_mUncompressedNumBytes < jj;
          p_mUncompressedNumBytes = (__int64 *)((char *)p_mUncompressedNumBytes + 1) )
    {
      v28 = *(_BYTE *)jj;
      v29 = *(_BYTE *)p_mUncompressedNumBytes;
      jj = (__int64 *)((char *)jj - 1);
      *(_BYTE *)p_mUncompressedNumBytes = v28;
      *((_BYTE *)jj + 1) = v29;
    }
    p_mUncompressedChecksum = &this->mUncompressedChecksum;
    for ( kk = (__int64 *)((char *)&this->mUncompressedChecksum + 7);
          p_mUncompressedChecksum < kk;
          p_mUncompressedChecksum = (__int64 *)((char *)p_mUncompressedChecksum + 1) )
    {
      v32 = *(_BYTE *)kk;
      v33 = *(_BYTE *)p_mUncompressedChecksum;
      kk = (__int64 *)((char *)kk - 1);
      *(_BYTE *)p_mUncompressedChecksum = v32;
      *((_BYTE *)kk + 1) = v33;
    }
    p_pad0 = &this->pad0;
    for ( mm = (unsigned int *)((char *)&this->pad0 + 3); p_pad0 < mm; p_pad0 = (unsigned int *)((char *)p_pad0 + 1) )
    {
      v36 = *(_BYTE *)mm;
      v37 = *(_BYTE *)p_pad0;
      mm = (unsigned int *)((char *)mm - 1);
      *(_BYTE *)p_pad0 = v36;
      *((_BYTE *)mm + 1) = v37;
    }
    p_pad1 = &this->pad1;
    for ( nn = (unsigned int *)((char *)&this->pad1 + 3); p_pad1 < nn; p_pad1 = (unsigned int *)((char *)p_pad1 + 1) )
    {
      v40 = *(_BYTE *)nn;
      v41 = *(_BYTE *)p_pad1;
      nn = (unsigned int *)((char *)nn - 1);
      *(_BYTE *)p_pad1 = v40;
      *((_BYTE *)nn + 1) = v41;
    }
    p_pad2 = &this->pad2;
    for ( i1 = (unsigned int *)((char *)&this->pad2 + 3); p_pad2 < i1; p_pad2 = (unsigned int *)((char *)p_pad2 + 1) )
    {
      v44 = *(_BYTE *)i1;
      v45 = *(_BYTE *)p_pad2;
      i1 = (unsigned int *)((char *)i1 - 1);
      *(_BYTE *)p_pad2 = v44;
      *((_BYTE *)i1 + 1) = v45;
    }
    p_pad3 = &this->pad3;
    for ( i2 = (unsigned int *)((char *)&this->pad3 + 3); p_pad3 < i2; p_pad3 = (unsigned int *)((char *)p_pad3 + 1) )
    {
      v48 = *(_BYTE *)i2;
      v49 = *(_BYTE *)p_pad3;
      i2 = (unsigned int *)((char *)i2 - 1);
      *(_BYTE *)p_pad3 = v48;
      *((_BYTE *)i2 + 1) = v49;
    }
    p_pad4 = &this->pad4;
    for ( i3 = (unsigned int *)((char *)&this->pad4 + 3); p_pad4 < i3; p_pad4 = (unsigned int *)((char *)p_pad4 + 1) )
    {
      v52 = *(_BYTE *)i3;
      v53 = *(_BYTE *)p_pad4;
      i3 = (unsigned int *)((char *)i3 - 1);
      *(_BYTE *)p_pad4 = v52;
      *((_BYTE *)i3 + 1) = v53;
    }
    p_pad5 = &this->pad5;
    for ( i4 = (unsigned int *)((char *)&this->pad5 + 3); p_pad5 < i4; p_pad5 = (unsigned int *)((char *)p_pad5 + 1) )
    {
      v56 = *(_BYTE *)i4;
      v57 = *(_BYTE *)p_pad5;
      i4 = (unsigned int *)((char *)i4 - 1);
      *(_BYTE *)p_pad5 = v56;
      *((_BYTE *)i4 + 1) = v57;
    }
  }
}

