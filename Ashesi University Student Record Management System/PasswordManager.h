#pragma once

namespace AshesiUniversityStudentRecordManagementSystem {
    using namespace System::Security::Cryptography;
    using namespace System::Text;

    public ref class PasswordManager
    {
    public  :
        static System::String^ HashPassword(String^ password) {
			// Convert password to byte array
			array<Byte>^ bytes = System::Text::Encoding::UTF8->GetBytes(password);

			// Create SHA256 instance
			SHA256^ sha256 = SHA256::Create();

			// Compute the hash
			array<Byte>^ hashBytes = sha256->ComputeHash(bytes);

			// Convert the hash bytes to a hexadecimal string
			StringBuilder^ sb = gcnew StringBuilder();
			for (int i = 0; i < hashBytes->Length; i++)
			{
				sb->Append(hashBytes[i].ToString("x2"));  // Format bytes as hex
			}
			return sb->ToString();
        }
    };
};