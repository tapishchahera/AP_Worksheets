const express = require("express");
const mongoose = require("mongoose");
const bcrypt = require("bcrypt");
const cors = require("cors");

// Create an Express app
const app = express();

// Update the MongoDB connection string to connect to MongoDB Compass
const MONGO_URI = "mongodb+srv://ansh12jais:D8B6E034@mydbonline.lps87.mongodb.net/?retryWrites=true&w=majority&appName=MyDBOnline"; // Update this line with your MongoDB Compass connection string

// Middleware
app.use(express.json());
app.use(cors());

// MongoDB connection
mongoose
  .connect(MONGO_URI)
  .then(() => console.log("Connected to MongoDB Atlas"))
  .catch((err) => console.error("MongoDB connection error:", err));

// Mongoose User schema
const userSchema = new mongoose.Schema({
  name: { type: String, required: true },
  email: { type: String, required: true, unique: true },
  password: { type: String, required: true },
});

// Hash password before saving
userSchema.pre("save", async function (next) {
  if (!this.isModified("password")) return next();
  const salt = await bcrypt.genSalt(10);
  this.password = await bcrypt.hash(this.password, salt);
  next();
});

// User model
const User = mongoose.model("User", userSchema);

// signup route ******************************************************
app.post("/signup", async (req, res) => {
  const { name, email, password } = req.body;

  // Validate input
  if (!name || !email || !password) {
    return res.status(400).json({ error: "All fields are required" });
  }
  try {
    // Check if user already exists
    const existingUser = await User.findOne({ email });
    if (existingUser) {
      return res.status(400).json({ error: "User already exists" });
    }

    // Create and save new user
    const newUser = new User({ name, email, password });
    await newUser.save();

    res.status(201).json({ message: "User registered successfully" });
  } catch (err) {
    console.error("Error during signup:", err);
    res.status(500).json({ error: "Server error" });
  }
});

// login route *********************************************************
app.post("/login", async (req, res) => {
  const { email, password } = req.body;

  if (!email || !password)
    return res.status(400).json({ error: "Email and password are required" });

  try {
    const user = await User.findOne({ email });
    const isMatch = user && (await bcrypt.compare(password, user.password));

    if (!isMatch)
      return res.status(400).json({ error: "Invalid email or password" });

    res.status(200).json({ message: "Login successful" });
  } catch (error) {
    res.status(500).json({ error: "Server error" });
  }
});

// Start the server
const PORT = 5000;
app.listen(PORT, () => console.log(`Server running on port ${PORT}`));

// Instructions for MongoDB Compass:
// 1. Open MongoDB Compass.
// 2. Click on "Connect" and enter the connection string.
// 3. Replace <username>, <password>, <host>, <port>, and <database> with your MongoDB details.
// 4. Click "Connect" to establish the connection.
