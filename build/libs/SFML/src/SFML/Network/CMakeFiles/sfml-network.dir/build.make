# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CMake.app/Contents/bin/cmake

# The command to remove a file.
RM = /Applications/CMake.app/Contents/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/madsrossen/Documents/VS_code/projects/greenhouse_simulator

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/madsrossen/Documents/VS_code/projects/greenhouse_simulator/build

# Include any dependencies generated for this target.
include libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/depend.make

# Include the progress variables for this target.
include libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/progress.make

# Include the compile flags for this target's objects.
include libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/flags.make

libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/Ftp.cpp.o: libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/flags.make
libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/Ftp.cpp.o: ../libs/SFML/src/SFML/Network/Ftp.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/madsrossen/Documents/VS_code/projects/greenhouse_simulator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/Ftp.cpp.o"
	cd /Users/madsrossen/Documents/VS_code/projects/greenhouse_simulator/build/libs/SFML/src/SFML/Network && /usr/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sfml-network.dir/Ftp.cpp.o -c /Users/madsrossen/Documents/VS_code/projects/greenhouse_simulator/libs/SFML/src/SFML/Network/Ftp.cpp

libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/Ftp.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sfml-network.dir/Ftp.cpp.i"
	cd /Users/madsrossen/Documents/VS_code/projects/greenhouse_simulator/build/libs/SFML/src/SFML/Network && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/madsrossen/Documents/VS_code/projects/greenhouse_simulator/libs/SFML/src/SFML/Network/Ftp.cpp > CMakeFiles/sfml-network.dir/Ftp.cpp.i

libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/Ftp.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sfml-network.dir/Ftp.cpp.s"
	cd /Users/madsrossen/Documents/VS_code/projects/greenhouse_simulator/build/libs/SFML/src/SFML/Network && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/madsrossen/Documents/VS_code/projects/greenhouse_simulator/libs/SFML/src/SFML/Network/Ftp.cpp -o CMakeFiles/sfml-network.dir/Ftp.cpp.s

libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/Http.cpp.o: libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/flags.make
libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/Http.cpp.o: ../libs/SFML/src/SFML/Network/Http.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/madsrossen/Documents/VS_code/projects/greenhouse_simulator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/Http.cpp.o"
	cd /Users/madsrossen/Documents/VS_code/projects/greenhouse_simulator/build/libs/SFML/src/SFML/Network && /usr/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sfml-network.dir/Http.cpp.o -c /Users/madsrossen/Documents/VS_code/projects/greenhouse_simulator/libs/SFML/src/SFML/Network/Http.cpp

libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/Http.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sfml-network.dir/Http.cpp.i"
	cd /Users/madsrossen/Documents/VS_code/projects/greenhouse_simulator/build/libs/SFML/src/SFML/Network && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/madsrossen/Documents/VS_code/projects/greenhouse_simulator/libs/SFML/src/SFML/Network/Http.cpp > CMakeFiles/sfml-network.dir/Http.cpp.i

libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/Http.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sfml-network.dir/Http.cpp.s"
	cd /Users/madsrossen/Documents/VS_code/projects/greenhouse_simulator/build/libs/SFML/src/SFML/Network && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/madsrossen/Documents/VS_code/projects/greenhouse_simulator/libs/SFML/src/SFML/Network/Http.cpp -o CMakeFiles/sfml-network.dir/Http.cpp.s

libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/IpAddress.cpp.o: libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/flags.make
libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/IpAddress.cpp.o: ../libs/SFML/src/SFML/Network/IpAddress.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/madsrossen/Documents/VS_code/projects/greenhouse_simulator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/IpAddress.cpp.o"
	cd /Users/madsrossen/Documents/VS_code/projects/greenhouse_simulator/build/libs/SFML/src/SFML/Network && /usr/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sfml-network.dir/IpAddress.cpp.o -c /Users/madsrossen/Documents/VS_code/projects/greenhouse_simulator/libs/SFML/src/SFML/Network/IpAddress.cpp

libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/IpAddress.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sfml-network.dir/IpAddress.cpp.i"
	cd /Users/madsrossen/Documents/VS_code/projects/greenhouse_simulator/build/libs/SFML/src/SFML/Network && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/madsrossen/Documents/VS_code/projects/greenhouse_simulator/libs/SFML/src/SFML/Network/IpAddress.cpp > CMakeFiles/sfml-network.dir/IpAddress.cpp.i

libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/IpAddress.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sfml-network.dir/IpAddress.cpp.s"
	cd /Users/madsrossen/Documents/VS_code/projects/greenhouse_simulator/build/libs/SFML/src/SFML/Network && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/madsrossen/Documents/VS_code/projects/greenhouse_simulator/libs/SFML/src/SFML/Network/IpAddress.cpp -o CMakeFiles/sfml-network.dir/IpAddress.cpp.s

libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/Packet.cpp.o: libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/flags.make
libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/Packet.cpp.o: ../libs/SFML/src/SFML/Network/Packet.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/madsrossen/Documents/VS_code/projects/greenhouse_simulator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/Packet.cpp.o"
	cd /Users/madsrossen/Documents/VS_code/projects/greenhouse_simulator/build/libs/SFML/src/SFML/Network && /usr/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sfml-network.dir/Packet.cpp.o -c /Users/madsrossen/Documents/VS_code/projects/greenhouse_simulator/libs/SFML/src/SFML/Network/Packet.cpp

libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/Packet.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sfml-network.dir/Packet.cpp.i"
	cd /Users/madsrossen/Documents/VS_code/projects/greenhouse_simulator/build/libs/SFML/src/SFML/Network && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/madsrossen/Documents/VS_code/projects/greenhouse_simulator/libs/SFML/src/SFML/Network/Packet.cpp > CMakeFiles/sfml-network.dir/Packet.cpp.i

libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/Packet.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sfml-network.dir/Packet.cpp.s"
	cd /Users/madsrossen/Documents/VS_code/projects/greenhouse_simulator/build/libs/SFML/src/SFML/Network && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/madsrossen/Documents/VS_code/projects/greenhouse_simulator/libs/SFML/src/SFML/Network/Packet.cpp -o CMakeFiles/sfml-network.dir/Packet.cpp.s

libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/Socket.cpp.o: libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/flags.make
libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/Socket.cpp.o: ../libs/SFML/src/SFML/Network/Socket.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/madsrossen/Documents/VS_code/projects/greenhouse_simulator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/Socket.cpp.o"
	cd /Users/madsrossen/Documents/VS_code/projects/greenhouse_simulator/build/libs/SFML/src/SFML/Network && /usr/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sfml-network.dir/Socket.cpp.o -c /Users/madsrossen/Documents/VS_code/projects/greenhouse_simulator/libs/SFML/src/SFML/Network/Socket.cpp

libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/Socket.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sfml-network.dir/Socket.cpp.i"
	cd /Users/madsrossen/Documents/VS_code/projects/greenhouse_simulator/build/libs/SFML/src/SFML/Network && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/madsrossen/Documents/VS_code/projects/greenhouse_simulator/libs/SFML/src/SFML/Network/Socket.cpp > CMakeFiles/sfml-network.dir/Socket.cpp.i

libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/Socket.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sfml-network.dir/Socket.cpp.s"
	cd /Users/madsrossen/Documents/VS_code/projects/greenhouse_simulator/build/libs/SFML/src/SFML/Network && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/madsrossen/Documents/VS_code/projects/greenhouse_simulator/libs/SFML/src/SFML/Network/Socket.cpp -o CMakeFiles/sfml-network.dir/Socket.cpp.s

libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/SocketSelector.cpp.o: libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/flags.make
libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/SocketSelector.cpp.o: ../libs/SFML/src/SFML/Network/SocketSelector.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/madsrossen/Documents/VS_code/projects/greenhouse_simulator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/SocketSelector.cpp.o"
	cd /Users/madsrossen/Documents/VS_code/projects/greenhouse_simulator/build/libs/SFML/src/SFML/Network && /usr/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sfml-network.dir/SocketSelector.cpp.o -c /Users/madsrossen/Documents/VS_code/projects/greenhouse_simulator/libs/SFML/src/SFML/Network/SocketSelector.cpp

libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/SocketSelector.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sfml-network.dir/SocketSelector.cpp.i"
	cd /Users/madsrossen/Documents/VS_code/projects/greenhouse_simulator/build/libs/SFML/src/SFML/Network && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/madsrossen/Documents/VS_code/projects/greenhouse_simulator/libs/SFML/src/SFML/Network/SocketSelector.cpp > CMakeFiles/sfml-network.dir/SocketSelector.cpp.i

libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/SocketSelector.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sfml-network.dir/SocketSelector.cpp.s"
	cd /Users/madsrossen/Documents/VS_code/projects/greenhouse_simulator/build/libs/SFML/src/SFML/Network && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/madsrossen/Documents/VS_code/projects/greenhouse_simulator/libs/SFML/src/SFML/Network/SocketSelector.cpp -o CMakeFiles/sfml-network.dir/SocketSelector.cpp.s

libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/TcpListener.cpp.o: libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/flags.make
libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/TcpListener.cpp.o: ../libs/SFML/src/SFML/Network/TcpListener.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/madsrossen/Documents/VS_code/projects/greenhouse_simulator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/TcpListener.cpp.o"
	cd /Users/madsrossen/Documents/VS_code/projects/greenhouse_simulator/build/libs/SFML/src/SFML/Network && /usr/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sfml-network.dir/TcpListener.cpp.o -c /Users/madsrossen/Documents/VS_code/projects/greenhouse_simulator/libs/SFML/src/SFML/Network/TcpListener.cpp

libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/TcpListener.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sfml-network.dir/TcpListener.cpp.i"
	cd /Users/madsrossen/Documents/VS_code/projects/greenhouse_simulator/build/libs/SFML/src/SFML/Network && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/madsrossen/Documents/VS_code/projects/greenhouse_simulator/libs/SFML/src/SFML/Network/TcpListener.cpp > CMakeFiles/sfml-network.dir/TcpListener.cpp.i

libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/TcpListener.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sfml-network.dir/TcpListener.cpp.s"
	cd /Users/madsrossen/Documents/VS_code/projects/greenhouse_simulator/build/libs/SFML/src/SFML/Network && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/madsrossen/Documents/VS_code/projects/greenhouse_simulator/libs/SFML/src/SFML/Network/TcpListener.cpp -o CMakeFiles/sfml-network.dir/TcpListener.cpp.s

libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/TcpSocket.cpp.o: libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/flags.make
libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/TcpSocket.cpp.o: ../libs/SFML/src/SFML/Network/TcpSocket.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/madsrossen/Documents/VS_code/projects/greenhouse_simulator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/TcpSocket.cpp.o"
	cd /Users/madsrossen/Documents/VS_code/projects/greenhouse_simulator/build/libs/SFML/src/SFML/Network && /usr/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sfml-network.dir/TcpSocket.cpp.o -c /Users/madsrossen/Documents/VS_code/projects/greenhouse_simulator/libs/SFML/src/SFML/Network/TcpSocket.cpp

libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/TcpSocket.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sfml-network.dir/TcpSocket.cpp.i"
	cd /Users/madsrossen/Documents/VS_code/projects/greenhouse_simulator/build/libs/SFML/src/SFML/Network && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/madsrossen/Documents/VS_code/projects/greenhouse_simulator/libs/SFML/src/SFML/Network/TcpSocket.cpp > CMakeFiles/sfml-network.dir/TcpSocket.cpp.i

libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/TcpSocket.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sfml-network.dir/TcpSocket.cpp.s"
	cd /Users/madsrossen/Documents/VS_code/projects/greenhouse_simulator/build/libs/SFML/src/SFML/Network && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/madsrossen/Documents/VS_code/projects/greenhouse_simulator/libs/SFML/src/SFML/Network/TcpSocket.cpp -o CMakeFiles/sfml-network.dir/TcpSocket.cpp.s

libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/UdpSocket.cpp.o: libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/flags.make
libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/UdpSocket.cpp.o: ../libs/SFML/src/SFML/Network/UdpSocket.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/madsrossen/Documents/VS_code/projects/greenhouse_simulator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/UdpSocket.cpp.o"
	cd /Users/madsrossen/Documents/VS_code/projects/greenhouse_simulator/build/libs/SFML/src/SFML/Network && /usr/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sfml-network.dir/UdpSocket.cpp.o -c /Users/madsrossen/Documents/VS_code/projects/greenhouse_simulator/libs/SFML/src/SFML/Network/UdpSocket.cpp

libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/UdpSocket.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sfml-network.dir/UdpSocket.cpp.i"
	cd /Users/madsrossen/Documents/VS_code/projects/greenhouse_simulator/build/libs/SFML/src/SFML/Network && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/madsrossen/Documents/VS_code/projects/greenhouse_simulator/libs/SFML/src/SFML/Network/UdpSocket.cpp > CMakeFiles/sfml-network.dir/UdpSocket.cpp.i

libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/UdpSocket.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sfml-network.dir/UdpSocket.cpp.s"
	cd /Users/madsrossen/Documents/VS_code/projects/greenhouse_simulator/build/libs/SFML/src/SFML/Network && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/madsrossen/Documents/VS_code/projects/greenhouse_simulator/libs/SFML/src/SFML/Network/UdpSocket.cpp -o CMakeFiles/sfml-network.dir/UdpSocket.cpp.s

libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/Unix/SocketImpl.cpp.o: libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/flags.make
libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/Unix/SocketImpl.cpp.o: ../libs/SFML/src/SFML/Network/Unix/SocketImpl.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/madsrossen/Documents/VS_code/projects/greenhouse_simulator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/Unix/SocketImpl.cpp.o"
	cd /Users/madsrossen/Documents/VS_code/projects/greenhouse_simulator/build/libs/SFML/src/SFML/Network && /usr/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sfml-network.dir/Unix/SocketImpl.cpp.o -c /Users/madsrossen/Documents/VS_code/projects/greenhouse_simulator/libs/SFML/src/SFML/Network/Unix/SocketImpl.cpp

libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/Unix/SocketImpl.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sfml-network.dir/Unix/SocketImpl.cpp.i"
	cd /Users/madsrossen/Documents/VS_code/projects/greenhouse_simulator/build/libs/SFML/src/SFML/Network && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/madsrossen/Documents/VS_code/projects/greenhouse_simulator/libs/SFML/src/SFML/Network/Unix/SocketImpl.cpp > CMakeFiles/sfml-network.dir/Unix/SocketImpl.cpp.i

libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/Unix/SocketImpl.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sfml-network.dir/Unix/SocketImpl.cpp.s"
	cd /Users/madsrossen/Documents/VS_code/projects/greenhouse_simulator/build/libs/SFML/src/SFML/Network && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/madsrossen/Documents/VS_code/projects/greenhouse_simulator/libs/SFML/src/SFML/Network/Unix/SocketImpl.cpp -o CMakeFiles/sfml-network.dir/Unix/SocketImpl.cpp.s

# Object files for target sfml-network
sfml__network_OBJECTS = \
"CMakeFiles/sfml-network.dir/Ftp.cpp.o" \
"CMakeFiles/sfml-network.dir/Http.cpp.o" \
"CMakeFiles/sfml-network.dir/IpAddress.cpp.o" \
"CMakeFiles/sfml-network.dir/Packet.cpp.o" \
"CMakeFiles/sfml-network.dir/Socket.cpp.o" \
"CMakeFiles/sfml-network.dir/SocketSelector.cpp.o" \
"CMakeFiles/sfml-network.dir/TcpListener.cpp.o" \
"CMakeFiles/sfml-network.dir/TcpSocket.cpp.o" \
"CMakeFiles/sfml-network.dir/UdpSocket.cpp.o" \
"CMakeFiles/sfml-network.dir/Unix/SocketImpl.cpp.o"

# External object files for target sfml-network
sfml__network_EXTERNAL_OBJECTS =

libs/SFML/lib/libsfml-network-d.2.5.1.dylib: libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/Ftp.cpp.o
libs/SFML/lib/libsfml-network-d.2.5.1.dylib: libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/Http.cpp.o
libs/SFML/lib/libsfml-network-d.2.5.1.dylib: libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/IpAddress.cpp.o
libs/SFML/lib/libsfml-network-d.2.5.1.dylib: libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/Packet.cpp.o
libs/SFML/lib/libsfml-network-d.2.5.1.dylib: libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/Socket.cpp.o
libs/SFML/lib/libsfml-network-d.2.5.1.dylib: libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/SocketSelector.cpp.o
libs/SFML/lib/libsfml-network-d.2.5.1.dylib: libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/TcpListener.cpp.o
libs/SFML/lib/libsfml-network-d.2.5.1.dylib: libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/TcpSocket.cpp.o
libs/SFML/lib/libsfml-network-d.2.5.1.dylib: libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/UdpSocket.cpp.o
libs/SFML/lib/libsfml-network-d.2.5.1.dylib: libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/Unix/SocketImpl.cpp.o
libs/SFML/lib/libsfml-network-d.2.5.1.dylib: libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/build.make
libs/SFML/lib/libsfml-network-d.2.5.1.dylib: libs/SFML/lib/libsfml-system-d.2.5.1.dylib
libs/SFML/lib/libsfml-network-d.2.5.1.dylib: libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/madsrossen/Documents/VS_code/projects/greenhouse_simulator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Linking CXX shared library ../../../lib/libsfml-network-d.dylib"
	cd /Users/madsrossen/Documents/VS_code/projects/greenhouse_simulator/build/libs/SFML/src/SFML/Network && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sfml-network.dir/link.txt --verbose=$(VERBOSE)
	cd /Users/madsrossen/Documents/VS_code/projects/greenhouse_simulator/build/libs/SFML/src/SFML/Network && $(CMAKE_COMMAND) -E cmake_symlink_library ../../../lib/libsfml-network-d.2.5.1.dylib ../../../lib/libsfml-network-d.2.5.dylib ../../../lib/libsfml-network-d.dylib

libs/SFML/lib/libsfml-network-d.2.5.dylib: libs/SFML/lib/libsfml-network-d.2.5.1.dylib
	@$(CMAKE_COMMAND) -E touch_nocreate libs/SFML/lib/libsfml-network-d.2.5.dylib

libs/SFML/lib/libsfml-network-d.dylib: libs/SFML/lib/libsfml-network-d.2.5.1.dylib
	@$(CMAKE_COMMAND) -E touch_nocreate libs/SFML/lib/libsfml-network-d.dylib

# Rule to build all files generated by this target.
libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/build: libs/SFML/lib/libsfml-network-d.dylib

.PHONY : libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/build

libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/clean:
	cd /Users/madsrossen/Documents/VS_code/projects/greenhouse_simulator/build/libs/SFML/src/SFML/Network && $(CMAKE_COMMAND) -P CMakeFiles/sfml-network.dir/cmake_clean.cmake
.PHONY : libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/clean

libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/depend:
	cd /Users/madsrossen/Documents/VS_code/projects/greenhouse_simulator/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/madsrossen/Documents/VS_code/projects/greenhouse_simulator /Users/madsrossen/Documents/VS_code/projects/greenhouse_simulator/libs/SFML/src/SFML/Network /Users/madsrossen/Documents/VS_code/projects/greenhouse_simulator/build /Users/madsrossen/Documents/VS_code/projects/greenhouse_simulator/build/libs/SFML/src/SFML/Network /Users/madsrossen/Documents/VS_code/projects/greenhouse_simulator/build/libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/depend

