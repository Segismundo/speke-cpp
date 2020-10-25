// Copyright (C) 2019 by Jakub Wojciech

// This file is part of Lelo Remote Music Player.

// Lelo Remote Music Player is free software: you can redistribute it
// and/or modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation, either version 3 of
// the License, or (at your option) any later version.

// Lelo Remote Music Player is distributed in the hope that it will be
// useful, but WITHOUT ANY WARRANTY; without even the implied warranty
// of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
// General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with Lelo Remote Music Player. If not, see
// <https://www.gnu.org/licenses/>.

#ifndef LRM_CRYPTO_CONFIG_H_
#define LRM_CRYPTO_CONFIG_H_

#include <vector>

#include <openssl/evp.h>

namespace lrm::crypto {
static constexpr int LRM_RSA_KEY_BITS = 2048;
static const EVP_CIPHER* LRM_RSA_KEY_PEM_CIPHER = EVP_aes_192_gcm();
static const EVP_MD* LRM_RSA_KEY_SIGN_DIGEST = EVP_sha256();

static const EVP_CIPHER* LRM_SPEKE_CIPHER_TYPE = EVP_aes_192_gcm();
static const EVP_MD* LRM_SPEKE_HASHFUNC = EVP_sha3_512();

// 4096-bit safe prime
static const char LRM_SPEKE_SAFE_PRIME[] =
    "901461244723357275807455577213220180450928876216770160525104880396721411"
    "399362417574187351099730383355255131992590016150626076455591715641371153"
    "135715481920069845164820764407709936930300326555072375978472658125543469"
    "630960168074872114823980235825911707919241184433398900613894170520460226"
    "715066477263678892230671335091167207720777748392282271950211953604882319"
    "561518050662586926258259217419572940659402095933375477522778060053798033"
    "936163052432729603898717924942765741483258508843256156200133036751645569"
    "468900713483923145511991719067336460128485234855032568389646382513314247"
    "981467992391569489007558114354533587715754632785263240961356875003628867"
    "962078237351034961752495095382304468996166874570800098239682923529652347"
    "868243962473855521325829487060496746492253626756107704449039618757265403"
    "041694512080576284186589594221686120597097736048026527737402632214417615"
    "345458789251873315487616047147144211616002389334419326964076821977614142"
    "587160671105241200295343915380265147098370403413759581742558163443263749"
    "068006159231352606973922287783307071713392411850122423315913991125319238"
    "087692089003479907879627648100831788904561387557158509374985568416931133"
    "236113018802586784951379853118530388694146979344425384554341464672795704"
    "095945203";

using Bytes = std::vector<std::byte>;
}

#endif  // LRM_CRYPTO_CONFIG_H_
