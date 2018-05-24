#include <cassert>
#include "Stage.h"
#include "MerkleDamgardConstruction.h"

/*
SHA1_Hash MerkleDamgardConstruction::round(SHA1_Hash input, Word word_j ) {
    assert(mRoundCounter<=79 && mRoundCounter >= 0);

    SHA1_Hash output = mCurrentHash;

    if(mRoundCounter >= 0 && mRoundCounter < 20){
        output.A = Stage<1>::f(input.B, input.C, input.D);
        output.A += Stage<1>::constant;
    } else if(mRoundCounter >= 20 && mRoundCounter < 40){
        output.A = Stage<2>::f(input.B, input.C, input.D);
        output.A += Stage<2>::constant;
    } else if(mRoundCounter >= 40 && mRoundCounter < 60){
        output.A = Stage<3>::f(input.B, input.C, input.D);
        output.A += Stage<3>::constant;
    } else if(mRoundCounter >= 60 && mRoundCounter < 80){
        output.A = Stage<4>::f(input.B, input.C, input.D);
        output.A += Stage<4>::constant;
    }
    output.A += input.E;
    output.A += input.A.rotateLeft(5);
    output.A += word_j;
    output.B = input.A;
    output.C = input.B.rotateLeft(30);
    output.D = input.C;
    output.E = input.D;

    mRoundCounter++;

    return mCurrentHash = output;
}*/

MerkleDamgardConstruction& MerkleDamgardConstruction::nextRound() {

    SHA1_Hash nextHash;
    if(mRoundCounter >= 0 && mRoundCounter < 20){
        nextHash.A = Stage<1>::f(mCurrentHash.B, mCurrentHash.C, mCurrentHash.D);
        nextHash.A += Stage<1>::constant;
    } else if(mRoundCounter >= 20 && mRoundCounter < 40){
        nextHash.A = Stage<2>::f(mCurrentHash.B, mCurrentHash.C, mCurrentHash.D);
        nextHash.A += Stage<2>::constant;
    } else if(mRoundCounter >= 40 && mRoundCounter < 60){
        nextHash.A = Stage<3>::f(mCurrentHash.B, mCurrentHash.C, mCurrentHash.D);
        nextHash.A += Stage<3>::constant;
    } else if(mRoundCounter >= 60 && mRoundCounter < 80){
        nextHash.A = Stage<4>::f(mCurrentHash.B, mCurrentHash.C, mCurrentHash.D);
        nextHash.A += Stage<4>::constant;
    }
    nextHash.A += mCurrentHash.E;
    nextHash.A += mCurrentHash.A.rotateLeft(5);
    nextHash.A += mMessageSchedule[mRoundCounter];
    nextHash.B = mCurrentHash.A;
    nextHash.C = mCurrentHash.B.rotateLeft(30);
    nextHash.D = mCurrentHash.C;
    nextHash.E = mCurrentHash.D;

    mCurrentHash=nextHash;
    std::cout << "i = " << mRoundCounter
              << ": A=" << mCurrentHash.A
              << ", B=" << mCurrentHash.B
              << ", C=" << mCurrentHash.C
              << ", D=" << mCurrentHash.D
              << ", E=" << mCurrentHash.E
              << ", W_j=" << Stage<1>::constant
              << std::endl;
    mRoundCounter++;
    return *this;
}


MerkleDamgardConstruction::MerkleDamgardConstruction(const MessageBlock& messageBlock):
        mMessageSchedule{messageBlock}, mRoundCounter{0}, mCurrentHash{0x67452301,0xEFCDAB89,0x98BADCFE,0x10325476,0xC3D2E1F0} {
    for(int i = 0; i < 80; i++){
        MerkleDamgardConstruction::nextRound();
    }
    mCurrentHash.A += 0x67452301;
    mCurrentHash.B += 0xEFCDAB89;
    mCurrentHash.C += 0x98BADCFE;
    mCurrentHash.D += 0x10325476;
    mCurrentHash.E += 0xC3D2E1F0;
}

SHA1_Hash MerkleDamgardConstruction::sha1_hash() const {
    return mCurrentHash;
}

MerkleDamgardConstruction& MerkleDamgardConstruction::update(const MessageBlock &messageBlock) {
    assert(mRoundCounter==79);
    mRoundCounter = 0;
    mMessageSchedule = MessageSchedule{messageBlock};
    for(int i = 0; i < 80; i++){
        MerkleDamgardConstruction::nextRound();
    }
    mCurrentHash.A += 0x67452301;
    mCurrentHash.B += 0xEFCDAB89;
    mCurrentHash.C += 0x98BADCFE;
    mCurrentHash.D += 0x10325476;
    mCurrentHash.E += 0xC3D2E1F0;

    return *this;
}

