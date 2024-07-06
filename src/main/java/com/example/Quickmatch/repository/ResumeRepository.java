package com.example.Quickmatch.repository;

import com.example.Quickmatch.model.Resume;
import org.springframework.data.jpa.repository.JpaRepository;

public interface ResumeRepository extends JpaRepository<Resume, Long> {
}
