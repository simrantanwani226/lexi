# QuickMatch

A small Spring Boot service that scores how well a resume matches a job
description, exposed as a REST API. Resumes and job descriptions are persisted
with Spring Data JPA (H2 in-memory database), and a matching service computes an
overlap score between the two texts.

## Tech stack

- Java 11, Spring Boot 2.5.4
- Spring Web (REST), Spring Data JPA
- H2 in-memory database

## Architecture

```
controller/   ResumeController, JobDescriptionController   REST endpoints
service/      MatchService                                 match scoring
repository/   ResumeRepository, JobDescriptionRepository   Spring Data JPA
model/        Resume, JobDescription                       JPA entities
```

## How matching works

`MatchService` normalizes each text (lowercase, strip punctuation), reduces it to
a set of unique words, and returns the percentage of the job description's words
that also appear in the resume, capped at 100%. It is a simple keyword-overlap
score, not an ML model.

## Running

```bash
./mvnw spring-boot:run
# starts on http://localhost:8082
```

H2 console: `http://localhost:8082/h2-console` (JDBC URL `jdbc:h2:mem:testdb`, user `sa`).

## API

| Method | Path                          | Body                   | Returns                    |
|--------|-------------------------------|------------------------|----------------------------|
| `POST` | `/resumes`                    | `{ "content": "..." }` | created Resume (with `id`) |
| `POST` | `/jobs`                       | `{ "content": "..." }` | created JobDescription     |
| `GET`  | `/resumes/{id}/match/{jobId}` | —                      | match score `0`–`100`      |

### Example

```bash
# create a resume
curl -X POST http://localhost:8082/resumes \
  -H 'Content-Type: application/json' \
  -d '{"content":"java spring boot postgres rest api"}'

# create a job description
curl -X POST http://localhost:8082/jobs \
  -H 'Content-Type: application/json' \
  -d '{"content":"looking for a java spring developer with rest api experience"}'

# score resume 1 against job 1
curl http://localhost:8082/resumes/1/match/1
```

## Tests

```bash
./mvnw test
```
