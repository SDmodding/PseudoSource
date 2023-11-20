// File Line: 36
// RVA: 0x16D160
void __fastcall UFG::qCompressHeader::EndianSwap(UFG::qCompressHeader *this)
{
  UFG::qCompressHeader *v1; // r10
  UFG::qCompressHeader *v2; // r8
  UFG::qCompressHeader *i; // r9
  char v4; // al
  char v5; // dl
  unsigned __int16 *v6; // rdx
  unsigned __int16 *v7; // r8
  char v8; // al
  char v9; // cl
  unsigned __int16 *v10; // rdx
  unsigned __int16 *v11; // r8
  char v12; // al
  char v13; // cl
  unsigned int *v14; // rdx
  unsigned int *v15; // r8
  char v16; // al
  char v17; // cl
  unsigned int *v18; // rdx
  unsigned int *v19; // r8
  char v20; // al
  char v21; // cl
  __int64 *v22; // rdx
  __int64 *v23; // r8
  char v24; // al
  char v25; // cl
  __int64 *v26; // rdx
  __int64 *v27; // r8
  char v28; // al
  char v29; // cl
  __int64 *v30; // rdx
  __int64 *v31; // r8
  char v32; // al
  char v33; // cl
  unsigned int *v34; // rdx
  unsigned int *v35; // r8
  char v36; // al
  char v37; // cl
  unsigned int *v38; // rdx
  unsigned int *v39; // r8
  char v40; // al
  char v41; // cl
  unsigned int *v42; // rdx
  unsigned int *v43; // r8
  char v44; // al
  char v45; // cl
  unsigned int *v46; // rdx
  unsigned int *v47; // r8
  char v48; // al
  char v49; // cl
  unsigned int *v50; // rdx
  unsigned int *v51; // r8
  char v52; // al
  char v53; // cl
  unsigned int *v54; // rdx
  unsigned int *v55; // r8
  char v56; // al
  char v57; // cl

  v1 = this;
  if ( this->mID != 'QCMP' )
  {
    v2 = (UFG::qCompressHeader *)((char *)this + 3);
    for ( i = this; i < v2; i = (UFG::qCompressHeader *)((char *)i + 1) )
    {
      v4 = v2->mID;
      v5 = i->mID;
      v2 = (UFG::qCompressHeader *)((char *)v2 - 1);
      LOBYTE(i->mID) = v4;
      BYTE1(v2->mID) = v5;
    }
    v6 = &this->mType;
    v7 = (unsigned __int16 *)((char *)&this->mType + 1);
    if ( &this->mType < (unsigned __int16 *)((char *)&this->mType + 1) )
    {
      do
      {
        v8 = *(_BYTE *)v7;
        v9 = *(_BYTE *)v6;
        v7 = (unsigned __int16 *)((char *)v7 - 1);
        *(_BYTE *)v6 = v8;
        *((_BYTE *)v7 + 1) = v9;
        v6 = (unsigned __int16 *)((char *)v6 + 1);
      }
      while ( v6 < v7 );
    }
    v10 = &v1->mVersion;
    v11 = (unsigned __int16 *)((char *)&v1->mVersion + 1);
    if ( &v1->mVersion < (unsigned __int16 *)((char *)&v1->mVersion + 1) )
    {
      do
      {
        v12 = *(_BYTE *)v11;
        v13 = *(_BYTE *)v10;
        v11 = (unsigned __int16 *)((char *)v11 - 1);
        *(_BYTE *)v10 = v12;
        *((_BYTE *)v11 + 1) = v13;
        v10 = (unsigned __int16 *)((char *)v10 + 1);
      }
      while ( v10 < v11 );
    }
    v14 = &v1->mDataOffset;
    v15 = (unsigned int *)((char *)&v1->mDataOffset + 3);
    if ( &v1->mDataOffset < (unsigned int *)((char *)&v1->mDataOffset + 3) )
    {
      do
      {
        v16 = *(_BYTE *)v15;
        v17 = *(_BYTE *)v14;
        v15 = (unsigned int *)((char *)v15 - 1);
        *(_BYTE *)v14 = v16;
        *((_BYTE *)v15 + 1) = v17;
        v14 = (unsigned int *)((char *)v14 + 1);
      }
      while ( v14 < v15 );
    }
    v18 = &v1->mInPlaceExtraNumBytes;
    v19 = (unsigned int *)((char *)&v1->mInPlaceExtraNumBytes + 3);
    if ( &v1->mInPlaceExtraNumBytes < (unsigned int *)((char *)&v1->mInPlaceExtraNumBytes + 3) )
    {
      do
      {
        v20 = *(_BYTE *)v19;
        v21 = *(_BYTE *)v18;
        v19 = (unsigned int *)((char *)v19 - 1);
        *(_BYTE *)v18 = v20;
        *((_BYTE *)v19 + 1) = v21;
        v18 = (unsigned int *)((char *)v18 + 1);
      }
      while ( v18 < v19 );
    }
    v22 = &v1->mCompressedNumBytes;
    v23 = (__int64 *)((char *)&v1->mCompressedNumBytes + 7);
    if ( &v1->mCompressedNumBytes < (__int64 *)((char *)&v1->mCompressedNumBytes + 7) )
    {
      do
      {
        v24 = *(_BYTE *)v23;
        v25 = *(_BYTE *)v22;
        v23 = (__int64 *)((char *)v23 - 1);
        *(_BYTE *)v22 = v24;
        *((_BYTE *)v23 + 1) = v25;
        v22 = (__int64 *)((char *)v22 + 1);
      }
      while ( v22 < v23 );
    }
    v26 = &v1->mUncompressedNumBytes;
    v27 = (__int64 *)((char *)&v1->mUncompressedNumBytes + 7);
    if ( &v1->mUncompressedNumBytes < (__int64 *)((char *)&v1->mUncompressedNumBytes + 7) )
    {
      do
      {
        v28 = *(_BYTE *)v27;
        v29 = *(_BYTE *)v26;
        v27 = (__int64 *)((char *)v27 - 1);
        *(_BYTE *)v26 = v28;
        *((_BYTE *)v27 + 1) = v29;
        v26 = (__int64 *)((char *)v26 + 1);
      }
      while ( v26 < v27 );
    }
    v30 = &v1->mUncompressedChecksum;
    v31 = (__int64 *)((char *)&v1->mUncompressedChecksum + 7);
    if ( &v1->mUncompressedChecksum < (__int64 *)((char *)&v1->mUncompressedChecksum + 7) )
    {
      do
      {
        v32 = *(_BYTE *)v31;
        v33 = *(_BYTE *)v30;
        v31 = (__int64 *)((char *)v31 - 1);
        *(_BYTE *)v30 = v32;
        *((_BYTE *)v31 + 1) = v33;
        v30 = (__int64 *)((char *)v30 + 1);
      }
      while ( v30 < v31 );
    }
    v34 = &v1->pad0;
    v35 = (unsigned int *)((char *)&v1->pad0 + 3);
    if ( &v1->pad0 < (unsigned int *)((char *)&v1->pad0 + 3) )
    {
      do
      {
        v36 = *(_BYTE *)v35;
        v37 = *(_BYTE *)v34;
        v35 = (unsigned int *)((char *)v35 - 1);
        *(_BYTE *)v34 = v36;
        *((_BYTE *)v35 + 1) = v37;
        v34 = (unsigned int *)((char *)v34 + 1);
      }
      while ( v34 < v35 );
    }
    v38 = &v1->pad1;
    v39 = (unsigned int *)((char *)&v1->pad1 + 3);
    if ( &v1->pad1 < (unsigned int *)((char *)&v1->pad1 + 3) )
    {
      do
      {
        v40 = *(_BYTE *)v39;
        v41 = *(_BYTE *)v38;
        v39 = (unsigned int *)((char *)v39 - 1);
        *(_BYTE *)v38 = v40;
        *((_BYTE *)v39 + 1) = v41;
        v38 = (unsigned int *)((char *)v38 + 1);
      }
      while ( v38 < v39 );
    }
    v42 = &v1->pad2;
    v43 = (unsigned int *)((char *)&v1->pad2 + 3);
    if ( &v1->pad2 < (unsigned int *)((char *)&v1->pad2 + 3) )
    {
      do
      {
        v44 = *(_BYTE *)v43;
        v45 = *(_BYTE *)v42;
        v43 = (unsigned int *)((char *)v43 - 1);
        *(_BYTE *)v42 = v44;
        *((_BYTE *)v43 + 1) = v45;
        v42 = (unsigned int *)((char *)v42 + 1);
      }
      while ( v42 < v43 );
    }
    v46 = &v1->pad3;
    v47 = (unsigned int *)((char *)&v1->pad3 + 3);
    if ( &v1->pad3 < (unsigned int *)((char *)&v1->pad3 + 3) )
    {
      do
      {
        v48 = *(_BYTE *)v47;
        v49 = *(_BYTE *)v46;
        v47 = (unsigned int *)((char *)v47 - 1);
        *(_BYTE *)v46 = v48;
        *((_BYTE *)v47 + 1) = v49;
        v46 = (unsigned int *)((char *)v46 + 1);
      }
      while ( v46 < v47 );
    }
    v50 = &v1->pad4;
    v51 = (unsigned int *)((char *)&v1->pad4 + 3);
    if ( &v1->pad4 < (unsigned int *)((char *)&v1->pad4 + 3) )
    {
      do
      {
        v52 = *(_BYTE *)v51;
        v53 = *(_BYTE *)v50;
        v51 = (unsigned int *)((char *)v51 - 1);
        *(_BYTE *)v50 = v52;
        *((_BYTE *)v51 + 1) = v53;
        v50 = (unsigned int *)((char *)v50 + 1);
      }
      while ( v50 < v51 );
    }
    v54 = &v1->pad5;
    v55 = (unsigned int *)((char *)&v1->pad5 + 3);
    if ( &v1->pad5 < (unsigned int *)((char *)&v1->pad5 + 3) )
    {
      do
      {
        v56 = *(_BYTE *)v55;
        v57 = *(_BYTE *)v54;
        v55 = (unsigned int *)((char *)v55 - 1);
        *(_BYTE *)v54 = v56;
        *((_BYTE *)v55 + 1) = v57;
        v54 = (unsigned int *)((char *)v54 + 1);
      }
      while ( v54 < v55 );
    }
  }
}

